cmake_minimum_required(VERSION 3.12)
project(CollatzConjecture CXX)

add_compile_options(-Wall -Wextra -pedantic)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG main
)

FetchContent_MakeAvailable(googletest)

add_executable(string_tests uts/string_tests.cpp )
target_include_directories(string_tests PUBLIC include)
target_link_libraries(string_tests gmock_main gtest gmock)
target_compile_features(string_tests PUBLIC cxx_std_20)

add_custom_target(run_tests
                  COMMAND string_tests
                  DEPENDS string_tests)

enable_testing()
add_test(tests string_tests)
