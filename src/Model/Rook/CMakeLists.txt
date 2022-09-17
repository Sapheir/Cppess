add_library(Rook "")

target_sources(Rook
PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/Rook.cpp
PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/Rook.h
)

target_include_directories(Rook
PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)