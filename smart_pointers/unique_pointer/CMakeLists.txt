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

add_executable(Unique_ptr_tests uts/Unique_ptr_tests.cpp )
target_include_directories(Unique_ptr_tests PUBLIC include)
target_link_libraries(Unique_ptr_tests gmock_main gtest gmock)
target_compile_features(Unique_ptr_tests PUBLIC cxx_std_20)

add_custom_target(run_tests
                  COMMAND Unique_ptr_tests
                  DEPENDS Unique_ptr_tests)

enable_testing()
add_test(tests Unique_ptr_tests)
