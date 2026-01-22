/*
 * Problem: 55. Jump Game (LeetCode)
 * Date: January 08, 2026
 * Difficulty: Medium
 * Topics: Array, Greedy, Dynamic Programming
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * Problem Link: https://leetcode.com/problems/jump-game/description/
 *
 * Problem Statement:
 * You are given an integer array nums. You are initially positioned at the first index (index 0).
 * Each element nums[i] represents your maximum jump length at that position.
 * Return true if you can reach the last index, or false otherwise.
 *
 * Examples:
 *   Input:  nums = [2,3,1,1,4]
 *   Output: true
 *   Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
 *
 *   Input:  nums = [3,2,1,0,4]
 *   Output: false
 *   Explanation: You will always arrive at index 3, whose jump length is 0 → can't reach last index.
 *
 * Key Insight: Greedy / Farthest Reach
 * - At each index i, the farthest index you can reach is i + nums[i].
 * - Keep a variable maxReach that tracks how far you can go so far.
 * - If at any index i, i > maxReach → you can't reach this index → return false.
 * - Else, update maxReach = max(maxReach, i + nums[i]).
 * - If you finish the loop, return true.
 */

#include <iostream>
#include <vector>
using namespace std;

/*
 * Function: canJump
 * Purpose: Determine if you can reach the last index of the array.
 * Steps:
 *   1. Initialize maxReach = 0 → farthest index reachable so far.
 *   2. Traverse each index i from 0 to n-1:
 *        - If i > maxReach → current index is unreachable → return false.
 *        - Else → update maxReach = max(maxReach, i + nums[i]).
 *   3. If we complete the loop → last index is reachable → return true.
 *
 * Why it works?
 * - We keep track of the farthest index that can be reached with any previous jumps.
 * - At each step, if we can jump from here, we extend maxReach.
 * - If we can never reach a certain index, we return false early.
 */
bool canJump(vector<int>& nums) {
    int n = nums.size();
    int maxReach = 0;  // farthest index we can reach

    for (int i = 0; i < n; i++) {
        // If current index is beyond what we can reach, return false
        if (i > maxReach) {
            return false;
        }

        // Update how far we can go from here
        maxReach = max(maxReach, i + nums[i]);

        // Optional: if we can already reach the last index, we can break early
        // if (maxReach >= n - 1) return true;
    }

    return true;
}

// Utility function to print result with label
void printResult(const vector<int>& nums, bool result, const string& label) {
    cout << label << ": [";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << " ";
    }
    cout << "] → " << (result ? "true" : "false") << endl;
}

// Main function for local testing
int main() {
    cout << "=== Day 8: Jump Game (LeetCode 55) ===" << endl;

    // Test Case 1: [2,3,1,1,4] → true
    {
        vector<int> nums = {2, 3, 1, 1, 4};
        bool result = canJump(nums);
        printResult(nums, result, "Test 1");
        cout << endl;
    }

    // Test Case 2: [3,2,1,0,4] → false
    {
        vector<int> nums = {3, 2, 1, 0, 4};
        bool result = canJump(nums);
        printResult(nums, result, "Test 2");
        cout << endl;
    }

    // Test Case 3: [0] → true (only one element, already at last index)
    {
        vector<int> nums = {0};
        bool result = canJump(nums);
        printResult(nums, result, "Test 3");
        cout << endl;
    }

    // Test Case 4: [1,0] → true (can jump from 0 to 1, then already at last index)
    {
        vector<int> nums = {1, 0};
        bool result = canJump(nums);
        printResult(nums, result, "Test 4");
        cout << endl;
    }

    // Test Case 5: [0,1] → false (start at 0 with jump 0, can't reach index 1)
    {
        vector<int> nums = {0, 1};
        bool result = canJump(nums);
        printResult(nums, result, "Test 5");
        cout << endl;
    }

    return 0;
}

