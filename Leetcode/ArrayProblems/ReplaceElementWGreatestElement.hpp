#pragma once
#include <vector>

// https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/

// Given an array arr, replace every element in that array with the greatest
// element among the elements to its right, and replace the last element with - 1.

// Input: arr = [17, 18, 5, 4, 6, 1]
// Output : [18, 6, 6, 6, 1, -1]
// Explanation :
//	- index 0 -- > the greatest element to the right of index 0 is index 1 (18).
//	- index 1 -- > the greatest element to the right of index 1 is index 4 (6).
//	- index 2 -- > the greatest element to the right of index 2 is index 4 (6).
//	- index 3 -- > the greatest element to the right of index 3 is index 4 (6).
//	- index 4 -- > the greatest element to the right of index 4 is index 5 (1).
//	- index 5 -- > there are no elements to the right of index 5, so we put - 1.

// Input: arr = [400]
// Output : [-1]
// Explanation : There are no elements to the right of index 0.

class Solution {

public:

    // Time Complexity: O(n)
    // Space Complexity: O(1)
    // https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/discuss/799052/easy-c%2B%2B-solution-O(n)faster-than-99.44

    std::vector<int> replaceElements(std::vector<int>& arr) {

        int max_val = -1;

        // Start loop from the back of the array
        for (int i = arr.size() - 1; i >= 0; i--) {
            int current_val = arr[i];

            // Store max val encountered so far
            arr[i] = max_val;

            // Update max value to be 'max' of what we have encountered
            max_val = std::max(max_val, current_val);
        }
        return arr;
    }

};