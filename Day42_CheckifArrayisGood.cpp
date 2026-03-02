/*
 * Problem: 2341. Check if the Array is Good (LeetCode)
 * Date: March 02, 2026
 * Difficulty: Medium
 * Topics: Array, Hashing
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * Problem Link: https://leetcode.com/problems/check-if-array-is-good/
 *
 * Problem Statement:
 * Given an array nums, determine if it is a "good" array based on the following criteria:
 * - The array contains integers from 1 to n (where n = nums.size() - 1).
 * - All integers from 1 to n-1 appear exactly once.
 * - The number n appears exactly twice.
 * Return true if all conditions are met; otherwise, false.
 *
 * Example:
 *   Input: nums = [1, 2, 3, 3]
 *   Output: true
 *   Explanation: n=3, appears twice; 1 and 2 appear once.
 *
 *   Input: nums = [1, 2, 4]
 *   Output: false
 *   Explanation: 4 is out of range (should be <= n).
 *
 * Key Insight:
 * - Check if all numbers are within 1 to n.
 * - Count the frequency of each number.
 * - Verify that 1..n-1 each appear exactly once.
 * - Verify that n appears exactly twice.
 */
#include <vector>
#include <iostream>
using namespace std;

/*
 * Function: isGood
 * Purpose: To determine if the input array meets the "good" array conditions.
 * Approach:
 *   1. Calculate n = size of array - 1.
 *   2. Initialize a frequency array of size n+1 with zeros.
 *   3. Loop through nums:
 *       - Check if each element is within 1 to n.
 *       - Increment its frequency.
 *   4. Verify:
 *       - All elements from 1 to n-1 appear exactly once.
 *       - The last element n appears exactly twice.
 *   5. Return true if conditions are met; false otherwise.
 */
bool isGood(vector<int>& nums) {
    int n = nums.size() - 1;
    vector<int> freq(n + 1, 0);

    for (int num : nums) {
        if (num < 1 || num > n) {
            // Number out of valid range
            return false;
        }
        freq[num]++;
    }

    for (int i = 1; i < n; i++) {
        // Check if 1..n-1 appear exactly once
        if (freq[i] != 1) {
            return false;
        }
    }

    // Check if n appears exactly twice
    return freq[n] == 2;
}

// Utility function to test the implementation
void test() {
    cout << "=== Day 42: Check if Array is Good ===" << endl;

    // Test case 1: [1, 2, 3, 3]
    {
        vector<int> arr = {1, 2, 3, 3};
        cout << "Input: ";
        for (auto num : arr) cout << num << " ";
        cout << "\nOutput: " << (isGood(arr) ? "true" : "false") << endl << endl;
    }

    // Test case 2: [1, 2, 4]
    {
        vector<int> arr = {1, 2, 4};
        cout << "Input: ";
        for (auto num : arr) cout << num << " ";
        cout << "\nOutput: " << (isGood(arr) ? "true" : "false") << endl << endl;
    }

    // Test case 3: [1, 1, 2]
    {
        vector<int> arr = {1, 1, 2};
        cout << "Input: ";
        for (auto num : arr) cout << num << " ";
        cout << "\nOutput: " << (isGood(arr) ? "true" : "false") << endl << endl;
    }
}

int main() {
    test();
    return 0;
}
