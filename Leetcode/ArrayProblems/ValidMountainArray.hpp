#pragma once
#include <vector>

// https://leetcode.com/problems/valid-mountain-array/

// Given an array of integers arr, return true if and only if it is a valid
// mountain array.

// Input: arr = [2, 1]
// Output : false

// Input: arr = [3, 5, 5]
// Output : false

// Input: arr = [0, 3, 2, 1]
// Output : true

class Solution {

public:

    // Time Complexity: O(n)
    // Space Complexity: O(1)
    // https://leetcode.com/problems/valid-mountain-array/discuss/451553/C%2B%2B-Simple-Solution-with-Explanations-for-newbies-less3

    bool validMountainArray(std::vector<int>& arr) {

        if (arr.size() < 3) {
            return false;
        }

        int mountain_stepper = 1;

        while (mountain_stepper < arr.size() && arr[mountain_stepper] > arr[mountain_stepper - 1]) {
            // Increment the mountain stepper as long as the array is increasing
            mountain_stepper++;
        }

        // If our mountain stepper equals the size of the array, we are only
        // increasing:
        if (mountain_stepper == arr.size()) {
            return false;
        }

        // If the mountain stepper still equals one, it means our 2nd number
        // (index 1) is not increasing
        if (mountain_stepper == 1) {
            return false;
        }

        while (mountain_stepper < arr.size() && arr[mountain_stepper] < arr[mountain_stepper - 1]) {
            // Increment the mountain stepper as long as the array is decreasing
            mountain_stepper++;
        }

        // If the mountain stepper is equal to the length of the array,
        // it means that we have successfully increased and then decreased
        // the entire length without stopping
        return mountain_stepper == arr.size();

    }
};