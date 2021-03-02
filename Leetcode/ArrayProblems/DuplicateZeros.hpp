#pragma once
#include <vector>

// https://leetcode.com/problems/duplicate-zeros/

// Given a fixed length array arr of integers, duplicate each occurrence of zero,
// shifting the remaining elements to the right.
// Note that elements beyond the length of the original array are not written.
// Do the above modifications to the input array in place, do not return anything
// from your function.

// Input: [1, 0, 2, 3, 0, 4, 5, 0]
// Output : null
// Explanation : After calling your function, the input array is modified to :
// [1, 0, 0, 2, 3, 0, 0, 4]

// Input: [1, 2, 3]
// Output : null
// Explanation : After calling your function, the input array is modified to : [1, 2, 3]

// 1 <= arr.length <= 10000
// 0 <= arr[i] <= 9

class Solution {

public:

    // Time Complexity: O(n^2)
    // Space Complexity: O(1)

    void duplicateZeros(std::vector<int>& arr) {

        for (int i = 0; i < arr.size(); i++) {

            // If current element == 0, move all the next elements to the right
            if (arr.at(i) == 0) {

                // Note that we start from the back this time
                // This will also copy over the existing 0
                for (int j = arr.size() - 1; j > i; j--) {
                    arr.at(j) = arr.at(j - 1);
                }

                // Increment i to 'skip' over the zero we just placed
                // (So i gets incremented twice; Both here and from the loop)
                i++;
            }

        }

    }
};