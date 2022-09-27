include(FetchContent)
FetchContent_Declare(gtest
  QUIET
  URL https://github.com/google/googletest/archive/release-1.12.1.tar.gz
)
# configure build of googletest
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(gtest)

add_executable(unit_tests
        model/Pieces/utils/TestModelUtils.cpp
        ../src/model/pieces/utils/ModelUtils.h
        ../src/model/pieces/utils/ModelUtils.cpp
        model/Pieces/bishop/TestBishop.cpp
        ../src/model/pieces/bishop/Bishop.h
        ../src/model/pieces/bishop/Bishop.cpp
        model/Pieces/king/TestKing.cpp
        ../src/model/pieces/king/King.h
        ../src/model/pieces/king/King.cpp
        model/Pieces/knight/TestKnight.cpp
        ../src/model/pieces/knight/Knight.h
        ../src/model/pieces/knight/Knight.cpp
        model/Pieces/pawn/TestPawn.cpp
        ../src/model/pieces/pawn/Pawn.h
        ../src/model/pieces/pawn/Pawn.cpp
        model/Pieces/queen/TestQueen.cpp
        ../src/model/pieces/queen/Queen.h
        ../src/model/pieces/queen/Queen.cpp
        model/Pieces/rook/TestRook.cpp
        ../src/model/pieces/rook/Rook.h
        ../src/model/pieces/rook/Rook.cpp
        model/Pieces/TestPiece.cpp
        ../src/model/pieces/Piece.h
)

target_link_libraries(unit_tests
  PRIVATE
    cppess_test
    gtest_main
  )

# automatic discovery of unit tests
include(GoogleTest)
gtest_discover_tests(unit_tests
  PROPERTIES
    LABELS "unit"
  DISCOVERY_TIMEOUT  # how long to wait (in seconds) before crashing
    240
  )
