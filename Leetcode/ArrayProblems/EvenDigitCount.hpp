#pragma once
#include <vector>

// https://leetcode.com/problems/find-numbers-with-even-number-of-digits/

// Given an array nums of integers, return how many of them contain an even
// number of digits.

// Input: nums = [12, 345, 2, 6, 7896]
// Output : 2
// Explanation :
//	12 contains 2 digits(even number of digits).
//	345 contains 3 digits(odd number of digits).
//	2 contains 1 digit(odd number of digits).
//	6 contains 1 digit(odd number of digits).
//	7896 contains 4 digits(even number of digits).
//	Therefore only 12 and 7896 contain an even number of digits.

class Solution {
	
public:

    // Time Complexity: O(n)
	// Space Complexity: O(1)
	
    int findNumbers(std::vector<int>& nums) {

        int even_digit_count = 0;
        for(const auto& val : nums){
            if(isEven(digitCount(val))){
                even_digit_count++;
            }        	
        }
    	
        return even_digit_count;
    }
	
private:
	
	// This works due to integer division
	int digitCount(int num){
		int count = 0;
    	while(num != 0){
            num = num / 10;
            count++;
    	}
        return count;
	}

    bool isEven(int num){
        return num % 2 == 0;
	}
};