add_library(Pawn "")

target_sources(Pawn
PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/Pawn.cpp
PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/Pawn.h
)

target_include_directories(Pawn
PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)