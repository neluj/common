add_library(domain
src/lodging.cpp
src/offer.cpp 
src/user.cpp)

target_include_directories(domain PUBLIC include)