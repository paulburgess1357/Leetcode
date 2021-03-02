#pragma once
#include <vector>
#include <unordered_set>
#include <limits.h>

// https://leetcode.com/problems/third-maximum-number/

// Given integer array nums, return the third maximum number in this array.
// If the third maximum does not exist, return the maximum number.

// Input: nums = [3, 2, 1]
// Output : 1
// Explanation : The third maximum is 1.

// Input: nums = [1, 2]
// Output : 2
// Explanation : The third maximum does not exist, so the maximum(2) is returned instead.

// Input: nums = [2, 2, 3, 1]
// Output : 1
// Explanation : Note that the third maximum here means the third maximum distinct number.
// Both numbers with value 2 are both considered as second maximum.

class Solution{
	
public:

	// Time Complexity: O(n)
	// Space Complexity: O(1)
	
	int thirdMax(std::vector<int>& nums){

		// Convert nums into unordered set
		std::unordered_set<int> nums_set;
		for(const auto & val : nums){
			nums_set.insert(val);
		}

		// Handle edge case where 3rd max does not exist (return max instead)
		if(nums_set.size() < 3){
			return get_max(nums_set);
		}

		// Iterate over set and remove max twice
		for(int i = 0; i < 2; i++){
			nums_set.erase(get_max(nums_set));
		}

		// Now that both max set values have been removed, we can return the
		// 3rd max set value:
		return get_max(nums_set);
		
	}

	static int get_max(std::unordered_set<int>& nums_set){
		int max = INT_MIN;
		for (const auto& val : nums_set) {
			if (val > max) {
				max = val;
			}
		}
		return max;
	}
	
};