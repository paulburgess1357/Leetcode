#pragma once
#include <vector>

// https://leetcode.com/problems/check-if-n-and-its-double-exist/

// Given an array arr of integers, check if there exists two integers N and M
// such that N is the double of M ( i.e. N = 2 * M).

// Input: arr = [10, 2, 5, 3]
// Output : true
// Explanation : N = 10 is the double of M = 5, that is, 10 = 2 * 5.

// Input: arr = [7, 1, 14, 11]
// Output : true
// Explanation : N = 14 is the double of M = 7, that is, 14 = 2 * 7.

// Input: arr = [3, 1, 7, 11]
// Output : false
// Explanation : In this case does not exist N and M, such that N = 2 * M.

class Solution {

public:

    // Time Complexity: O(n^2)
    // Space Complexity O(1)

    bool checkIfExist(std::vector<int>& arr) {

        for (int i = 0; i < arr.size(); i++) {

            const int current_val = arr[i];
            const int double_val = current_val * 2;

            for (int j = 0; j < arr.size(); j++) {

                if (j == i) {
                    continue;
                }

                if (arr[j] == double_val) {
                    return true;
                }
            }

        }

        return false;
    }
};