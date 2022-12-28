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


# model
add_executable(Cppess
        model/pieces/bishop/Bishop.cpp model/pieces/bishop/Bishop.h
        model/pieces/king/King.cpp model/pieces/king/King.h
        model/pieces/knight/Knight.cpp model/pieces/knight/Knight.h
        model/pieces/pawn/Pawn.cpp model/pieces/pawn/Pawn.h
        model/pieces/queen/Queen.cpp model/pieces/queen/Queen.h
        model/pieces/rook/Rook.cpp model/pieces/rook/Rook.h
        model/pieces/Piece.cpp model/pieces/Piece.h
        model/pieces/colors.h
        model/table/Table.cpp model/table/Table.h
        model/services/ServiceTable.cpp model/services/ServiceTable.h
        gui/GUI.cpp gui/GUI.h
        main.cpp)

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
        model/pieces/Piece.cpp
  PUBLIC
        model/pieces/Piece.h
        model
  )

target_include_directories(cppess_test
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
        model/pieces/utils/ModelUtils.cpp model/pieces/utils/ModelUtils.h
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
