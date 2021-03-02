#pragma once
#include <vector>

// https://leetcode.com/problems/max-consecutive-ones/

// Given a binary array, find the maximum number of consecutive 1s in this
// array if you can flip at most one 0.

// Input: [1, 0, 1, 1, 0]
// Output : 4
// Explanation : Flip the first zero will get the maximum number of consecutive 1s.
// After flipping, the maximum number of consecutive 1s is 4.

class Solution {
	
public:

    // Time Complexity: O(n^2)
	// Space Complexity: O(1)
	
    int findMaxConsecutiveOnes(std::vector<int>& nums) {

        // Length vector of 1 will always have a result of 1:
    	// [1]
    	// [0] -> flipped to [1]
    	if(nums.size() == 1){
            return 1;
    	}
    	
        int final_result = 0;
        int all_ones_check = 0;
    	
        // Locate zeros:
    	for(int i = 0; i < nums.size(); i++){

            if(nums[i] == 0){

            	// Iterate and sum the left consecutive one's
                int left_count = 0;
            	for(int left = i - 1; left >=0; left--){

            		// Stop if we encounter another zero
            		if(nums[left] == 0){
                        break;
            		}
                    left_count++;
            		
            	}

            	// Iterate and sum the right consecutive one's
                int right_count = 0;
            	for(int right = i + 1; right < nums.size(); right++){

            		// Stop if we encounter another zero
                    if(nums[right] == 0){
                        break;
                    }

                    right_count++;
            	}

            	// Sum the left + right consecutive ones
                // + 1 because we can 'flip' the zero
                final_result = std::max(final_result, left_count + right_count + 1); 
            	
            } else {
                all_ones_check++;
            }    		
    	}

        // Handle array of all 1's
        if (all_ones_check == nums.size()) {
            return all_ones_check;
        }
    	    	
        return final_result;
    	
    }
};