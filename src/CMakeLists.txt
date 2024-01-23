add_executable(${PROJECT_NAME} main.cpp)

add_library(src 
lodging.cpp
offer.cpp
user.cpp
lodgingRepositoryJSON.cpp
lodgingRepositoryXML.cpp)

target_link_libraries( src PUBLIC ${CONAN_LIBS})
