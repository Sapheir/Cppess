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
        ${CMAKE_CURRENT_LIST_DIR}/model/utils/TestModelUtils.cpp
        ../src/model/utils/ModelUtils.h
        ../src/model/utils/ModelUtils.cpp
        ${CMAKE_CURRENT_LIST_DIR}/model/bishop/TestBishop.cpp
        ../src/model/bishop/Bishop.h
        ../src/model/bishop/Bishop.cpp
        ${CMAKE_CURRENT_LIST_DIR}/model/king/TestKing.cpp
        ../src/model/king/King.h
        ../src/model/king/King.cpp
        ${CMAKE_CURRENT_LIST_DIR}/model/knight/TestKnight.cpp
        ../src/model/knight/Knight.h
        ../src/model/knight/Knight.cpp
        ${CMAKE_CURRENT_LIST_DIR}/model/pawn/TestPawn.cpp
        ../src/model/pawn/Pawn.h
        ../src/model/pawn/Pawn.cpp
        ${CMAKE_CURRENT_LIST_DIR}/model/queen/TestQueen.cpp
        ../src/model/queen/Queen.h
        ../src/model/queen/Queen.cpp
        ${CMAKE_CURRENT_LIST_DIR}/model/rook/TestRook.cpp
        ../src/model/rook/Rook.h
        ../src/model/rook/Rook.cpp
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
