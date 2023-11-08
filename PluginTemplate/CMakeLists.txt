# 3.12.0 is required for CXX_STANDARD 20
cmake_minimum_required(VERSION 3.12.0)

project(CCMplugin)

set(CCM_PLUGIN_SOURCES 
    "src/CCMplugin.cpp"
    
    # Please specify any additional source files here:
    "src/main.cpp"
)

# Locate CCM Library
find_package(CCM 1.0 REQUIRED)
find_package(ICU 73.2 COMPONENTS uc i18n REQUIRED)

# Plugin information.
# Please configure these variables using cmake cache
set(CCM_PLUGIN_NAME "Plugin Template" CACHE STRING "The display name of the plugin.")
set(CCM_PLUGIN_DESCRIPTION "An example plugin for the CCM library." CACHE STRING "The description of the plugin.")
set(CCM_PLUGIN_VERSION "1;0;0" CACHE STRING "The version of the plugin. (Major;Minor;Build)")
set(CCM_PLUGIN_VENDOR "Some Vendor" CACHE STRING "The vendor (author/publisher) of the plugin.")
set(CCM_PLUGIN_TYPE "CCM_EDITOR_AND_RUNTIME" CACHE STRING "The kind of plugin being compiled.")
set_property(CACHE CCM_PLUGIN_TYPE PROPERTY STRINGS "CCM_EDITOR_AND_RUNTIME;CCM_EDITOR_ONLY;CCM_RUNTIME_ONLY")

string(MAKE_C_IDENTIFIER ${CCM_PLUGIN_NAME} CCM_PLUGIN_CODE_NAME)

string(
    UUID CCM_PLUGIN_UUID
    NAMESPACE 3b301bfd-67e1-4c47-8bfa-cc0261dc311f 
    NAME ${CCM_PLUGIN_CODE_NAME}
    TYPE SHA1 UPPER
)

list(GET CCM_PLUGIN_VERSION 0 CCM_PLUGIN_VERSION_MAJOR)
list(GET CCM_PLUGIN_VERSION 1 CCM_PLUGIN_VERSION_MINOR)
list(GET CCM_PLUGIN_VERSION 2 CCM_PLUGIN_VERSION_BUILD)

add_compile_definitions(
    CCM_PLUGIN_CODE_NAME=${CCM_PLUGIN_CODE_NAME}
    CCM_PLUGIN_NAME=${CCM_PLUGIN_NAME} 
    CCM_PLUGIN_DESCRIPTION=${CCM_PLUGIN_DESCRIPTION} 
    CCM_PLUGIN_VENDOR=${CCM_PLUGIN_VENDOR}
    CCM_PLUGIN_VERSION_MAJOR=${CCM_PLUGIN_VERSION_MAJOR}
    CCM_PLUGIN_VERSION_MINOR=${CCM_PLUGIN_VERSION_MINOR}
    CCM_PLUGIN_VERSION_BUILD=${CCM_PLUGIN_VERSION_BUILD}
    CCM_PLUGIN_TYPE=${CCM_PLUGIN_TYPE}
    CCM_PLUGIN_UUID=${CCM_PLUGIN_UUID}
)

# Print plugin name
message("CCM Plugin: ${CCM_PLUGIN_NAME} (UUID: ${CCM_PLUGIN_UUID}) v${CCM_PLUGIN_VERSION_MAJOR}.${CCM_PLUGIN_VERSION_MINOR}.${CCM_PLUGIN_VERSION_BUILD}")

get_target_property(CCM_INCLUDE_DIRS CCM::CCM_shared INTERFACE_INCLUDE_DIRECTORIES)
message(STATUS "CCM_INCLUDE_DIRS: ${CCM_INCLUDE_DIRS}")

# Add library target
add_library(${CCM_PLUGIN_CODE_NAME} SHARED ${CCM_PLUGIN_SOURCES})

# Link against libCCM
target_link_libraries(${CCM_PLUGIN_CODE_NAME} PUBLIC CCM::CCM_shared)

# Specify include directory
target_include_directories(${CCM_PLUGIN_CODE_NAME} PUBLIC "include" ${CCM_INCLUDE_DIRS})

