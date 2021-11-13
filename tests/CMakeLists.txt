enable_testing()

add_executable(
    test_merge
    test_merge.cpp
    test_mergesort.cpp
    test_split.cpp
    ${CMAKE_SOURCE_DIR}/mergesort.cpp
)

target_link_libraries(
    test_merge
    gtest_main
)

target_include_directories(test_merge PUBLIC ${CMAKE_SOURCE_DIR})

include(GoogleTest)
gtest_discover_tests(test_merge)
