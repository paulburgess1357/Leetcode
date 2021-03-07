#pragma once
#include <vector>
#include <limits>

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

// You are given an array prices where prices[i] is the price of a given stock
// on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock and
// choosing a different day in the future to sell that stock.

// Return the maximum profit you can achieve from this transaction.
// If you cannot achieve any profit, return 0

// Input: prices = [7, 1, 5, 3, 6, 4]
// Output : 5
// Explanation : Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6 - 1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

// Input: prices = [7, 6, 4, 3, 1]
// Output : 0
// Explanation : In this case, no transactions are doneand the max profit = 0.

class Solution {
	
public:

    // Time Complexity: O(n^2)
    // Space Complexity: O(1)

    int maxProfit(std::vector<int>& prices) {

        int max_profit = 0;
        for (int i = 0; i < prices.size(); i++) {
            for (int j = i + 1; j < prices.size(); j++) {
                if (prices[j] - prices[i] > max_profit) {
                    max_profit = prices[j] - prices[i];
                }
            }
        }

        return max_profit;

    }

    // Time Complexity: O(n)
    // Space Complexity: (1)
    // Leetcode Posted Solution

    int maxProfit_ex2(std::vector<int>& prices) {

        int lowest_price = INT_MAX;
        int max_profit = 0;

        for (int i = 0; i < prices.size(); i++) {
            
            if (prices[i] < lowest_price) {
                // Set lowest price encountered:
                lowest_price = prices[i];
            } else{
                // Set max profit based on current price:
                max_profit = std::max(max_profit, prices[i] - lowest_price);
            }
            
        }

        return max_profit;

    }


};