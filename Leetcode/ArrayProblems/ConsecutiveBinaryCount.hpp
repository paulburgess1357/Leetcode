#pragma once
#include <vector>

// https://leetcode.com/problems/max-consecutive-ones-ii/

// Given a binary array, find the maximum number of consecutive 1s in this
// array.

// Input: [1, 1, 0, 1, 1, 1]
// Output : 3
// Explanation : The first two digits or the last three digits are consecutive
// 1s.  The maximum number of consecutive 1s is 3.

// Constraints
// The input array will only contain 0 and 1.
// The length of input array is a positive integer and will not exceed 10,000

class Solution {

public:

    // Time Complexity: O(n)
    // Space Complexity: O(1)

    int findMaxConsecutiveOnes(std::vector<int>& nums) {

        int count = 0;
        int max_consecutive_count = 0;

        for (const auto& val : nums) {

            if (val == 1) {
                count += 1;

                // Get max count (this also has the benefit of handling an 
                // array of only 1's.
                max_consecutive_count = std::max(max_consecutive_count, count);
            } else {
                count = 0;
            }

        }

        return max_consecutive_count;
    }
};