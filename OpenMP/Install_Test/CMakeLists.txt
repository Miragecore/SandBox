cmake_minimum_required(VERSION 3.22)

set(CMAKE_SYSTEM_PROCESSOR "X86_64")
set(CMAKE_OSX_ARCHITECTURES "x86_64")

project(install_test )

#Add OpenMP 
find_package(OpenMP REQUIRED)

add_executable( install_test.app install_test.cpp )
target_link_libraries( install_test.app PRIVATE OpenMP::OpenMP_CXX)
