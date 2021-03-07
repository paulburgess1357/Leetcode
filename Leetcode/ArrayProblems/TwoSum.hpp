#pragma once
#include <vector>
#include <unordered_map>

// https://leetcode.com/problems/two-sum/

// Given an array of integers nums and an integer target, return indices of the two
// numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not
// use the same element twice.
// You can return the answer in any order.

// Input: nums = [2, 7, 11, 15], target = 9
// Output : [0, 1]
// Output : Because nums[0] + nums[1] == 9, we return[0, 1].

// Input: nums = [3, 2, 4], target = 6
// Output : [1, 2]

// Input: nums = [3, 3], target = 6
// Output : [0, 1]

class Solution {

public:

    // Time Complexity: O(n^2)
    // Space Complexity: O(1)

    std::vector<int> twoSum(const std::vector<int>& numbers, const int target) {

        std::vector<int> result;
        for (int i = 0; i < numbers.size(); i++) {
            int desired_number = target - numbers[i];
            for (int j = i + 1; j < numbers.size(); j++) {
                if (numbers[j] == desired_number) {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        return result;

    }

    // Time Compexity O(n)
    // Space Complexity: O(n)
    // Hash Table

    std::vector<int> twoSum_ex2(const std::vector<int>& numbers, const int target) {

        std::vector<int> results;

        // Fill hash table and look up the number (target - nums[i] = number_to_find)
        // <number, index>    	
        std::unordered_map<int, int> hash_table;
        for (int i = 0; i < numbers.size(); i++) {

            // Search for remaining number
            int number_to_find = target - numbers[i];
            std::unordered_map<int, int>::const_iterator it = hash_table.find(number_to_find);

            if (it != hash_table.end()) {
                results.push_back(i);
                results.push_back(it->second);
                return results;
            }

            // Fill Hash Table
            // This must be after the search above.  The reason is because
            // if we had the input [3, 2, 4] with a target of 6,
            // the correct answer is index 1 and index 2.  However, if we
            // fill the hash table first then search, we will return
            // index 0 and index 0 (3 + 3)
            hash_table[numbers[i]] = i;

        }

        return results;
    }

};
