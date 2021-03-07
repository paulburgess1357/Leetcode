#pragma once
#include <string>
#include <vector>
#include <algorithm>

// In an alien language, surprisingly they also use english lowercase letters,
// but possibly in a different order.The order of the alphabet is some
// permutation of lowercase letters.

// Given a sequence of words written in the alien language, and the order of the
// alphabet, return true ifand only if the given words are sorted lexicographicaly
// in this alien language.

// Input: words = ["hello", "leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
// Output : true
// Explanation : As 'h' comes before 'l' in this language, then the sequence is sorted.

// Input: words = ["word", "world", "row"], order = "worldabcefghijkmnpqstuvxyz"
// Output : false
// Explanation : As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.

// All characters in words[i] and order are English lowercase letters.

class Solution {

public:

    // Time Complexity O(c), where 'c' is the total content of words
    // Space Complexity: O(1)

    // Discussion Board Answer:
    // https://leetcode.com/problems/verifying-an-alien-dictionary/discuss/203185/JavaC%2B%2BPython-Mapping-to-Normal-Order

    bool isAlienSorted(std::vector<std::string>& words, const std::string& order) {

        // -------- Step 1:    	
        // In order to test if the words are sorted properly, we need to make
        // an index to be able to check the correct order of the letters.

        // Create empty vector with 26 slots filled with 0's
        std::vector<int> letter_index(26, 0);

    	// Create index
        for (int i = 0; i < order.size(); i++) {
            int location = order[i] - 'a';
            letter_index[location] = i;
        }

        // We create a vector of integers to 'store' this order.  We also
        // need to scale the values to be between 0 and 25 (26 letters total)
        // See Ascii table lowercase values for the following:

        // For example: order = "rsatpz" (imagine this extends to 26 total letters)
        // 'r' - 'a' = 17 ---> insert value will be 1 because this letter is first
        // 's' - 'a' = 18 ---> insert value will be 2 because this letter is second
        // 'a' - 'a' = 0  ---> insert value will be a 3 because this letter is third
        // 't' - 'a' = 19 ---> etc
        // 'p' - 'a' = 15 ---> etc
        // 'z' = 'a' = 25 ---> etc

        // We locate the index location of each value and store its location in
        // supplied order.
        // Array:    	
        // [,,,,,,,,,,,,,,,,,,,,,,,,,]

        // Working through the above character subtraction values:

        // Letter r
        // Locate location 17 and insert a 1.  This is the letter that comes first
        // [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25]
        // [ , , , , , , , , , ,  ,  ,  ,  ,  ,  ,  , 1,  ,  ,  ,  ,  ,  ,  ,  ]

        // Letter s
        // Locate location 18 and insert a 2
        // [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25]
        // [ , , , , , , , , , ,  ,  ,  ,  ,  ,  ,  , 1, 2,  ,  ,  ,  ,  ,  ,  ]

        // Letter a
        // Locate location 0 and insert a 3:
        // [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25]
        // [3, , , , , , , , , ,  ,  ,  ,  ,  ,  ,  , 1, 2,  ,  ,  ,  ,  ,  ,  ]

        // Letter t
        // Locate location 19 and insert a 4:
        // [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25]
        // [3, , , , , , , , , ,  ,  ,  ,  ,  ,  ,  , 1, 2, 4,  ,  ,  ,  ,  ,  ]

        // This vector of integers allows us to compare two letters to determine
        // if one letter should come before the other.  Using the example
        // above, the letter 'r' (value of 1; slot 17) comes before the
        // letter 'a' (value of 3; slot 0).  

        // -------- Step 2:
        // Next we can iterate of each letter in each word.  For each character,
        // we can create the same transformation as above.  We will recode
        // (in place) each character in the word.

        // For example: 
        // If we have the word "tiny". We need to find where 't' is in our
        // index above.  Looking at the index we created, we can see that 't'
        // ('t' - 'a' = 19) is in slot 19.  At slot 19, we see that the letter
        // 't' has a value of 4.  This means that there are 3 letters that come
        // before 't' based on our alien alphabet ordering.  We then simply
        // recode the letter 't' (ascii value of 116) as 4.  This will allow
        // us to use the is_sorted function on the vector!

        for (auto& word : words) {
            for (auto& character : word) {
                // Overwrite the exiting character value
                character = letter_index[character - 'a'];
            }
        }

        // -------- Step 3:
        // Lastly, all we have to do is check if the vector is sorted!
        return std::is_sorted(words.begin(), words.end());

    }
};