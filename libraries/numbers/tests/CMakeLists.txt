cmake_minimum_required(VERSION 3.28)

if (GTest_FOUND)
    add_executable(numbers_tests)
    file(GLOB_RECURSE TEST_FILES "*.cc")
    target_sources(numbers_tests PRIVATE ${TEST_FILES})
    target_link_libraries(numbers_tests numbers GTest::GTest GTest::Main)

    gtest_discover_tests(numbers_tests)
endif ()