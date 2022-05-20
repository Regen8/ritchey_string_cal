#include "cs12x_test.h"
#include "string_calculator.cpp"

#include<string>
#include<sstream>
int main() {
    INIT_TEST;
    EXPECT_EQ(decimal_to_digit(0), '0');
    EXPECT_EQ(decimal_to_digit(1), '1');
    EXPECT_EQ(decimal_to_digit(2), '2');
    EXPECT_EQ(decimal_to_digit(3), '3');
    EXPECT_EQ(decimal_to_digit(4), '4');
    EXPECT_EQ(decimal_to_digit(5), '5');
    EXPECT_EQ(decimal_to_digit(6), '6');
    EXPECT_EQ(decimal_to_digit(7), '7');
    EXPECT_EQ(decimal_to_digit(8), '8');
    EXPECT_EQ(decimal_to_digit(9), '9');
    RESULT(pass);
    return pass ? 0 : 1;
}
