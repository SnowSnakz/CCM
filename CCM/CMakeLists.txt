
set(CCM_sources "src/CCM.cpp")

# Create cache variables for compiling the static and shared libraries.
set(CCM_COMPILE_STATIC_LIB TRUE CACHE BOOL "Compile a static version of the CCM library. (libCCM.a / CCM.lib)")
set(CCM_COMPILE_SHARED_LIB TRUE CACHE BOOL "Compile a shared version of the CCM library. (libCCM.so / CCM.dll / CCM.dylib)")

# ICU is required for UTF-8 support.
find_package(ICU 73.2 COMPONENTS uc i18n REQUIRED)

if(CCM_COMPILE_STATIC_LIB)

    # Create CCM Static Library 
    add_library(CCM_static STATIC ${CCM_sources})

    # Define the include directory.
    target_include_directories(CCM_static PUBLIC "include")

    # Link against ICU
    target_link_libraries(CCM_static PUBLIC ICU::uc ICU::i18n)

    # Set the CXX_STANDARD to 20.
    set_property(TARGET CCM_static PROPERTY CXX_STANDARD 20) 

    # Set the output name to CCM.
    set_property(TARGET CCM_static PROPERTY OUTPUT_NAME "CCM")

endif()

if(CCM_COMPILE_SHARED_LIB)

    # Create CCM Static Library 
    add_library(CCM_shared SHARED ${CCM_sources})

    # Define the include directory.
    target_include_directories(CCM_shared PUBLIC "include")

    # Link against ICU
    target_link_libraries(CCM_shared PUBLIC ICU::uc ICU::i18n)

    # Set the CXX_STANDARD to 20.
    set_property(TARGET CCM_shared PROPERTY CXX_STANDARD 20) 

    # Set the output name to CCM.
    set_property(TARGET CCM_shared PROPERTY OUTPUT_NAME "CCM")

endif()