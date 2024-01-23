cmake_minimum_required (VERSION 3.22)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(RentLodging)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(NO_OUTPUT_DIRS)

enable_testing()

add_subdirectory(src)
add_subdirectory(test)

target_link_libraries( ${PROJECT_NAME} PUBLIC src)

target_include_directories(src PUBLIC include src)