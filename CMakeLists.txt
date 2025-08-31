cmake_minimum_required(VERSION 3.16)
project(oss_starter VERSION 0.1.0 LANGUAGES CXX)

option(OSS_WARNINGS_AS_ERRORS "Treat warnings as errors" OFF)
option(OSS_ENABLE_CLANG_TIDY "Enable clang-tidy static analysis" ON)
option(OSS_ENABLE_CPPCHECK "Enable cppcheck static analysis" OFF)
option(OSS_ENFORCE_NO_EXCEPTIONS "Disable C++ exceptions" OFF)
option(OSS_ENFORCE_NO_RTTI "Disable RTTI" OFF)
option(OSS_FORBID_DYNAMIC_ALLOCATION "Forbid global new/delete by linking guard" OFF)

# Global settings
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Static analysis integrations
if (OSS_ENABLE_CLANG_TIDY)
  find_program(CLANG_TIDY_EXE NAMES clang-tidy)
  if (CLANG_TIDY_EXE)
    set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_EXE};-p=${CMAKE_BINARY_DIR}")
  endif()
endif()

if (OSS_ENABLE_CPPCHECK)
  find_program(CPPCHECK_EXE NAMES cppcheck)
  if (CPPCHECK_EXE)
    set(CMAKE_CXX_CPPCHECK "${CPPCHECK_EXE};--project=${CMAKE_BINARY_DIR}/compile_commands.json;--addon=;--config=${CMAKE_SOURCE_DIR}/cppcheck.cfg")
  endif()
endif()

# Library
add_library(oss_starter src/lib.cpp)
add_library(oss::starter ALIAS oss_starter)

target_include_directories(oss_starter
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_compile_features(oss_starter PUBLIC cxx_std_17)

# Policy flags
if (OSS_ENFORCE_NO_EXCEPTIONS)
  if (MSVC)
    add_compile_options(/EHs-c-)
  else()
    add_compile_options(-fno-exceptions)
  endif()
endif()

if (OSS_ENFORCE_NO_RTTI)
  if (MSVC)
    add_compile_options(/GR-)
  else()
    add_compile_options(-fno-rtti)
  endif()
endif()

# Warnings
if (MSVC)
  target_compile_options(oss_starter PRIVATE /W4)
  if (OSS_WARNINGS_AS_ERRORS)
    target_compile_options(oss_starter PRIVATE /WX)
  endif()
else()
  target_compile_options(oss_starter PRIVATE -Wall -Wextra -Wpedantic)
  if (OSS_WARNINGS_AS_ERRORS)
    target_compile_options(oss_starter PRIVATE -Werror)
  endif()
endif()

# Forbid dynamic allocation by deleting global operators (optional)
if (OSS_FORBID_DYNAMIC_ALLOCATION)
  add_library(noalloc STATIC src/noalloc.cpp)
endif()

# Example
add_executable(example examples/main.cpp)
target_link_libraries(example PRIVATE oss::starter $<IF:$<BOOL:${OSS_FORBID_DYNAMIC_ALLOCATION}>,noalloc,>)

# Tests
include(CTest)
if (BUILD_TESTING)
  add_executable(test_basic tests/test_basic.cpp)
  target_link_libraries(test_basic PRIVATE oss::starter $<IF:$<BOOL:${OSS_FORBID_DYNAMIC_ALLOCATION}>,noalloc,>)
  add_test(NAME basic COMMAND test_basic)
endif()

# Install
include(GNUInstallDirs)
install(TARGETS oss_starter
  EXPORT oss_starterTargets
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(EXPORT oss_starterTargets
  FILE oss_starterTargets.cmake
  NAMESPACE oss::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/oss_starter
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/oss_starterConfigVersion.cmake"
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY SameMajorVersion
)
configure_file(cmake/oss_starterConfig.cmake
  "${CMAKE_CURRENT_BINARY_DIR}/oss_starterConfig.cmake"
  @ONLY
)
install(FILES
  "${CMAKE_CURRENT_BINARY_DIR}/oss_starterConfig.cmake"
  "${CMAKE_CURRENT_BINARY_DIR}/oss_starterConfigVersion.cmake"
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/oss_starter
)
