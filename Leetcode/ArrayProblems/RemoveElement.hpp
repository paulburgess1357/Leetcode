#pragma once
#include <vector>

// https://leetcode.com/problems/remove-element/

// Given an array 'nums' and a value 'val', remove all instances of that value
// in - place and return the new length.  Do not allocate extra space for
// another array, you must do this by modifying the input array in -
// place with O(1) extra memory.  The order of elements can be changed. It
// doesn't matter what you leave beyond the new length.

// Input: nums = [3, 2, 2, 3], val = 3
// Output : 2, nums = [2, 2]
// Explanation : Your function should return length = 2, with the first two
// elements of nums being 2.
// It doesn't matter what you leave beyond the returned length. For example if
// you return 2 with nums = [2,2,3,3] or nums = [2,2,0,0],
// your answer will be accepted.

// Input: nums = [0, 1, 2, 2, 3, 0, 4, 2], val = 2
// Output : 5, nums = [0, 1, 4, 0, 3]
// Explanation : Your function should return length = 5, with the first five
// elements of nums containing 0, 1, 3, 0, and 4.
// Note that the order of those five elements can be arbitrary. It doesn't
// matter what values are set beyond the returned length.

class Solution {

public:

    // Leetcode Posted Solution
    // Two index approach
    // Time Complexity: O(n)
    // Space Complexity: O(1)

    int removeElement(std::vector<int>& nums, int val) {

        // When the value at (i) = val, we skip overwriting the
        // array.  i is incremented and we move onto the next element.
        // If that next element != val, we write it in the 'write_idx'
        // location.  This continues until all elements have been examined.
        // The end of the array will contain extra values we don't need anymore.

        int write_idx = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums.at(i) != val) {
                nums.at(write_idx) = nums.at(i);
                write_idx++;
            }
        }

        // We return write_idx.  This is the number of 'valid' elements in the
        // final array.  E.g. [3, 3] -> two valid elements
        // Note that the array above is edited in place.
        return write_idx;
    }

    // Leetcode Posted Solution
    // More efficient approach
    // Time Complexity: O(n)
    // Space Complexity: O(1)

    // This is more efficient when elements to remove are sparse
    // This approach takes the last element in the array and swaps it with the
    // element to dispose of

    // Note that this works even if it was an array like so: [8, 7, 7]
    // say val = 7.  The write_idx will be the value 1, so only the first
    // part of the array is used (assuming the user uses the returned value)
    // The 1 means there is 1 valid element.

    int removeElement_ex2(std::vector<int>& nums, int val) {
        int write_idx = 0;
        int read_idx = nums.size();

        while (write_idx < read_idx) {

            if (nums.at(write_idx) == val) {
                nums.at(write_idx) = nums.at(read_idx - 1);
                read_idx--;
            } else {
                write_idx++;
            }
        }
        return write_idx;
    }

};