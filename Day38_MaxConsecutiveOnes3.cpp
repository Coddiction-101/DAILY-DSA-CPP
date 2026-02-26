/*
 * Day 38 - Daily DSA in C++
 * Problem: 1004. Max Consecutive Ones III (LeetCode)
 * Date: February 07, 2026
 * Difficulty: Medium
 * Topics: Array, Binary Search, Sliding Window, Prefix Sum
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 *
 * Problem Link:
 * https://leetcode.com/problems/max-consecutive-ones-iii/
 *
 * -------------------------------------------------------------------
 * Problem Statement:
 * Given a binary array nums and an integer k, return the maximum number 
 * of consecutive 1's in the array if you can flip at most k 0's.
 *
 * -------------------------------------------------------------------
 * Examples:
 *
 *   Input:  nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
 *   Output: 6
 *   Explanation: Flip the 0 at index 5 and 10.
 *                After flipping: [1,1,1,0,0,1,1,1,1,1,1]
 *                Max consecutive 1's = 6 (from index 4 to 9)
 *
 *   Input:  nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
 *   Output: 10
 *   Explanation: Flip 3 zeros to maximize consecutive 1's
 *
 * -------------------------------------------------------------------
 * Key Insight:
 * Sliding Window (Variable Size) Approach:
 * - Maintain a window [left, right] with at most k zeros
 * - Expand window by moving right pointer
 * - If zeros exceed k, shrink window by moving left pointer
 * - Track the maximum window size seen
 * 
 * Window represents: Maximum consecutive 1's we can achieve
 * if we flip the zeros in that window
 * 
 * Why it works:
 * - We try all possible valid windows efficiently
 * - Each element enters and exits window at most once
 * - Time complexity: O(n) - linear scan with two pointers
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    /*
     * Function: longestOnes
     * Purpose: Find the maximum length of consecutive 1's after flipping at most k 0's.
     *
     * Approach - Variable Size Sliding Window:
     * - Use two pointers: left and right to define window
     * - Expand window by moving right pointer
     * - Count zeros in current window
     * - If zeros > k, shrink window from left until valid
     * - Track maximum window size throughout
     * 
     * Steps:
     * 1. Initialize: left=0, right=0, zeros=0, maxLen=0
     * 2. Expand: Move right, count zeros in window
     * 3. Shrink: If zeros > k, move left until zeros <= k
     * 4. Track: Update maxLen with current window size
     * 5. Repeat: Continue until right reaches end
     */
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;     // Left pointer of sliding window
        int right = 0;    // Right pointer of sliding window
        int zeros = 0;    // Count of zeros in current window
        int maxLen = 0;   // Maximum window length seen so far
        
        // Expand window by moving right pointer
        while(right < nums.size()) {
            // Step 1: Add current element to window
            // If it's a 0, increment zeros count
            if(nums[right] == 0) {
                zeros++;
            }
            
            // Step 2: Shrink window if condition violated
            // Window is valid only if it has at most k zeros
            // If zeros > k, we need to shrink from left
            while(zeros > k) {
                // Remove leftmost element from window
                // If it's a 0, decrement zeros count
                if(nums[left] == 0) {
                    zeros--;
                }
                left++;  // Move left pointer to shrink window
            }
            
            // Step 3: Update maximum length
            // Current window size = right - left + 1
            // This window contains at most k zeros
            // All zeros can be flipped to get consecutive 1's
            maxLen = max(maxLen, right - left + 1);
            
            // Step 4: Move right pointer to expand window
            right++;
        }
        
        // Return the maximum window size found
        return maxLen;
    }
};
// Main function for local testing
int main() {
    cout << "=== Day 38: Max Consecutive Ones III ===" << endl;
    Solution solution;
    
    // Test Case 1
    {
        vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
        int k = 2;
        cout << "Test 1: nums = [1,1,1,0,0,0,1,1,1,1,0], k = " << k << endl;
        cout << "Output: " << solution.longestOnes(nums, k) << " (Expected: 6)" << endl;
        cout << "Explanation: Flip index 5 and 10 to get 6 consecutive 1's" << endl;
        cout << endl;
    }
    
    // Test Case 2
    {
        vector<int> nums = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
        int k = 3;
        cout << "Test 2: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = " << k << endl;
        cout << "Output: " << solution.longestOnes(nums, k) << " (Expected: 10)" << endl;
        cout << "Explanation: Flip 3 zeros to maximize length" << endl;
        cout << endl;
    }
    
    // Test Case 3 (Edge Case - k = 0)
    {
        vector<int> nums = {1,1,1,0,1,1,0,1,1,1};
        int k = 0;
        cout << "Test 3: nums = [1,1,1,0,1,1,0,1,1,1], k = " << k << endl;
        cout << "Output: " << solution.longestOnes(nums, k) << " (Expected: 3)" << endl;
        cout << "Explanation: No flips allowed, longest existing sequence" << endl;
        cout << endl;
    }
    
    // Test Case 4 (All zeros)
    {
        vector<int> nums = {0,0,0,0,0};
        int k = 2;
        cout << "Test 4: nums = [0,0,0,0,0], k = " << k << endl;
        cout << "Output: " << solution.longestOnes(nums, k) << " (Expected: 2)" << endl;
        cout << "Explanation: Can flip at most 2 zeros" << endl;
        cout << endl;
    }
    
    // Test Case 5 (All ones)
    {
        vector<int> nums = {1,1,1,1,1};
        int k = 0;
        cout << "Test 5: nums = [1,1,1,1,1], k = " << k << endl;
        cout << "Output: " << solution.longestOnes(nums, k) << " (Expected: 5)" << endl;
        cout << "Explanation: Already all 1's, no flips needed" << endl;
        cout << endl;
    }
    
    return 0;
}

/*
 * Dry Run:
 * Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
 * 
 * Initial: left=0, right=0, zeros=0, maxLen=0
 * 
 * right=0: nums[0]=1, zeros=0
 *   Window: [1], size=1, maxLen=1
 * 
 * right=1: nums[1]=1, zeros=0
 *   Window: [1,1], size=2, maxLen=2
 * 
 * right=2: nums[2]=1, zeros=0
 *   Window: [1,1,1], size=3, maxLen=3
 * 
 * right=3: nums[3]=0, zeros=1
 *   Window: [1,1,1,0], size=4, maxLen=4
 * 
 * right=4: nums[4]=0, zeros=2
 *   Window: [1,1,1,0,0], size=5, maxLen=5
 * 
 * right=5: nums[5]=0, zeros=3 → zeros > k!
 *   Shrink: left=0, nums[0]=1, left=1
 *   Shrink: left=1, nums[1]=1, left=2
 *   Shrink: left=2, nums[2]=1, left=3
 *   Shrink: left=3, nums[3]=0, zeros=2, left=4
 *   Window: [0,0], size=2, maxLen=5
 * 
 * right=6: nums[6]=1, zeros=2
 *   Window: [0,0,1], size=3, maxLen=5
 * 
 * right=7: nums[7]=1, zeros=2
 *   Window: [0,0,1,1], size=4, maxLen=5
 * 
 * right=8: nums[8]=1, zeros=2
 *   Window: [0,0,1,1,1], size=5, maxLen=5
 * 
 * right=9: nums[9]=1, zeros=2
 *   Window: [0,0,1,1,1,1], size=6, maxLen=6 ✓
 * 
 * right=10: nums[10]=0, zeros=3 → zeros > k!
 *   Shrink: left=4, nums[4]=0, zeros=2, left=5
 *   Window: [0,1,1,1,1,0], size=6, maxLen=6
 * 
 * Final: maxLen = 6 ✓
 * 
 * -------------------------------------------------------------------
 * 
 * Key Points:
 * 
 * 1. Sliding Window Pattern:
 *    - Expand: Add element, check condition
 *    - Shrink: If invalid, remove from left
 *    - Track: Keep maximum window size
 * 
 * 2. Why count zeros?
 *    - Window is valid if zeros <= k
 *    - We can flip at most k zeros to 1's
 *    - More zeros = need to shrink window
 * 
 * 3. Window size calculation:
 *    - size = right - left + 1
 *    - Represents consecutive 1's after flipping zeros
 * 
 * 4. Two pointers efficiency:
 *    - Each element visited at most twice
 *    - Once when right pointer reaches it
 *    - Once when left pointer skips it
 *    - Total: O(n) time complexity
 * 
 * 5. Space complexity:
 *    - Only using constant extra space
 *    - Variables: left, right, zeros, maxLen
 *    - O(1) space complexity
 * 
 * 6. Edge cases handled:
 *    - k = 0: Window can't have any zeros
 *    - All zeros: Can flip up to k
 *    - All ones: No flips needed
 *    - Empty array: Returns 0
 * 
 * 7. Sliding window template:
 *    ```
 *    left = 0
 *    for right in range(n):
 *        add nums[right] to window
 *        
 *        while (window invalid):
 *            remove nums[left] from window
 *            left++
 *        
 *        update answer
 *    ```
 * 
 * 8. Why this pattern is important:
 *    - Very common in array/string problems
 *    - Optimizes brute force O(n²) to O(n)
 *    - Master template, solve many problems
 */
