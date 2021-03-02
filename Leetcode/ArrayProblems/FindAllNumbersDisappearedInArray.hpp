#pragma once
#include <vector>
#include <unordered_map>

// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

// Given an array of integers where 1 ≤ a[i] ≤ n(n = size of array), some
// elements appear twice and others appear once.
// Find all the elements of[1, n] inclusive that do not appear in this array.
// Could you do it without extra space and in O(n) runtime?
// You may assume the returned list does not count as extra space.

// Input:
// [4, 3, 2, 7, 8, 2, 3, 1]
//
// Output :
// [5, 6]

// 1 <= a[i] <= n
// This is key to the 2nd solution (no extra space) - Positive Number
// This is also key because we know the max value in the array is <= the size
// of the array

class Solution {

public:

    // Using Extra Space Solution
    // Time Complexity: O(n)
    // Space Complexity: O(n)

    std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {

        // <Number, Count>
        std::unordered_map<int, int> nums_map;
        for (int i = 1; i <= nums.size(); i++) {
            nums_map[i] = 0;
        }

        // Count Values
        for (const auto& val : nums) {
            if (nums_map.find(val) != nums_map.end()) {
                nums_map[val]++;
            }
        }

        // Create vector and store values that have a count of zero
        std::vector<int> result;
        for (auto it : nums_map) {
            if (it.second == 0) {
                result.push_back(it.first);
            }
        }

        return result;

    }

    // Altering the input array but NOT allocating
    // https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/discuss/375581/C%2B%2B-easy-to-understand-comments-(negate-seen-elements)

    // Time Complexity: O(n)
    // Space Complexity: O(1)

    // The idea is to use the input array to 'mark' seen values
    // For example: [3, 2, 5, 6, 3, 3]:
    // The first loop over the values returns a 3.  Lets flag that we
    // have found a 3 using the original array.  We can do this by making the
    // 3rd element negative (remember, our input values are only positive)
    // [3, 2, -5, 6, 3, 3]
    //         ^ -----> The negative sign here tells us we have a '3' in our data.
    //         This is because its the 3rd index location

    std::vector<int> findDisappearedNumbers_ex2(std::vector<int>& nums) {

        // Iterate over the array and flag seen values as negative
        for (int i = 0; i < nums.size(); i++) {

            // Minus 1 because we don't want to go out of range of our array (1 <= a[i] <= n)
            // E.g. if we see a 3, we flag the 3rd index location which is 2 (arr[2])
            const int index_to_make_negative = abs(nums[i]) - 1;

            if (nums[index_to_make_negative] > 0) {
                nums[index_to_make_negative] *= -1;
            }

        }

        // Remember, if we have seen a value, the INDEX will be negative.  For
        // example, if we have seen a 5 ANYWHERE in our array, the index at the
        // 5th position (nums[4]) will be negative.  We don't care about the
        // value anymore.  We only care about the sign.  If a sign is positive,
        // it means that we have NOT found that index location value.

        std::vector<int> results;
        for (int i = 0; i < nums.size(); i++) {

            // Check sign:
            if (nums[i] > 0) {
                // If the value is positive, it means we have not seen the value
                // The + 1 is necessary.For example, if we flag the 3rd position
                // as negative(from the above loop), we would have[3, 2, -5, 1, 1].
                // This occurs at the 2nd index, but the value that triggered it was a 3.
                results.push_back(i + 1);
            }

        }

        return results;
    }
};