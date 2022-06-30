add_library(database
src/lodgingRepositoryJSON.cpp
src/lodgingRepositoryXML.cpp
src/offerRepositoryJSON.cpp
src/offerRepositoryXML.cpp
src/userRepositoryJSON.cpp
src/userRepositoryXML.cpp
src/repositoryCreator.cpp
src/repositoryJSONFact.cpp
src/repositoryXMLFact.cpp
src/userRepositoryJSON.cpp
src/userRepositoryXML.cpp
)

target_link_libraries( database PUBLIC ${CONAN_LIBS} domain)

target_include_directories(database PUBLIC include ../domain/include)