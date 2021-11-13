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
