cmake_minimum_required(VERSION 3.22)

set(CMAKE_SYSTEM_PROCESSOR "X86_64")
set(CMAKE_OSX_ARCHITECTURES "x86_64")

project(openMVG_test)

#Add OpenMVG 
find_package(OpenMVG REQUIRED)
find_package(OpenMP REQUIRED)

add_executable(describe_and_match.app describe_and_match.cpp )
target_include_directories( describe_and_match.app PRIVATE /Users/yoonsukim/repo/openMVG/build/install/include/openMVG) 
target_link_libraries( describe_and_match.app 
        PRIVATE 
            OpenMVG::openMVG_image
            OpenMVG::openMVG_features
            OpenMVG::openMVG_matching
        )

