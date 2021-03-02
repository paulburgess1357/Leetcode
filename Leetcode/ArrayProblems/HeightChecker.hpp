#pragma once
#include <vector>
#include <algorithm>

// https://leetcode.com/problems/height-checker/

// Students are asked to stand in non - decreasing order of heights for an
// annual photo.
// Return the minimum number of students that must move in order for all
// students to be standing in non - decreasing order of height.

// Input: heights = [1, 1, 4, 2, 1, 3]
// Output : 3
// Explanation :
// 3 students are out of place:
//	Current array : [1, 1, 4, 2, 1, 3]
//	Target array :  [1, 1, 1, 2, 3, 4]

class Solution {

public:

	// Time Complexity: O(n log(n))
	// Space Complexity: O(log n)

	int heightChecker(std::vector<int>& heights) {

		std::vector<int> heights_sorted = heights;
		std::sort(heights.begin(), heights.end());

		int move_count = 0;
		for (int i = 0; i < heights.size(); i++) {

			if (heights_sorted[i] != heights[i]) {
				move_count++;
			}
		}

		return move_count;
	}

};