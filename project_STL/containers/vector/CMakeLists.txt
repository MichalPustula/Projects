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

add_executable(Vector_tests uts/Vector_tests.cpp)
target_include_directories(Vector_tests PUBLIC include)
target_link_libraries(Vector_tests gmock_main gtest gmock)
target_compile_features(Vector_tests PUBLIC cxx_std_20)


add_custom_target(run_tests
                  COMMAND Vector_tests
                  DEPENDS Vector_tests)

enable_testing()
add_test(tests Vector_tests)
