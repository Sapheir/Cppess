add_library(Bishop "")

target_sources(Bishop
 PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/Bishop.cpp
 PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/Bishop.h
)

target_include_directories(Bishop
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)