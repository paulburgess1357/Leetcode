#pragma once
#include <vector>
#include <algorithm>

// https://leetcode.com/problems/merge-sorted-array/

// Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as
// one sorted array.
// The number of elements initialized in nums1 and nums2 are m and n respectively.
// You may assume that nums1 has a size equal to m + n such that it has enough
// space to hold additional elements from nums2.

// Input: nums1 = [1, 2, 3, 0, 0, 0], m = 3, nums2 = [2, 5, 6], n = 3
// Output : [1, 2, 2, 3, 5, 6]

// Input : nums1 = [1], m = 1, nums2 = [], n = 0
// Output : [1]

class Solution {

public:
    // Leetcode Posted Solution 1
    // Time Complexity: O(n log(n))
    // Space Complexity: O(log n)

    void merge_ex1(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {

        // Place nums2 items into nums1
        for (int i = 0; i < nums2.size(); i++) {
            nums1.at(m + i) = nums2.at(i);
        }

        // Sort nums1
        std::sort(nums1.begin(), nums1.end());
    }


    // Leetcode Posted Solution 2
    // Time complexity: O(n).
    // Space complexity: O(n).

    void merge_ex2(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {

        // Detailed Solution
        // https://leetcode.com/problems/merge-sorted-array/discuss/600243/C%2B%2B-solution-O(m%2Bn)-solution-with-detailed-explanation.

        // Solve the solution doing a reverse sorting (placing large elements
        // at the back of nums1)

        // All idx variables start from the back
        int nums1_write_idx = m + n - 1;
        int nums1_read_idx = m - 1;
        int nums2_read_idx = n - 1;

        while (nums1_read_idx >= 0 && nums2_read_idx >= 0) {

            const int num1_val = nums1.at(nums1_read_idx);
            const int num2_val = nums2.at(nums2_read_idx);

            // Comparison Write
            if (num1_val > num2_val) {
                nums1.at(nums1_write_idx) = num1_val;
                nums1_write_idx--;
                nums1_read_idx--;
            } else {
                nums1.at(nums1_write_idx) = num2_val;
                nums1_write_idx--;
                nums2_read_idx--;
            }

        }

        // Only one of the remainder loops below will run once the
        // above while loop finishes.

        // Write any remainders for values left in nums1
        while (nums1_read_idx >= 0) {
            nums1.at(nums1_write_idx) = nums1.at(nums1_read_idx);
            nums1_write_idx--;
            nums1_read_idx--;
        }

        // Write any remainders for values left in nums2
        while (nums2_read_idx >= 0) {
            nums1.at(nums1_write_idx) = nums2.at(nums2_read_idx);
            nums1_write_idx--;
            nums2_read_idx--;
        }

    }
};