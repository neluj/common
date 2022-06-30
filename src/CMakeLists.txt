cmake_minimum_required (VERSION 3.22)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(rentLodging)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(NO_OUTPUT_DIRS)

add_subdirectory( domain )
add_subdirectory( database )
add_subdirectory( businessLogic )
add_subdirectory( ui )

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries( ${PROJECT_NAME} PUBLIC ui)



