
# Create cache variable for compiling the editor program.
set(CCM_COMPILE_EDITOR_PROGRAM TRUE CACHE BOOL "Compile the Editor program.")

# Locate GLFW
find_package(glfw3 3.3.8 REQUIRED)

if(CCM_COMPILE_EDITOR_PROGRAM)
    if(NOT CCM_COMPILE_STATIC_LIB)

        # The Editor requires the static library to be compiled.
        message(WARNING "Compile target `CCM_editor` requires target `CCM_static`, which is currently disabled.")
        message(WARNING "(To hide this warning, please either set CCM_COMPILE_EDITOR_PROGRAM to false, or set CCM_COMPILE_STATIC_LIB to true.)")

    else()

        # Create Editor Executable
        add_executable(CCM_editor "src/main.cpp" "src/gl.c")

        # Define the include directory.
        target_include_directories(CCM_editor PUBLIC "include")

        # Link against the CCM library.
        target_link_libraries(CCM_editor PUBLIC CCM_static glfw)

        # Set the CXX_STANDARD to 20.
        set_property(TARGET CCM_editor PROPERTY CXX_STANDARD 20)

    endif()
endif()