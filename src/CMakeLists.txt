include(FetchContent)

# SFML
FetchContent_Declare(
        sfml
        GIT_REPOSITORY "https://github.com/SFML/SFML.git"
        GIT_TAG        "2.5.1"
)
FetchContent_GetProperties(sfml)
if(NOT sfml_POPULATED)
  FetchContent_Populate(sfml)
  add_subdirectory(${sfml_SOURCE_DIR} ${sfml_BINARY_DIR})
endif()

# Asio
include(FetchContent)
FetchContent_Declare(
        asiocmake
        GIT_REPOSITORY "https://github.com/OlivierLDff/asio.cmake"
        GIT_TAG        "main"
)
FetchContent_MakeAvailable(asiocmake)


# Model
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/Model)

add_executable(Cppess
        ${CMAKE_CURRENT_LIST_DIR}/Model/Utils/ModelUtils.cpp ${CMAKE_CURRENT_LIST_DIR}/Model/Utils/ModelUtils.h
        ${CMAKE_CURRENT_LIST_DIR}/Model/Bishop/Bishop.cpp ${CMAKE_CURRENT_LIST_DIR}/Model/Bishop/Bishop.h
        ${CMAKE_CURRENT_LIST_DIR}/Model/King/King.cpp ${CMAKE_CURRENT_LIST_DIR}/Model/King/King.h
        ${CMAKE_CURRENT_LIST_DIR}/Model/Knight/Knight.cpp ${CMAKE_CURRENT_LIST_DIR}/Model/Knight/Knight.h
        ${CMAKE_CURRENT_LIST_DIR}/Model/Pawn/Pawn.cpp ${CMAKE_CURRENT_LIST_DIR}/Model/Pawn/Pawn.h
        ${CMAKE_CURRENT_LIST_DIR}/Model/Queen/Queen.cpp ${CMAKE_CURRENT_LIST_DIR}/Model/Queen/Queen.h
        ${CMAKE_CURRENT_LIST_DIR}/Model/Rook/Rook.cpp ${CMAKE_CURRENT_LIST_DIR}/Model/Rook/Rook.h
        main.cpp
        )

target_link_libraries(Cppess PRIVATE
        sfml-audio
        sfml-graphics
        sfml-system
        sfml-window

        asio::asio
        )



if(MINGW)
  target_link_libraries(Cppess PRIVATE ws2_32 wsock32 bcrypt)
endif()

# Library format used by the test package
add_library(cppess_test)

target_sources(cppess_test
  PRIVATE
    example.cpp
  PUBLIC
    example.h
  )

target_include_directories(cppess_test
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )

# we use this to get code coverage
# flags are only valid with the GNU compiler and on Linux
if(CMAKE_CXX_COMPILER_ID MATCHES GNU AND CMAKE_HOST_SYSTEM_NAME STREQUAL "Linux")
  target_compile_options(example
    PUBLIC
      "--coverage"
    )
  target_link_options(example
    INTERFACE
      "--coverage"
    )
endif()
