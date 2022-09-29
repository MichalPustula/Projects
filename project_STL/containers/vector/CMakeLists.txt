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

add_executable(VectorTests uts/VectorTests.cpp)
target_include_directories(VectorTests PUBLIC include)
target_link_libraries(VectorTests gmock_main gtest gmock)
target_compile_features(VectorTests PUBLIC cxx_std_20)


add_custom_target(run_tests
                  COMMAND VectorTests
                  DEPENDS VectorTests)

enable_testing()
add_test(tests VectorTests)
