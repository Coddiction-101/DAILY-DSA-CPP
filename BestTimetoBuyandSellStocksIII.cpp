/*
 * Problem: 123. Best Time to Buy and Sell Stock III (LeetCode)
 * Date: February 05, 2026
 * Difficulty: Hard
 * Topics: Array, Dynamic Programming, State Machine
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
 *
 * Problem Statement:
 * You are given an array prices where prices[i] is the price of a given stock on day i.
 * Find the maximum profit you can achieve. You may complete at most two transactions.
 * 
 * Note: You may not engage in multiple transactions simultaneously 
 * (i.e., you must sell the stock before you buy again).
 *
 * Examples:
 *   Input:  prices = [3,3,5,0,0,3,1,4]
 *   Output: 6
 *   Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3.
 *                Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 3.
 *                Total profit = 3 + 3 = 6.
 *
 *   Input:  prices = [1,2,3,4,5]
 *   Output: 4
 *   Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 4.
 *                Only one transaction needed.
 *
 *   Input:  prices = [7,6,4,3,1]
 *   Output: 0
 *   Explanation: No profit possible as prices are decreasing.
 *
 * Key Insight:
 * State Machine Dynamic Programming:
 * - We track 4 states at each price point:
 *   1. buy1:  Maximum profit after buying first stock
 *   2. sell1: Maximum profit after selling first stock
 *   3. buy2:  Maximum profit after buying second stock
 *   4. sell2: Maximum profit after selling second stock (final answer)
 * 
 * - State transitions ensure proper ordering:
 *   buy1 → sell1 → buy2 → sell2
 * 
 * - At each price, we decide whether to take action or maintain previous state
 */

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    /*
     * Function: maxProfit
     * Purpose: Calculate maximum profit with at most 2 transactions.
     * 
     * Approach - State Machine DP:
     * We maintain 4 variables representing 4 states:
     * 
     * buy1:  Best profit after first purchase (will be negative or 0)
     *        Represents: -price (spent money to buy)
     * 
     * sell1: Best profit after first sale
     *        Represents: buy1 + price (recovered money + profit)
     * 
     * buy2:  Best profit after second purchase
     *        Represents: sell1 - price (profit from first - second buy cost)
     * 
     * sell2: Best profit after second sale (final answer)
     *        Represents: buy2 + price (total profit from both transactions)
     * 
     * State Transitions:
     * For each price, we decide:
     * - Keep previous state OR
     * - Perform action (buy/sell)
     * We always take the maximum of these two choices.
     * 
     * Why this works:
     * - buy2 depends on sell1, ensuring first transaction completes first
     * - We track "best so far" at each state
     * - Greedy choice at each state leads to global optimum
     * 
     * Time Complexity: O(n) - single pass through prices array
     * Space Complexity: O(1) - only 4 variables, constant space
     */
    int maxProfit(vector<int>& prices) {
        // Initialize states
        // buy1, buy2: Start with INT_MIN (haven't bought yet, so profit is very negative)
        // sell1, sell2: Start with 0 (no transactions yet, so profit is 0)
        int buy1 = INT_MIN, sell1 = 0;
        int buy2 = INT_MIN, sell2 = 0;

        // Process each price point
        for(int price : prices) {
            // ===== First Transaction =====
            
            // Update buy1: Maximum profit after buying first stock
            // Choice 1: Keep previous buy1 (already bought earlier at better price)
            // Choice 2: Buy now at current price (-price, negative because we spend money)
            // We take maximum because we want best profit (least negative)
            buy1 = max(buy1, -price);
            
            // Update sell1: Maximum profit after selling first stock
            // Choice 1: Keep previous sell1 (already sold earlier for better profit)
            // Choice 2: Sell now (buy1 + price, we get back money)
            // Example: if buy1 = -3 (bought at 3), price = 5, then sell1 = -3 + 5 = 2
            sell1 = max(sell1, buy1 + price);
            
            // ===== Second Transaction =====
            
            // Update buy2: Maximum profit after buying second stock
            // Choice 1: Keep previous buy2 (already made second purchase earlier)
            // Choice 2: Buy now using profit from first transaction (sell1 - price)
            // Example: if sell1 = 2 (profit from first), price = 1, then buy2 = 2 - 1 = 1
            // This ensures we use profit from first transaction for second purchase
            buy2 = max(buy2, sell1 - price);
            
            // Update sell2: Maximum profit after selling second stock (FINAL ANSWER)
            // Choice 1: Keep previous sell2 (already completed both transactions)
            // Choice 2: Sell second stock now (buy2 + price)
            // Example: if buy2 = 1, price = 4, then sell2 = 1 + 4 = 5
            sell2 = max(sell2, buy2 + price);
        }
        
        // Return final profit after (possibly) completing 2 transactions
        // Note: If only 1 transaction is profitable, sell2 will reflect that
        // If no transactions are profitable, sell2 will be 0
        return sell2;
    }
};

// Main function for local testing
int main() {
    cout << "=== Day 36: Best Time to Buy and Sell Stock III ===" << endl;
    Solution solution;
    
    // Test Case 1: Two profitable transactions
    {
        vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
        int result = solution.maxProfit(prices);
        cout << "Test 1: [3,3,5,0,0,3,1,4]" << endl;
        cout << "Max Profit: " << result << " (expected: 6)" << endl;
        cout << "Explanation: Buy at 0, sell at 3 (profit=3), buy at 1, sell at 4 (profit=3)" << endl;
        cout << endl;
    }
    
    // Test Case 2: One transaction is optimal
    {
        vector<int> prices = {1, 2, 3, 4, 5};
        int result = solution.maxProfit(prices);
        cout << "Test 2: [1,2,3,4,5]" << endl;
        cout << "Max Profit: " << result << " (expected: 4)" << endl;
        cout << "Explanation: Buy at 1, sell at 5 (profit=4), one transaction enough" << endl;
        cout << endl;
    }
    
    // Test Case 3: No profitable transactions
    {
        vector<int> prices = {7, 6, 4, 3, 1};
        int result = solution.maxProfit(prices);
        cout << "Test 3: [7,6,4,3,1]" << endl;
        cout << "Max Profit: " << result << " (expected: 0)" << endl;
        cout << "Explanation: Prices only decrease, no profit possible" << endl;
        cout << endl;
    }
    
    // Test Case 4: Single price
    {
        vector<int> prices = {1};
        int result = solution.maxProfit(prices);
        cout << "Test 4: [1]" << endl;
        cout << "Max Profit: " << result << " (expected: 0)" << endl;
        cout << "Explanation: Need at least 2 days for a transaction" << endl;
        cout << endl;
    }
    
    // Test Case 5: Multiple peaks and valleys
    {
        vector<int> prices = {1, 2, 4, 2, 5, 7, 2, 4, 9, 0};
        int result = solution.maxProfit(prices);
        cout << "Test 5: [1,2,4,2,5,7,2,4,9,0]" << endl;
        cout << "Max Profit: " << result << endl;
        cout << "Explanation: Two best transactions identified automatically" << endl;
        cout << endl;
    }
    
    return 0;
}

/*
 * Dry Run Example:
 * Input: prices = [3,3,5,0,0,3,1,4]
 * 
 * Initial State:
 * buy1 = INT_MIN, sell1 = 0
 * buy2 = INT_MIN, sell2 = 0
 * 
 * i=0, price=3:
 * buy1  = max(INT_MIN, -3) = -3          (bought at 3)
 * sell1 = max(0, -3+3) = 0               (no profit yet)
 * buy2  = max(INT_MIN, 0-3) = -3         (second buy at 3)
 * sell2 = max(0, -3+3) = 0               (no final profit)
 * 
 * i=1, price=3:
 * buy1  = max(-3, -3) = -3               (keep previous)
 * sell1 = max(0, -3+3) = 0               (still no profit)
 * buy2  = max(-3, 0-3) = -3              (keep previous)
 * sell2 = max(0, -3+3) = 0               (still no final profit)
 * 
 * i=2, price=5:
 * buy1  = max(-3, -5) = -3               (keep buy at 3)
 * sell1 = max(0, -3+5) = 2               (profit if sell at 5!)
 * buy2  = max(-3, 2-5) = -3              (keep previous)
 * sell2 = max(0, -3+5) = 2               (could end with profit=2)
 * 
 * i=3, price=0:
 * buy1  = max(-3, -0) = 0                (buy at 0 is better!)
 * sell1 = max(2, 0+0) = 2                (keep previous profit)
 * buy2  = max(-3, 2-0) = 2               (second buy at 0 after profit=2)
 * sell2 = max(2, 2+0) = 2                (keep current best)
 * 
 * i=4, price=0:
 * buy1  = max(0, -0) = 0                 (keep)
 * sell1 = max(2, 0+0) = 2                (keep)
 * buy2  = max(2, 2-0) = 2                (keep)
 * sell2 = max(2, 2+0) = 2                (keep)
 * 
 * i=5, price=3:
 * buy1  = max(0, -3) = 0                 (keep buy at 0)
 * sell1 = max(2, 0+3) = 3                (better to sell at 3!)
 * buy2  = max(2, 3-3) = 2                (keep previous)
 * sell2 = max(2, 2+3) = 5                (if sell second at 3, profit=5)
 * 
 * i=6, price=1:
 * buy1  = max(0, -1) = 0                 (keep buy at 0)
 * sell1 = max(3, 0+1) = 3                (keep sell at 3)
 * buy2  = max(2, 3-1) = 2                (keep previous)
 * sell2 = max(5, 2+1) = 5                (keep current best)
 * 
 * i=7, price=4:
 * buy1  = max(0, -4) = 0                 (keep buy at 0)
 * sell1 = max(3, 0+4) = 4                (could sell first at 4)
 * buy2  = max(2, 4-4) = 2                (keep previous buy2)
 * sell2 = max(5, 2+4) = 6                (sell second at 4, total=6!) ✓
 * 
 * Final Answer: 6
 * Transactions: Buy at 0, sell at 3 (profit=3), buy at 1, sell at 4 (profit=3)
 * 
 * Key Observations:
 * 1. States evolve as we see better opportunities
 * 2. buy2 depends on sell1, ensuring proper ordering
 * 3. We don't need to explicitly track which days we buy/sell
 * 4. The algorithm automatically finds optimal combination
 * 5. If only 1 transaction is better, it will be reflected in sell2
 * 
 * Extension to Stock IV:
 * This same logic extends to k transactions:
 * - Use arrays: buy[k], sell[k]
 * - Loop through k transactions
 * - Same state transition logic
 * 
 * Why This Pattern is Important:
 * - State machine DP is common in interview problems
 * - Teaches constraint handling (at most k transactions)
 * - Space optimization (4 variables vs 2D array)
 * - Understanding greedy within DP framework
 */
