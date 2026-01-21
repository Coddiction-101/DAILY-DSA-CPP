/*
 * Problem: 121. Best Time to Buy and Sell Stock (LeetCode)
 * Date: January 02, 2026
 * Difficulty: Easy
 * Topics: Arrays, Greedy, One Pass
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
 *
 * Problem Statement:
 * You are given an array prices where prices[i] is the price of a given stock on day i.
 * You want to maximize profit by:
 *   - Buying on one day
 *   - Selling on a different day in the future (selling day > buying day)
 * Return the maximum profit. If you cannot make any profit, return 0.
 *
 * Examples:
 *   Input:  prices = [7,1,5,3,6,4]
 *   Output: 5
 *   Explanation: Buy on day 2 (price = 1), sell on day 5 (price = 6), profit = 6 - 1 = 5.
 *
 *   Input:  prices = [7,6,4,3,1]
 *   Output: 0
 *   Explanation: No days to make a positive profit.
 *
 * Key Insight:
 * We want maximum profit = max(sell_price - buy_price) with sell_day > buy_day.
 * For each day, we want to:
 *   - Keep track of the minimum price so far (best day to buy until now).
 *   - Treat current day as the sell day and compute profit = current_price - min_price_so_far.
 *   - Update max profit if this is better than previous one.
 */

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*
 * Function: max_profit
 * Purpose: Calculate maximum profit from one buy and one sell.
 * Steps:
 *   1. Initialize min_price = INT_MAX (to find the smallest price so far).
 *   2. Initialize max_Profit = 0 (minimum profit is 0 if we can't make money).
 *   3. Loop through each price:
 *        - If current price is lower than min_price, update min_price.
 *        - Else, calculate current profit and update max_Profit if better.
 *   4. Return max_Profit.
 * Why it works?
 *   For each day, we know:
 *     - What is the cheapest day to buy on, before (or on) this day.
 *     - So selling today gives profit = price[i] - min_price.
 *   We just keep track of the best such profit.
 */
int max_profit(vector<int> &prices) {
    int min_price = INT_MAX;   // track the lowest price seen so far (best buy day so far)
    int max_Profit = 0;        // track the maximum profit we can make so far

    // Traverse each day's price
    for (int price : prices) {
        if (price < min_price) {
            // This is the cheapest day so far to buy; update buy price
            min_price = price;
        } else {
            // Treat this day as sell day
            int current_profit = price - min_price;
            // Update max profit if this sale gives better profit
            max_Profit = max(max_Profit, current_profit);
        }
    }

    return max_Profit;
}

// Main function for local testing
int main() {
    cout << "=== Day 2: Best Time to Buy and Sell Stock ===" << endl;

    // Test Case 1: [7,1,5,3,6,4] → max profit = 5
    {
        vector<int> prices = {7, 1, 5, 3, 6, 4};
        int profit = max_profit(prices);

        cout << "Test 1: [7,1,5,3,6,4]" << endl;
        cout << "max profit: " << profit << " (expected: 5)" << endl;
        cout << endl;
    }

    // Test Case 2: [7,6,4,3,1] → max profit = 0 (no profit possible)
    {
        vector<int> prices = {7, 6, 4, 3, 1};
        int profit = max_profit(prices);

        cout << "Test 2: [7,6,4,3,1]" << endl;
        cout << "max profit: " << profit << " (expected: 0)" << endl;
        cout << endl;
    }

    // Test Case 3: [1,2,3,4,5] → max profit = 4 (buy at 1, sell at 5)
    {
        vector<int> prices = {1, 2, 3, 4, 5};
        int profit = max_profit(prices);

        cout << "Test 3: [1,2,3,4,5]" << endl;
        cout << "max profit: " << profit << " (expected: 4)" << endl;
        cout << endl;
    }

    return 0;
}
