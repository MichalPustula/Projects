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

add_executable(observer_tests uts/observer_tests.cpp src/Server.cpp src/Client.cpp)
target_include_directories(observer_tests PUBLIC include)
target_link_libraries(observer_tests gmock_main gtest gmock)
target_compile_features(observer_tests PUBLIC cxx_std_20)

add_custom_target(run_tests
                  COMMAND observer_tests
                  DEPENDS observer_tests)

enable_testing()
add_test(tests observer_tests)
