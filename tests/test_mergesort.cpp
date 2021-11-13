#include "mergesort.h"
#include <gtest/gtest.h>
#include <utility>
#include <sstream>
#include <vector>
#include <fstream>

TEST(MergeSortTest, SortAlphabetString) {
    std::stringstream input("qwertyuiopasdfghjklzxcvbnm");
    std::stringstream output;

    mergeSort(input, output);
    EXPECT_EQ(output.str(), "abcdefghijklmnopqrstuvwxyz");
}

TEST(MergeSortTest, SortText) {
    std::stringstream input("Elo, co tam slychac?");
    std::stringstream output;

    mergeSort(input, output);
    EXPECT_EQ(output.str(), "   ,?Eaaccchllmoosty");
}

TEST(MergeSortTest, SortAlphabetStringWithThreeTmpFiles) {
    std::stringstream input("qwertyuiopasdfghjklzxcvbnm");
    std::stringstream output;

    mergeSort(input, output, 3);
    EXPECT_EQ(output.str(), "abcdefghijklmnopqrstuvwxyz");
}

TEST(MergeSortTest, SortAlphabetStringWithFourTmpFiles) {
    std::stringstream input("qwertyuiopasdfghjklzxcvbnm");
    std::stringstream output;

    mergeSort(input, output, 4);
    EXPECT_EQ(output.str(), "abcdefghijklmnopqrstuvwxyz");
}

TEST(MergeSortTest, SortTextWithFourTmpFiles) {
    std::stringstream input("Elo, co tam slychac?");
    std::stringstream output;

    mergeSort(input, output, 4);
    EXPECT_EQ(output.str(), "   ,?Eaaccchllmoosty");
}

TEST(MergeSortTest, SortAlphabetStringWithFiveTmpFiles) {
    std::stringstream input("qwertyuiopasdfghjklzxcvbnm");
    std::stringstream output;

    mergeSort(input, output, 5);
    EXPECT_EQ(output.str(), "abcdefghijklmnopqrstuvwxyz");
}

TEST(MergeSortTest, SortAlphabetStringWithSixTmpFiles) {
    std::stringstream input("qwertyuiopasdfghjklzxcvbnm");
    std::stringstream output;

    mergeSort(input, output, 6);
    EXPECT_EQ(output.str(), "abcdefghijklmnopqrstuvwxyz");
}