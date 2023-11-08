
set(CCM_sources 
    "src/CCM.cpp" 
    "src/version.cpp"
    "src/uuid.cpp"
    "src/plugin/plugin.cpp"
    "src/plugin/context.cpp"
    "src/shapes/shape.cpp")

# Create cache variables for compiling the static and shared libraries.
set(CCM_COMPILE_STATIC_LIB TRUE CACHE BOOL "Compile a static version of the CCM library. (libCCM.a / CCM.lib)")
set(CCM_COMPILE_SHARED_LIB TRUE CACHE BOOL "Compile a shared version of the CCM library. (libCCM.so / CCM.dll / CCM.dylib)")

# ICU is required for UTF-8 support.
find_package(ICU 73.2 COMPONENTS uc i18n REQUIRED)

# Add preprocessor macros for version.
add_compile_definitions(CCM_VMAJOR=${CCM_VERSION_MAJOR} CCM_VMINOR=${CCM_VERSION_MINOR} CCM_VBUILD=${CCM_VERSION_BUILD})

# Installs the include folder for devs.
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

if(CCM_COMPILE_STATIC_LIB)

    # Create CCM Static Library 
    add_library(CCM_static STATIC ${CCM_sources})
    add_library(CCM::CCM_static ALIAS CCM_static)

    # Define the include directory.
    target_include_directories(CCM_static PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
    )

    # Link against ICU
    target_link_libraries(CCM_static PUBLIC ICU::uc ICU::i18n)

    # Set the CXX_STANDARD to 20.
    set_property(TARGET CCM_static PROPERTY CXX_STANDARD 20) 

    # Set the output name to CCM.
    set_property(TARGET CCM_static PROPERTY OUTPUT_NAME "CCM")

    # Set the version of the API.
    set_property(TARGET CCM_static PROPERTY VERSION ${CCM_VERSION})

    # Create install rules.
    install(
        TARGETS CCM_static
        EXPORT CCMTargets
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        )

endif()

if(CCM_COMPILE_SHARED_LIB)

    # Create CCM Static Library 
    add_library(CCM_shared SHARED ${CCM_sources})
    add_library(CCM::CCM_shared ALIAS CCM_shared)

    # Define the include directory.
    target_include_directories(CCM_shared PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
    )

    # Link against ICU
    target_link_libraries(CCM_shared PUBLIC ICU::uc ICU::i18n)

    # Set the CXX_STANDARD to 20.
    set_property(TARGET CCM_shared PROPERTY CXX_STANDARD 20) 

    # Set the output name to CCM.
    set_property(TARGET CCM_shared PROPERTY OUTPUT_NAME "CCM")

    # Set the version of the API.
    set_property(TARGET CCM_shared PROPERTY VERSION ${CCM_VERSION})

    # Create install rules.
    install(
        TARGETS CCM_shared
        EXPORT CCMTargets
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        )

endif()