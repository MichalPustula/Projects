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

add_executable(snake_tests uts/snake_tests.cpp src/World.cpp src/Snake.cpp src/Game.cpp)
target_include_directories(snake_tests PUBLIC include)
target_link_libraries(snake_tests gmock_main gtest gmock)
target_compile_features(snake_tests PUBLIC cxx_std_20)

add_custom_target(run_tests
                  COMMAND snake_tests
                  DEPENDS snake_tests)

add_executable(snake_game src/main.cpp src/World.cpp src/Snake.cpp src/Game.cpp)
target_include_directories(snake_game PUBLIC include)
target_link_libraries(snake_game gmock_main gtest gmock)
target_compile_features(snake_game PUBLIC cxx_std_20)

add_custom_target(run_game
                  COMMAND snake_game
                  DEPENDS snake_game)

enable_testing()
add_test(tests game_of_life_tests)
