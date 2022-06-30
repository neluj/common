add_library(ui
src/consoleUI.cpp
)

target_link_libraries( ui PUBLIC bl)

target_include_directories(ui PUBLIC include ../domain/include ../database/include ../businessLogic/include) 