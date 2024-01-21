#include "gtest/gtest.h"
#include "pch.h"
#include "Test_Con.h"
#include <string>

TEST(ConversionsTest, DecimalToBinary) {
    Test_Con System_Converter;
    std::string x = "11";
    std::string y = "234";
    std::string z = "7";

    EXPECT_EQ(System_Converter.DecimalToBinary(x), "1011");

    EXPECT_EQ(System_Converter.DecimalToBinary(y), "11101010");

    EXPECT_EQ(System_Converter.DecimalToBinary(z), "111");

}

TEST(ConversionsTest, BinaryToDecimal) {
    Test_Con System_Converter;
    std::string x = "1111";
    std::string y = "1111101";
    std::string z = "10101";

    EXPECT_EQ(System_Converter.BinaryToDecimal(x), "15");

    EXPECT_EQ(System_Converter.BinaryToDecimal(y), "125");

    EXPECT_EQ(System_Converter.BinaryToDecimal(z), "21");

}

TEST(ConversionsTest, DecimalToOctal) {
    Test_Con System_Converter;
    std::string x = "17";
    std::string y = "244";
    std::string z = "334";

    EXPECT_EQ(System_Converter.DecimalToOctal(x), "21");

    EXPECT_EQ(System_Converter.DecimalToOctal(y), "364");

    EXPECT_EQ(System_Converter.DecimalToOctal(z), "516");

}

TEST(ConversionsTest, OctalToDecimal) {
    Test_Con System_Converter;
    std::string x = "103";
    std::string y = "221";
    std::string z = "1731";

    EXPECT_EQ(System_Converter.OctalToDecimal(x), "67");

    EXPECT_EQ(System_Converter.OctalToDecimal(y), "145");

    EXPECT_EQ(System_Converter.OctalToDecimal(z), "985");

}

TEST(ConversionsTest, DecimalToHexadecimal) {
    Test_Con System_Converter;
    std::string x = "46";
    std::string y = "156";
    std::string z = "6843";

    EXPECT_EQ(System_Converter.DecimalToHexadecimal(x), "2E");

    EXPECT_EQ(System_Converter.DecimalToHexadecimal(y), "9C");

    EXPECT_EQ(System_Converter.DecimalToHexadecimal(z), "1ABB");

}

TEST(ConversionsTest, HexadecimalToDecimal) {
    Test_Con System_Converter;
    std::string x = "4EE";
    std::string y = "7CA";
    std::string z = "CCC";

    EXPECT_EQ(System_Converter.HexadecimalToDecimal(x), "1262");

    EXPECT_EQ(System_Converter.HexadecimalToDecimal(y), "1994");

    EXPECT_EQ(System_Converter.HexadecimalToDecimal(z), "3276");

}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}