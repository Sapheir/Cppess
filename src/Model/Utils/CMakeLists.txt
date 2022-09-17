add_library(ModelUtils "")

target_sources(ModelUtils
        PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/ModelUtils.cpp
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/ModelUtils.h
        )

target_include_directories(ModelUtils
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
        )