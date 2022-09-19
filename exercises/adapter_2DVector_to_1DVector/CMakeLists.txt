cmake_minimum_required(VERSION 3.12)
project(ChangeMyName CXX)

add_compile_options(-Wall -Wextra -pedantic)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG main
)

FetchContent_MakeAvailable(googletest)

add_executable(tests uts/adapter_tests.cpp )
target_include_directories(tests PUBLIC include)
target_link_libraries(tests gmock_main gtest gmock)
target_compile_features(tests PUBLIC cxx_std_20)

add_custom_target(run_tests
                  COMMAND tests
                  DEPENDS tests)

enable_testing()
add_test(tests game_of_life_tests)
