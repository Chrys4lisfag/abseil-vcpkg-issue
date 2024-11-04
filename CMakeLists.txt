cmake_minimum_required(VERSION 3.28)
include(FetchContent)

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake CACHE STRING "Vcpkg toolchain file")
set(VCPKG_TARGET_TRIPLET "x64-windows-static" CACHE STRING "Vcpkg target triplet")
project(abseil-vcpkg-issue LANGUAGES CXX C)

# Set C++ standard and runtime library
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

## Export compile commands
#set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# Add executable and link libraries
add_executable(abseil-vcpkg-issue main.cpp)

find_package(absl CONFIG REQUIRED)
# note: 186 additional targets are not displayed.
target_link_libraries(abseil-vcpkg-issue PRIVATE
        absl::any
        absl::log
        absl::base
        absl::bits
        absl::flat_hash_set)

