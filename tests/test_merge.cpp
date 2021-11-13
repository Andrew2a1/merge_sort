#include "mergesort.h"
#include <gtest/gtest.h>
#include <utility>
#include <sstream>
#include <vector>

TEST(MergeTest, MergeTwoTrivialSortedStreamsByOneChar) {
    std::stringstream input1("a", std::ios_base::in);
    std::stringstream input2("b", std::ios_base::in);
    std::stringstream output(std::ios_base::out);

    std::vector<std::iostream*> inputs = {
        &input1,
        &input2
    };

    merge(inputs, output, 1);
    EXPECT_EQ(output.str(), "ab");
}

TEST(MergeTest, MergeTwoTrivialUnsortedStreamsByOneChar) {
    std::stringstream input1("b", std::ios_base::in);
    std::stringstream input2("a", std::ios_base::in);
    std::stringstream output(std::ios_base::out);

    std::vector<std::iostream*> inputs = {
        &input1,
        &input2
    };

    merge(inputs, output, 1);
    EXPECT_EQ(output.str(), "ab");
}

TEST(MergeTest, MergeTwoSortedStreamsByOneChar) {
    std::stringstream input1("ac", std::ios_base::in);
    std::stringstream input2("bd", std::ios_base::in);
    std::stringstream output(std::ios_base::out);

    std::vector<std::iostream*> inputs = {
        &input1,
        &input2
    };

    merge(inputs, output, 1);
    EXPECT_EQ(output.str(), "abcd");
}

TEST(MergeTest, MergeTwoUnsortedStreamsByOneChar) {
    std::stringstream input1("bd", std::ios_base::in);
    std::stringstream input2("ac", std::ios_base::in);
    std::stringstream output(std::ios_base::out);

    std::vector<std::iostream*> inputs = {
        &input1,
        &input2
    };

    merge(inputs, output, 1);
    EXPECT_EQ(output.str(), "abcd");
}

TEST(MergeTest, MergeTwoSortedStreamsByTwoChars) {
    std::stringstream input1("ab", std::ios_base::in);
    std::stringstream input2("cd", std::ios_base::in);
    std::stringstream output(std::ios_base::out);

    std::vector<std::iostream*> inputs = {
        &input1,
        &input2
    };

    merge(inputs, output, 2);
    EXPECT_EQ(output.str(), "abcd");
}

TEST(MergeTest, MergeTwoSortedStreamsByThreeChars) {
    std::stringstream input1("abc", std::ios_base::in);
    std::stringstream input2("def", std::ios_base::in);
    std::stringstream output(std::ios_base::out);

    std::vector<std::iostream*> inputs = {
        &input1,
        &input2
    };

    merge(inputs, output, 3);
    EXPECT_EQ(output.str(), "abcdef");
}

TEST(MergeTest, MergeTwoLongUnortedStreamsByThreeChars) {
    std::stringstream input1("abcjkz", std::ios_base::in);
    std::stringstream input2("defghi", std::ios_base::in);
    std::stringstream output(std::ios_base::out);

    std::vector<std::iostream*> inputs = {
        &input1,
        &input2
    };

    merge(inputs, output, 3);
    EXPECT_EQ(output.str(), "abcdefghijkz");
}

TEST(MergeTest, MergeTwoSortedStreamsDifferentSizeByOneChar) {
    std::stringstream input1("ac", std::ios_base::in);
    std::stringstream input2("b", std::ios_base::in);
    std::stringstream output(std::ios_base::out);

    std::vector<std::iostream*> inputs = {
        &input1,
        &input2
    };

    merge(inputs, output, 1);
    EXPECT_EQ(output.str(), "abc");
}

TEST(MergeTest, MergeTwoLongSortedStreamsDifferentSizeByOneChar) {
    std::stringstream input1("acegik", std::ios_base::in);
    std::stringstream input2("bdfhjl", std::ios_base::in);
    std::stringstream output(std::ios_base::out);

    std::vector<std::iostream*> inputs = {
        &input1,
        &input2
    };

    merge(inputs, output, 1);
    EXPECT_EQ(output.str(), "abcdefghijkl");
}

TEST(MergeTest, MergeTwoStrangeSortedStreamsDifferentSizeByOneChar) {
    std::stringstream input1("acbfa", std::ios_base::in);
    std::stringstream input2("b", std::ios_base::in);
    std::stringstream output(std::ios_base::out);

    std::vector<std::iostream*> inputs = {
        &input1,
        &input2
    };

    merge(inputs, output, 1);
    EXPECT_EQ(output.str(), "abcbfa");
}

TEST(MergeTest, MergeTwoStreamsByManyCharacters) {
    std::stringstream input1("azxyz", std::ios_base::in);
    std::stringstream input2("bcdef", std::ios_base::in);
    std::stringstream output(std::ios_base::out);

    std::vector<std::iostream*> inputs = {
        &input1,
        &input2
    };

    merge(inputs, output, 3);
    EXPECT_EQ(output.str(), "abcdxzefyz");
}