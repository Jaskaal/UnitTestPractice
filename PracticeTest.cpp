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
	- Standard usage
	- Non-standard edge cases
*/

//STD tests
TEST(PracticeTest, simple_sort) {
    Practice obj;
	int first = 7, second = 58, third = 45;
    obj.sortDescending(first, second, third);
    ASSERT_EQ(first, 58);
}
TEST(PracticeTest, simple_large_sort) {
    Practice obj;
	int first = 7222217, second = 5111118, third = 3123245;
    obj.sortDescending(first, second, third);
    ASSERT_EQ(first, 7222217);
}
TEST(PracticeTest, equal_sort) {
    Practice obj;
	int first = 0, second = 0, third = 0;
    obj.sortDescending(first, second, third);
    ASSERT_EQ(first, 0);
}