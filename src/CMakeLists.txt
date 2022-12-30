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
        model/domain/pieces/bishop/Bishop.cpp model/domain/pieces/bishop/Bishop.h
        model/domain/pieces/king/King.cpp model/domain/pieces/king/King.h
        model/domain/pieces/knight/Knight.cpp model/domain/pieces/knight/Knight.h
        model/domain/pieces/pawn/Pawn.cpp model/domain/pieces/pawn/Pawn.h
        model/domain/pieces/queen/Queen.cpp model/domain/pieces/queen/Queen.h
        model/domain/pieces/rook/Rook.cpp model/domain/pieces/rook/Rook.h
        model/domain/pieces/Piece.cpp model/domain/pieces/Piece.h
        model/domain/pieces/colors.h
        model/domain/pieces/pieces.h
        model/domain/Events.h
        model/table/Table.cpp model/table/Table.h
        model/services/ServiceTable.cpp model/services/ServiceTable.h
        model/table/History.h
        model/table/History.cpp
        model/domain/history/HistoryMove.h
        model/domain/history/HistoryMove.cpp
        gui/GUI.cpp gui/GUI.h
        gui/components/chess_table/ChessTable.cpp gui/components/chess_table/ChessTable.h
        gui/screens/Screen.cpp gui/screens/Screen.h gui/screens/screens.h
        gui/screens/main_menu/MainMenu.cpp gui/screens/main_menu/MainMenu.h gui/screens/main_menu/main_menu_options.h
        gui/screens/single_player/SinglePlayerOptions.cpp gui/screens/single_player/SinglePlayerOptions.h
        gui/screens/single_player/SinglePlayer.cpp gui/screens/single_player/SinglePlayer.h
        gui/screens/multiplayer/MultiplayerOptions.cpp gui/screens/multiplayer/MultiplayerOptions.h
        game/Game.cpp game/Game.h
        main.cpp game/single_player/SinglePlayerGame.cpp game/single_player/SinglePlayerGame.h)

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
        model/domain/pieces/Piece.cpp
  PUBLIC
        model/domain/pieces/Piece.h
        model
  )

target_include_directories(cppess_test
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
        model/domain/pieces/utils/ModelUtils.cpp model/domain/pieces/utils/ModelUtils.h
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
