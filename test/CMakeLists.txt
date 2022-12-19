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
        model/pieces/bishop/TestBishop.cpp
        ../src/model/pieces/bishop/Bishop.h
        ../src/model/pieces/bishop/Bishop.cpp
        model/pieces/king/TestKing.cpp
        ../src/model/pieces/king/King.h
        ../src/model/pieces/king/King.cpp
        model/pieces/knight/TestKnight.cpp
        ../src/model/pieces/knight/Knight.h
        ../src/model/pieces/knight/Knight.cpp
        model/pieces/pawn/TestPawn.cpp
        ../src/model/pieces/pawn/Pawn.h
        ../src/model/pieces/pawn/Pawn.cpp
        model/pieces/queen/TestQueen.cpp
        ../src/model/pieces/queen/Queen.h
        ../src/model/pieces/queen/Queen.cpp
        model/pieces/rook/TestRook.cpp
        ../src/model/pieces/rook/Rook.h
        ../src/model/pieces/rook/Rook.cpp
        model/pieces/TestPiece.cpp
        ../src/model/pieces/Piece.h
        ../src/model/pieces/Piece.cpp
        ../src/model/table/Table.h
        ../src/model/table/Table.cpp
        model/table/TestTableAddPieceGetPiece.cpp
        model/table/TestRemovePiece.cpp
        model/table/TestAvailableNextPositions.cpp
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
