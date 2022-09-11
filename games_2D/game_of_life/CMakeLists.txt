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

add_executable(game_of_life_tests uts/game_of_life_tests.cpp src/Grid.cpp)
target_include_directories(game_of_life_tests PUBLIC include)
target_link_libraries(game_of_life_tests gmock_main gtest gmock)
target_compile_features(game_of_life_tests PUBLIC cxx_std_20)


add_custom_target(run_tests
                  COMMAND game_of_life_tests
                  DEPENDS game_of_life_tests)

enable_testing()
add_test(tests game_of_life_tests)
