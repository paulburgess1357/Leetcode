#pragma once
#include <vector>

// https://leetcode.com/problems/remove-duplicates-from-sorted-array/solution/

// Given a sorted array nums, remove the duplicates in - place such that each
// element appears only once and returns the new length.
// Do not allocate extra space for another array, you must do this by modifying
// the input array in - place with O(1) extra memory.

// Input: nums = [1, 1, 2]
// Output : 2, nums = [1, 2]
// Explanation : Your function should return length = 2, with the first two
// elements of nums being 1 and 2 respectively.It doesn't matter what you leave
// beyond the returned length.

// Input: nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]
// Output : 5, nums = [0, 1, 2, 3, 4]
// Explanation : Your function should return length = 5, with the first five
// elements of nums being modified to 0, 1, 2, 3, and 4 respectively. It
// doesn't matter what values are set beyond the returned length.

class Solution {

public:

    // Leetcode Posted Solution
    // Time Complexity: O(n)
    // Space Complexity: O(1)

    int removeDuplicates(std::vector<int>& nums) {

        if (nums.empty()) {
            return 0;
        }

        int write_idx = 0;
        for (int read_idx = 1; read_idx < nums.size(); read_idx++) {

            if (nums[write_idx] != nums[read_idx]) {
                // increment the write_idx to the next slot.  Then write the
                // non-duplicate value.
                // You must increment to the next slot, otherwise you will
                // overwrite a previous unique value.
                write_idx++;
                nums[write_idx] = nums[read_idx];
            }

            // Do nothing.  Increment the read_idx to skip the duplicate.
            // Note that the loop is what increments it.              		
        }

        // The plus 1 indicates the number of valid elements in the updated vector
        return write_idx + 1;
    }
};