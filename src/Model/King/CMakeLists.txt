add_library(King "")

target_sources(King
PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/King.cpp
PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/King.h
)

target_include_directories(King
PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)