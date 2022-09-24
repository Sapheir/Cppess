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
        ${CMAKE_CURRENT_LIST_DIR}/Model/Utils/TestModelUtils.cpp
        ../src/Model/Utils/ModelUtils.h
        ../src/Model/Utils/ModelUtils.cpp
        ${CMAKE_CURRENT_LIST_DIR}/Model/Bishop/TestBishop.cpp
        ../src/Model/Bishop/Bishop.h
        ../src/Model/Bishop/Bishop.cpp
        ${CMAKE_CURRENT_LIST_DIR}/Model/King/TestKing.cpp
        ../src/Model/King/King.h
        ../src/Model/King/King.cpp
        ${CMAKE_CURRENT_LIST_DIR}/Model/Knight/TestKnight.cpp
        ../src/Model/Knight/Knight.h
        ../src/Model/Knight/Knight.cpp
        example_add.cpp
        example_subtract.cpp
        example_multiply.cpp
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
