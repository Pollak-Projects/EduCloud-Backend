# To install vcpkg correctly
# git pull
#.\bootstrap-vcpkg.bat
#.\vcpkg.exe integrate install
# https://github.com/microsoft/vcpkg/issues/22074

cmake_minimum_required(VERSION 3.30)
project(EduCloud_Backend)

set(CMAKE_CXX_STANDARD 20)

#find_package(fmt CONFIG REQUIRED)

add_executable(EduCloud_Backend main.cpp)

#target_link_libraries(EduCloud_Backend PRIVATE fmt::fmt)


