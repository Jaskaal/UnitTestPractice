/**
 * Unit Tests for Practice class
**/

#include <gtest/gtest.h>
#include "Practice.h"

class PracticeTest : public ::testing::Test {
	protected:
		PracticeTest(){} //constructor runs before each test
		virtual ~PracticeTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

/*
	Palindrome tests
	================
	- Standard usage
	- Symbolic characters
	- Non-standard edge cases
*/

//STD tests
TEST(PracticeTest, is_simple_palindrome) {
    Practice obj;
    bool actual = obj.isPalindrome("aaa");
    ASSERT_TRUE(actual);
}
TEST(PracticeTest, is_simple_false_palindrome) {
    Practice obj;
    bool actual = obj.isPalindrome("thisisatestnoneedtobealarmed");
    ASSERT_FALSE(actual);
}

//True Symbol tests -- Non-AZ characters
TEST(PracticeTest, is_symbol_palindrome) {
    Practice obj;
    bool actual = obj.isPalindrome("X/|/!|!/|/X");
    ASSERT_TRUE(actual);
}
TEST(PracticeTest, is_numerical_palindrome) {
    Practice obj;
    bool actual = obj.isPalindrome("111");
    ASSERT_TRUE(actual);
}

//False Symbol tests -- Non-AZ characters
TEST(PracticeTest, is_symbol_false_palindrome) {
    Practice obj;
    bool actual = obj.isPalindrome("-#!$");
    ASSERT_FALSE(actual);
}
TEST(PracticeTest, is_space_palindrome) {
    Practice obj;
    bool actual = obj.isPalindrome("   ");
    ASSERT_TRUE(actual);
}

// Edge cases
TEST(PracticeTest, is_empty_str_palindrome) {
    Practice obj;
    bool actual = obj.isPalindrome("");
    ASSERT_TRUE(actual);
}
TEST(PracticeTest, is_diff_case_palindrome) {
    Practice obj;
    bool actual = obj.isPalindrome("dBdBd");
    ASSERT_TRUE(actual);
}
TEST(PracticeTest, is_null_palindrome) {
    Practice obj;
    bool actual = obj.isPalindrome("\0");
    ASSERT_TRUE(actual);
}
/*  
	This is "working" for now because logically
	the function receives a string deliminated
	by the null-terminator, meaning that unless
	there's a reason there's no need to bother
	checking for malformed strings with data past
	the terminator
*/
TEST(PracticeTest, is_bad_comp_palindrome) {
    Practice obj;
    bool actual = obj.isPalindrome("\0anna");
    ASSERT_TRUE(actual);
}

/*
Decsending Order tests
======================
- Standard usage (IE: Each type of order from sorting as well as no sorting)
- Non-standard edge cases (IE: Negatives, large numbers, etc.)
*/

//STD tests
TEST(PracticeTest, simple_sort_first_order) {
    Practice obj;
    int first = 5, second = 7, third = 4;
    obj.sortDescending(first, second, third);
    ASSERT_EQ(first, 7);
    ASSERT_EQ(second, 5);
    ASSERT_EQ(third, 4);
}
TEST(PracticeTest, simple_sort_second_order) {
    Practice obj;
    int first = 7, second = 58, third = 45;
    obj.sortDescending(first, second, third);
    ASSERT_EQ(first, 58);
    ASSERT_EQ(second, 45);
    ASSERT_EQ(third, 7);
}
TEST(PracticeTest, simple_sort_third_order) {
    Practice obj;
    int first = 7, second = 58, third = 145;
    obj.sortDescending(first, second, third);
    ASSERT_EQ(first, 145);
    ASSERT_EQ(second, 58);
    ASSERT_EQ(third, 7);
}
TEST(PracticeTest, simple_reverse_order) {
    Practice obj;
    int first = 100, second = 50, third = 10;
    obj.sortDescending(first, second, third);
    ASSERT_EQ(first, 100);
    ASSERT_EQ(second, 50);
    ASSERT_EQ(third, 10);
}
TEST(PracticeTest, no_sorting_needed) {
    Practice obj;
    int first = 117, second = 58, third = 14;
    obj.sortDescending(first, second, third);
    ASSERT_EQ(first, 117);
    ASSERT_EQ(second, 58);
    ASSERT_EQ(third, 14);
}
TEST(PracticeTest, mixed_sign_sort) {
    Practice obj;
    int first = -3, second = 122, third = -23;
    obj.sortDescending(first, second, third);
    ASSERT_EQ(first, 122);
    ASSERT_EQ(second, -3);
    ASSERT_EQ(third, -23);
}

// Non-standard cases
TEST(PracticeTest, large_sort) {
    Practice obj;
    int first = 7222217, second = 5111118, third = 3123245;
    obj.sortDescending(first, second, third);
    ASSERT_EQ(first, 7222217);
    ASSERT_EQ(second, 5111118);
    ASSERT_EQ(third, 3123245);
}
TEST(PracticeTest, equal_sort) {
    Practice obj;
    int first = 0, second = 0, third = 0;
    obj.sortDescending(first, second, third);
    ASSERT_EQ(first, 0);
    ASSERT_EQ(second, 0);
    ASSERT_EQ(third, 0);
}
TEST(PracticeTest, negative_num_sort) {
    Practice obj;
    int first = -3, second = -13, third = -23;
    obj.sortDescending(first, second, third);
    ASSERT_EQ(first, -3);
    ASSERT_EQ(second, -13);
    ASSERT_EQ(third, -23);
}
TEST(PracticeTest, negativeEQ_sort) {
    Practice obj;
    int first = -3, second = -3, third = -3;
    obj.sortDescending(first, second, third);
    ASSERT_EQ(first, -3);
    ASSERT_EQ(second, -3);
    ASSERT_EQ(third, -3);
}
