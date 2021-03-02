#pragma once
#include <vector>

// https://leetcode.com/problems/sort-array-by-parity/

// Given an array A of non - negative integers, return an array consisting of
// all the even elements of A, followed by all the odd elements of A.
// You may return any answer array that satisfies this condition.

// Input: [3, 1, 2, 4]
// Output : [2, 4, 3, 1]
// The outputs[4, 2, 3, 1], [2, 4, 1, 3], and [4, 2, 1, 3] would also be accepted.

class Solution {
	
public:
	
	// In place solution:
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    // https://leetcode.com/problems/sort-array-by-parity/discuss/170760/Very-simple-C%2B%2BPythonJava-O(n)-soln-(Avoid-in-place-swapping-as-the-input-is-passed-as-reference)
	
    std::vector<int> sortArrayByParity(std::vector<int>& array) {

        int right_idx = array.size() - 1;
        int left_idx = 0;

    	while(left_idx < right_idx){

            if(is_odd(array[left_idx])){
            	// Left value is odd.  We replace the left value with the far
            	// right value.  This 'sorts' the odd value to the back.  We
            	// then increment the right index to move left one slot.
                std::swap(array[left_idx], array[right_idx]);
                right_idx--;
            } else{
            	// Left value is even so we increment to the next array value
                left_idx++;
            }    		
    	}

        return array;
    }

	bool is_odd(int val){
        return val % 2 != 0;
    }
};