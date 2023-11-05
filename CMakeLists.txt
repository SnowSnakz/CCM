# 3.12.0 is required for CXX_STANDARD 20
cmake_minimum_required(VERSION 3.12.0)

project("Composite Character Model")

# Composite Character Model API
add_subdirectory("CCM")

# Model Editor Program
add_subdirectory("Editor")
