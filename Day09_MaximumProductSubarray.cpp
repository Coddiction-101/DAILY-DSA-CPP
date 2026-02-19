/*
 * Problem: 152. Maximum Product Subarray (LeetCode)
 * Date: January 09, 2026
 * Difficulty: Medium
 * Topics: Arrays, Dynamic Programming
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * Problem Link: https://leetcode.com/problems/maximum-product-subarray/description/
 *
 * Problem Statement:
 * Given an integer array nums, find a contiguous non-empty subarray within the array
 * that has the largest product, and return the product.
 * The test cases are generated so that the answer will fit in a 32-bit integer.
 *
 * Examples:
 *   Input:  nums = [2,3,-2,4]
 *   Output: 6
 *   Explanation: [2,3] has the largest product 6.
 *
 *   Input:  nums = [-2,0,-1]
 *   Output: 0
 *   Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 *
 *   Input:  nums = [-2,3,-4]
 *   Output: 24
 *   Explanation: [-2,3,-4] has the largest product 24.
 *
 * Key Insight:
 * Unlike Maximum Subarray (Kadane's), we need to track BOTH max AND min because:
 *   - A negative number can turn the smallest (most negative) product into the largest
 *   - Example: min = -10, current = -3 → product = 30 (becomes new max!)
 *   - We maintain: maxEndingHere, minEndingHere, and globalMax
 * 
 * For each element, we have 3 choices:
 *   1. Start fresh with current element
 *   2. Extend previous max by multiplying with current
 *   3. Extend previous min by multiplying with current (important for negatives!)
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * Function: maxProduct
 * Purpose: Find the maximum product of a contiguous subarray.
 * Steps:
 *   1. Initialize maxEndingHere, minEndingHere, and globalMax with first element
 *   2. Loop through array from index 1:
 *        - Store previous max and min (needed before updating)
 *        - maxEndingHere = max of {current, prevMax * current, prevMin * current}
 *        - minEndingHere = min of {current, prevMax * current, prevMin * current}
 *        - Update globalMax if maxEndingHere is better
 *   3. Return globalMax
 * 
 * Why it works?
 *   - We keep both max and min products ending at each position
 *   - When we hit a negative number:
 *       → prevMin (large negative) * negative = large positive (new max!)
 *       → prevMax (large positive) * negative = large negative (new min!)
 *   - When we hit zero, we effectively "reset" by starting fresh
 *   - Each position, we consider: start new OR extend previous max/min
 */
int maxProduct(vector<int>& nums) {
    int n = nums.size();
    
    // Initialize with first element
    int maxEndingHere = nums[0];  // Max product ending at current position
    int minEndingHere = nums[0];  // Min product ending at current position
    int globalMax = nums[0];      // Overall maximum product found so far
    
    // Process remaining elements
    for(int i = 1; i < n; i++) {
        // Store previous values before updating (crucial!)
        int prevMax = maxEndingHere;
        int prevMin = minEndingHere;
        
        // Calculate new max: choose best among 3 options
        // 1. Current element alone (start fresh)
        // 2. Extend previous max
        // 3. Extend previous min (important when current is negative!)
        maxEndingHere = max({nums[i], prevMax * nums[i], prevMin * nums[i]});
        
        // Calculate new min: choose worst among 3 options
        // (We need this because negative * negative = positive)
        minEndingHere = min({nums[i], prevMax * nums[i], prevMin * nums[i]});
        
        // Update global maximum
        globalMax = max(globalMax, maxEndingHere);
    }
    
    return globalMax;
}

// Main function for local testing
int main() {
    cout << "=== Day 9: Maximum Product Subarray ===" << endl;
    
    // Test Case 1: [2,3,-2,4] → max product = 6
    {
        vector<int> nums = {2, 3, -2, 4};
        int result = maxProduct(nums);
        cout << "Test 1: [2,3,-2,4]" << endl;
        cout << "Max Product: " << result << " (expected: 6)" << endl;
        cout << "Explanation: [2,3] = 2*3 = 6" << endl;
        cout << endl;
    }
    
    // Test Case 2: [-2,0,-1] → max product = 0
    {
        vector<int> nums = {-2, 0, -1};
        int result = maxProduct(nums);
        cout << "Test 2: [-2,0,-1]" << endl;
        cout << "Max Product: " << result << " (expected: 0)" << endl;
        cout << "Explanation: Best is [0] = 0" << endl;
        cout << endl;
    }
    
    // Test Case 3: [-2,3,-4] → max product = 24
    {
        vector<int> nums = {-2, 3, -4};
        int result = maxProduct(nums);
        cout << "Test 3: [-2,3,-4]" << endl;
        cout << "Max Product: " << result << " (expected: 24)" << endl;
        cout << "Explanation: [-2,3,-4] = -2*3*-4 = 24" << endl;
        cout << endl;
    }
    
    // Test Case 4: [-2] → max product = -2
    {
        vector<int> nums = {-2};
        int result = maxProduct(nums);
        cout << "Test 4: [-2]" << endl;
        cout << "Max Product: " << result << " (expected: -2)" << endl;
        cout << "Explanation: Single element" << endl;
        cout << endl;
    }
    
    // Test Case 5: [2,-5,-2,-4,3] → max product = 24
    {
        vector<int> nums = {2, -5, -2, -4, 3};
        int result = maxProduct(nums);
        cout << "Test 5: [2,-5,-2,-4,3]" << endl;
        cout << "Max Product: " << result << " (expected: 24)" << endl;
        cout << "Explanation: [2,-5,-2,-4] = 2*-5*-2*-4 = -80, but [-5,-2,-4,3] = -5*-2*-4*3 = -120" << endl;
        cout << "Actually: [-2,-4,3] = -2*-4*3 = 24 or [2,-5,-2] = 2*-5*-2 = 20" << endl;
        cout << endl;
    }
    
    // Test Case 6: [0,2] → max product = 2
    {
        vector<int> nums = {0, 2};
        int result = maxProduct(nums);
        cout << "Test 6: [0,2]" << endl;
        cout << "Max Product: " << result << " (expected: 2)" << endl;
        cout << "Explanation: Zero resets, then [2] = 2" << endl;
        cout << endl;
    }
    
    // Test Case 7: [-2,-3,-4] → max product = 12
    {
        vector<int> nums = {-2, -3, -4};
        int result = maxProduct(nums);
        cout << "Test 7: [-2,-3,-4]" << endl;
        cout << "Max Product: " << result << " (expected: 12)" << endl;
        cout << "Explanation: [-3,-4] = -3*-4 = 12" << endl;
        cout << endl;
    }
    
    return 0;
}

/*
 * Dry Run Example:
 * Input: nums = [2,3,-2,4]
 * 
 * Initial: maxEndingHere=2, minEndingHere=2, globalMax=2
 * 
 * i=1, num=3:
 *   prevMax=2, prevMin=2
 *   maxEndingHere = max(3, 2*3=6, 2*3=6) = 6
 *   minEndingHere = min(3, 2*3=6, 2*3=6) = 3
 *   globalMax = max(2, 6) = 6
 * 
 * i=2, num=-2:
 *   prevMax=6, prevMin=3
 *   maxEndingHere = max(-2, 6*-2=-12, 3*-2=-6) = -2
 *   minEndingHere = min(-2, 6*-2=-12, 3*-2=-6) = -12
 *   globalMax = max(6, -2) = 6
 * 
 * i=3, num=4:
 *   prevMax=-2, prevMin=-12
 *   maxEndingHere = max(4, -2*4=-8, -12*4=-48) = 4
 *   minEndingHere = min(4, -2*4=-8, -12*4=-48) = -48
 *   globalMax = max(6, 4) = 6
 * 
 * Final: globalMax = 6 ✓
 * 
 * Key Points:
 * - Why track min? At i=2, minEndingHere=-12 could become max if next is negative
 * - At each step, we consider starting fresh vs extending previous products
 * - Negative numbers flip max and min, so we need both
 * - O(n) time, O(1) space - optimal solution
 */
