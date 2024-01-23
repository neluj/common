find_package(GTest REQUIRED)

add_executable(RentLodging_test 
lodgingRepositoryJSONTest.cpp)

target_link_libraries(RentLodging_test
 PUBLIC
 ${CONAN_LIBS}
  src)

add_test(NAME RentLodging_test
COMMAND RentLodging_test)

target_include_directories(RentLodging_test PUBLIC ../src )