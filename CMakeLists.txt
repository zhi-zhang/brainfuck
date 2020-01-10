cmake_minimum_required(VERSION 3.10)
project(brainfuck)

# Use C++17
set(CMAKE_CXX_STANDARD 17)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
elseif(MSVC)
  add_compile_options(-D_SILENCE_CXX17_OLD_ALLOCATOR_MEMBERS_DEPRECATION_WARNING )
  add_compile_options(-D_USE_MATH_DEFINES )
endif()

add_executable(bf)

# target_sources(bf PRIVATE)

# target_sources(bf PRIVATE)

target_include_directories(bf PRIVATE include)

if (MSVC)
  set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT bf)
endif()

# https://cliutils.gitlab.io/modern-cmake/chapters/testing/googletest.html

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.8.0
)

FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
  FetchContent_Populate(googletest)
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()