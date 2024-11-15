cmake_minimum_required(VERSION 3.28)

find_package(GTest)

if (GTest_FOUND)
    include(GoogleTest)
    enable_testing()
    add_executable(tests)
    file(GLOB_RECURSE TEST_FILES "*.cc")
    target_sources(tests PRIVATE ${TEST_FILES})
    target_link_libraries(tests numbers GTest::GTest GTest::Main)

    gtest_discover_tests(tests)
else ()
    message(STATUS "GTest not found")
endif ()