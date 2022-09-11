cmake_minimum_required(VERSION 3.12)
project(ChangeMyName CXX)

add_compile_options(-Wall -Wextra -pedantic -Werror)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG main
)

FetchContent_MakeAvailable(googletest)

add_executable(ArrayTests uts/ArrayTests.cpp)
target_include_directories(ArrayTests PUBLIC include)
target_link_libraries(ArrayTests gmock_main gtest gmock)
target_compile_features(ArrayTests PUBLIC cxx_std_20)


add_custom_target(run_tests
                  COMMAND ArrayTests
                  DEPENDS ArrayTests)

enable_testing()
add_test(tests ArrayTests)
