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

add_executable(Forward_listTests uts/Forward_listTests.cpp src/Forward_list.cpp src/Node.cpp)
target_include_directories(Forward_listTests PUBLIC include)
target_link_libraries(Forward_listTests gmock_main gtest gmock)
target_compile_features(Forward_listTests PUBLIC cxx_std_20)


add_custom_target(run_tests
                  COMMAND Forward_listTests
                  DEPENDS Forward_listTests)

enable_testing()
add_test(tests Forward_listTests)
