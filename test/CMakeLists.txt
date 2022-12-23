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
        model/domain/Pieces/bishop/TestBishop.cpp
        ../src/model/domain/pieces/bishop/Bishop.h
        ../src/model/domain/pieces/bishop/Bishop.cpp
        model/domain/Pieces/king/TestKing.cpp
        ../src/model/domain/pieces/king/King.h
        ../src/model/domain/pieces/king/King.cpp
        model/domain/Pieces/knight/TestKnight.cpp
        ../src/model/domain/pieces/knight/Knight.h
        ../src/model/domain/pieces/knight/Knight.cpp
        model/domain/Pieces/pawn/TestPawn.cpp
        ../src/model/domain/pieces/pawn/Pawn.h
        ../src/model/domain/pieces/pawn/Pawn.cpp
        model/domain/Pieces/queen/TestQueen.cpp
        ../src/model/domain/pieces/queen/Queen.h
        ../src/model/domain/pieces/queen/Queen.cpp
        model/domain/Pieces/rook/TestRook.cpp
        ../src/model/domain/pieces/rook/Rook.h
        ../src/model/domain/pieces/rook/Rook.cpp
        model/domain/Pieces/TestPiece.cpp
        ../src/model/domain/pieces/Piece.h
        ../src/model/domain/pieces/Piece.cpp
        ../src/model/table/Table.h
        ../src/model/table/Table.cpp
        ../src/model/services/ServiceTable.h
        ../src/model/services/ServiceTable.cpp
        model/table/TestTableAddPieceGetPiece.cpp
        model/table/TestTableRemovePiece.cpp
        model/table/TestTableAvailableNextPositions.cpp
        model/table/TestServiceMovePiece.cpp
        model/domain/TestHistoryMove.cpp

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
