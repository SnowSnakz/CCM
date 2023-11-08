# 3.12.0 is required for CXX_STANDARD 20
cmake_minimum_required(VERSION 3.12.0)

# The current version of CCM
set(CCM_VERSION_MAJOR 1)
set(CCM_VERSION_MINOR 0)
set(CCM_VERSION_BUILD 0)
set(CCM_VERSION "${CCM_VERSION_MAJOR}.${CCM_VERSION_MINOR}.${CCM_VERSION_BUILD}")

project(CCM VERSION ${CCM_VERSION})

include(GNUInstallDirs)

# Composite Character Model API
add_subdirectory("CCM")

# Model Editor Program
add_subdirectory("Editor")

# Finalize the install targets, enables support with find_package()
install(
  EXPORT CCMTargets
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/CCM
  NAMESPACE CCM::
  FILE CCMTargets.cmake
  )

include(CMakePackageConfigHelpers)
configure_package_config_file( 
  "Config.cmake.in" 
  "CCMConfig.cmake"
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/CCM
  PATH_VARS
    CMAKE_INSTALL_LIBDIR
  )

write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/CCMConfigVersion.cmake
  VERSION ${CCM_VERSION}
  COMPATIBILITY SameMinorVersion
  )

### Install Config and ConfigVersion files
install(
  FILES "${CMAKE_CURRENT_BINARY_DIR}/CCMConfig.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/CCMConfigVersion.cmake"
  DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/CCM"
  )
