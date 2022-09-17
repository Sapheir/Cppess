add_library(Queen "")

target_sources(Queen
PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/Queen.cpp
PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/Queen.h
)

target_include_directories(Queen
PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)