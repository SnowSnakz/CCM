
# Create Editor Executable
add_executable(EditorCCM "src/main.cpp")

# Define the include directory.
target_include_directories(EditorCCM PUBLIC "include")

# Link against the CCM library.
target_link_libraries(EditorCCM PUBLIC CCM_static)

# Set the CXX_STANDARD to 20.
set_property(TARGET EditorCCM PROPERTY CXX_STANDARD 20) 
