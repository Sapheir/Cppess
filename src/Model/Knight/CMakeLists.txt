add_library(Knight "")

target_sources(Knight
PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/Knight.cpp
PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/Knight.h
        )

target_include_directories(Knight
PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)