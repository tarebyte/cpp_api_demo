cmake_minimum_required(VERSION 3.5.0)

# Uncomment me if you want to use this outside of VSCode.
# set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake"
#   CACHE STRING "Vcpkg toolchain file")

project(github_app_demo VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(demo src/main.cpp)

find_package(fmt CONFIG REQUIRED)
target_link_libraries(demo PRIVATE fmt::fmt-header-only)

find_package(httplib CONFIG REQUIRED)

find_path(JWT_CPP_INCLUDE_DIRS "jwt-cpp/base.h")
target_include_directories(demo PRIVATE ${JWT_CPP_INCLUDE_DIRS})

find_package(OpenSSL REQUIRED)

target_link_libraries(demo PRIVATE OpenSSL::SSL OpenSSL::Crypto httplib::httplib)
