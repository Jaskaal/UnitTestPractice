#include "Practice.h"
#include <string>

using std::string;

// Basic Xor-Swapping for integer types using addresses;
//
// Uses if-statement to check for address of arugments
// being the same before a swap occurs
void xs(int *x, int *y) {if (x != y) {*x ^= *y ^= *x ^= *y;}}

// Receive three integers and rearrange their values so that they are in
// descending order from greatest (first) to least (third)
void Practice::sortDescending(int & first, int & second, int & third) {
	
	// Check validity of each integer specifically and 
	// assign that validity to a boolean used as the 
	// if-condition for swapping them with xs()
	bool f,s,t;
	while((f = first < second) || (s = second < third) || (t = first < third)) {
		if(f) {xs(&first, &second);}
		if(s) {xs(&second, &third);}
		if(t) {xs(&first, &third);}
	}
}

// Receive a string and return whether or not it is strictly a palindrome,
// where it is spelled the same backwards and forwards when considering every
// character in the string, but disregarding case ('x' is the same as 'X')
bool Practice::isPalindrome(string input) {
	for(int i = 0; i < (int)input.size(); i++) {
		if( input[i] >= 'a' && input[i] <= 'z' ) {
			input[i] = input[i] - ('a' - 'A');
		}
	}
	
	// Check each 2 sets of characters for up
	// to halfway up the string's size()
	for(int i = 0; i < (int)input.size()/2; i++) {
		if( input[i] != input[input.size()-1-i] ) {
			return false;
		}
	}
	return true;
}