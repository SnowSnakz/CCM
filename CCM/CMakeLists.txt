
set(CCM_sources "src/CCM.cpp")

set(CCM_COMPILE_STATIC_LIB TRUE CACHE BOOL "Compile a static version of the CCM library. (libCCM.a / CCM.lib)")
set(CCM_COMPILE_SHARED_LIB TRUE CACHE BOOL "Compile a shared version of the CCM library. (libCCM.so / CCM.dll / CCM.dylib)")

if(CCM_COMPILE_STATIC_LIB)
    # Create CCM Static Library 
    add_library(CCM_static STATIC ${CCM_sources})

    # Define the include directory.
    target_include_directories(CCM_static PUBLIC "include")

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

    # Set the CXX_STANDARD to 20.
    set_property(TARGET CCM_shared PROPERTY CXX_STANDARD 20) 

    # Set the output name to CCM.
    set_property(TARGET CCM_shared PROPERTY OUTPUT_NAME "CCM")
endif()