#include "mergesort.h"
#include <gtest/gtest.h>
#include <utility>
#include <sstream>
#include <vector>

TEST(SplitTest, SplitEvenInputToTwoOutputsOneChar) {
    std::stringstream input("abcdefgh", std::ios_base::in);
    std::stringstream output1(std::ios_base::out);
    std::stringstream output2(std::ios_base::out);

    std::vector<std::iostream*> outputs = {
        &output1,
        &output2
    };

    splitData(input, outputs, 1);
    EXPECT_EQ(output1.str(), "aceg");
    EXPECT_EQ(output2.str(), "bdfh");
}

TEST(SplitTest, SplitOddInputToTwoOutputsOneChar) {
    std::stringstream input("abcdefg", std::ios_base::in);
    std::stringstream output1(std::ios_base::out);
    std::stringstream output2(std::ios_base::out);

    std::vector<std::iostream*> outputs = {
        &output1,
        &output2
    };

    splitData(input, outputs, 1);
    EXPECT_EQ(output1.str(), "aceg");
    EXPECT_EQ(output2.str(), "bdf");
}

TEST(SplitTest, SplitEvenInputToTwoOutputsTwoChars) {
    std::stringstream input("abcdefgh", std::ios_base::in);
    std::stringstream output1(std::ios_base::out);
    std::stringstream output2(std::ios_base::out);

    std::vector<std::iostream*> outputs = {
        &output1,
        &output2
    };

    splitData(input, outputs, 2);
    EXPECT_EQ(output1.str(), "abef");
    EXPECT_EQ(output2.str(), "cdgh");
}

TEST(SplitTest, SplitOddInputToTwoOutputsTwoChars) {
    std::stringstream input("abcdefg", std::ios_base::in);
    std::stringstream output1(std::ios_base::out);
    std::stringstream output2(std::ios_base::out);

    std::vector<std::iostream*> outputs = {
        &output1,
        &output2
    };

    splitData(input, outputs, 2);
    EXPECT_EQ(output1.str(), "abef");
    EXPECT_EQ(output2.str(), "cdg");
}

TEST(SplitTest, SplitEvenInputToThreeOutputsOneChar) {
    std::stringstream input("abcdefgh", std::ios_base::in);
    std::stringstream output1(std::ios_base::out);
    std::stringstream output2(std::ios_base::out);
    std::stringstream output3(std::ios_base::out);

    std::vector<std::iostream*> outputs = {
        &output1,
        &output2,
        &output3
    };

    splitData(input, outputs, 1);
    EXPECT_EQ(output1.str(), "adg");
    EXPECT_EQ(output2.str(), "beh");
    EXPECT_EQ(output3.str(), "cf");
}

TEST(SplitTest, SplitOddInputToThreeOutputsOneChar) {
    std::stringstream input("abcdefg", std::ios_base::in);
    std::stringstream output1(std::ios_base::out);
    std::stringstream output2(std::ios_base::out);
    std::stringstream output3(std::ios_base::out);

    std::vector<std::iostream*> outputs = {
        &output1,
        &output2,
        &output3
    };

    splitData(input, outputs, 1);
    EXPECT_EQ(output1.str(), "adg");
    EXPECT_EQ(output2.str(), "be");
    EXPECT_EQ(output3.str(), "cf");
}

TEST(SplitTest, SplitEvenInputToThreeOutputsTwoChars) {
    std::stringstream input("abcdefgh", std::ios_base::in);
    std::stringstream output1(std::ios_base::out);
    std::stringstream output2(std::ios_base::out);
    std::stringstream output3(std::ios_base::out);

    std::vector<std::iostream*> outputs = {
        &output1,
        &output2,
        &output3
    };

    splitData(input, outputs, 2);
    EXPECT_EQ(output1.str(), "abgh");
    EXPECT_EQ(output2.str(), "cd");
    EXPECT_EQ(output3.str(), "ef");
}