#pragma once
#include <algorithm>
#include <vector>

// https://leetcode.com/problems/squares-of-a-sorted-array/

// Given an integer array nums sorted in non-decreasing order,
// return an array of the squares of each number sorted in non-decreasing order.

// Input: nums = [-4, -1, 0, 3, 10]
// Output : [0, 1, 9, 16, 100]
// Explanation : After squaring, the array becomes[16, 1, 0, 9, 100].  After
// sorting, it becomes[0, 1, 9, 16, 100].

// Input: nums = [-7, -3, 2, 3, 11]
// Output : [4, 9, 9, 49, 121]

class Solution {

public:

    // Time Complexity: O(n log(n))
    // Space Complexity: O(log n)

    std::vector<int> sortedSquares(std::vector<int>& nums) {
        std::vector<int> squared_array;
        for (const auto& val : nums) {
            squared_array.push_back(val * val);
        }
        std::sort(squared_array.begin(), squared_array.end());
        return squared_array;
    }

    // Faster Solution
    // Leetcode Posted Solution
    // Since the array is already sorted, we can take advantage of that:

    // Time Complexity: O(N)
    // Space Complexity: O(N)

    std::vector<int> sortedSquares_ex2(std::vector<int>& nums) {

        const int nums_size = nums.size();
        std::vector<int> squared_array(nums.size());

        int left_idx = 0;
        int right_idx = nums_size - 1;

        for (int i = nums_size - 1; i >= 0; i--) {

            const int left_val = abs(nums.at(left_idx));
            const int right_val = abs(nums.at(right_idx));

            // Largest absolute values are at the ends of the array (since its sorted)
            // Values are inserted into the array starting from the end
            if (left_val < right_val) {
                squared_array.at(i) = right_val * right_val;
                right_idx--;
            } else {
                squared_array.at(i) = left_val * left_val;
                left_idx++;
            }
        }

        return squared_array;
    }
};

