 cmake_minimum_required(VERSION 3.20)
 project (tristate)
 set(CMAKE_CXX_STANDARD 20)
 set(CMAKE_CXX_STANDARD_REQUIRED ON)
  
 set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
 include(FetchContent)

 FetchContent_Declare(
   googletest
   GIT_REPOSITORY https://github.com/google/googletest.git
   GIT_TAG release-1.12.1
   ) 

 FetchContent_MakeAvailable(googletest)
 set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
 set(BUILD_GTEST ON CACHE BOOL "" FORCE)
 add_executable(tristate tristate/main.cpp)
 add_executable(tristate_test tristate/tests/tristate_test.cpp)

 enable_testing()

target_link_libraries(
  tristate_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(tristate_test)
