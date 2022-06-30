add_library(bl
src/createLodgingUC.cpp
src/createOfferUC.cpp
src/findLodgingByOfferIDUC.cpp
src/findOffersByStartDateUC.cpp
src/generateDatas.cpp
src/hireOutUC.cpp
src/loginUC.cpp
src/registerUC.cpp
src/session.cpp
)

target_link_libraries( bl PUBLIC database)

target_include_directories(bl PUBLIC include ../database/include) 