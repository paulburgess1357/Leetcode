#pragma once
#include <vector>

// https://leetcode.com/problems/move-zeroes/

// Given an array nums, write a function to move all 0's to the end of it
// while maintaining the relative order of the non-zero elements.

// Input: [0, 1, 0, 3, 12]
// Output : [1, 3, 12, 0, 0]

// You must do this in - place without making a copy of the array.
// Minimize the total number of operations.

class Solution {

public:

    // Sub-Optimal Approach
    // This approach uses more space and isn't in place
    // Time Complexity: O(n)
    // Space Complexity: O(n)

    void moveZeroes(std::vector<int>& nums) {

        // Count the number of zeros:
        std::vector<int> result;
        int zero_count = 0;

        for (const auto& val : nums) {
            if (val != 0) {
                result.push_back(val);
            } else {
                zero_count++;
            }
        }

        while (zero_count > 0) {
            result.push_back(0);
            zero_count--;
        }

        nums = result;
    }

    // In-place example
    // https://leetcode.com/problems/move-zeroes/discuss/72005/My-simple-C%2B%2B-solution
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    void moveZeros_ex2(std::vector<int>& nums) {

        int write_idx = 0;
        for (int i = 0; i < nums.size(); i++) {

            // Move non-zero elements to the beginning of the vector
            if (nums[i] != 0) {
                nums[write_idx] = nums[i];
                write_idx++;
            }

        }

        // Fill in the rest of the zeros
        for (int i = write_idx; i < nums.size(); i++) {
            nums[i] = 0;
        }

    }
};