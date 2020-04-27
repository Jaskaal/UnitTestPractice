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