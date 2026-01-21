/*
 * Problem: 189. Rotate Array (LeetCode)
 * Date: January 07, 2026
 * Difficulty: Medium
 * Topics: Array, Math, Two Pointers, In-Place
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * Problem Link: https://leetcode.com/problems/rotate-array/description/
 *
 * Problem Statement:
 * Given an array nums, rotate the array to the right by k steps, where k is non-negative.
 * Do it in-place (modify nums directly).
 *
 * Example:
 *   Input:  nums = [1,2,3,4,5,6,7], k = 3
 *   Output: nums = [5,6,7,1,2,3,4]
 *   Explanation: Rotate by 3 steps: [1,2,3,4,5,6,7] → [5,6,7,1,2,3,4].
 *
 * Key Insight: Reverse in 3 Steps
 * - Rotate right by k: last k elements come to front, rest shift right.
 * - We can do this in 3 reverse operations:
 *     1. Reverse entire array → brings last k elements to front (but reversed).
 *     2. Reverse first k elements → fixes order of first k.
 *     3. Reverse last n-k elements → fixes order of last n-k.
 * - This is O(n) time and O(1) extra space.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * Function: rotateArray / rotate
 * Purpose: Rotate the array to the right by k steps in-place.
 * Steps:
 *   1. Handle edge case: k %= n → if k > n, take modulo to avoid full cycles.
 *   2. Reverse the entire array → [1,2,3,4,5,6,7] → [7,6,5,4,3,2,1] (for k=3).
 *   3. Reverse the first k elements → [7,6,5] → [5,6,7].
 *   4. Reverse the last n-k elements → [4,3,2,1] → [1,2,3,4].
 *   5. Result: [5,6,7,1,2,3,4] → correct rotation.
 *
 * Why it works?
 * - Reversing entire array flips the order.
 * - Reversing the two parts restores the order within each group while keeping the groups in correct relative order.
 */
void rotateArray(vector<int>& nums, int k) {
    int n = nums.size();
    if (n == 0) return;

    k %= n;  // Reduce k: if k >= n, only k mod n steps matter

    // Step 1: Reverse entire array
    reverse(nums.begin(), nums.end());

    // Step 2: Reverse first k elements
    reverse(nums.begin(), nums.begin() + k);

    // Step 3: Reverse last n-k elements
    reverse(nums.begin() + k, nums.end());
}

// Utility function to print a vector
void printVector(const vector<int>& nums, const string& label) {
    cout << label << ": [";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << " ";
    }
    cout << "]" << endl;
}

// Main function for local testing
int main() {
    cout << "=== Day 7: Rotate Array (LeetCode 189) ===" << endl;

    // Test Case 1: [1,2,3,4,5,6,7], k=3 → [5,6,7,1,2,3,4]
    {
        vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
        int k = 3;

        printVector("Input", arr);
        cout << "k = " << k << endl;

        rotateArray(arr, k);
        printVector("Rotated", arr);
        cout << endl;
    }

    // Test Case 2: [1,2], k=1 → [2,1]
    {
        vector<int> arr = {1, 2};
        int k = 1;

        printVector("Input", arr);
        cout << "k = " << k << endl;

        rotateArray(arr, k);
        printVector("Rotated", arr);
        cout << endl;
    }

    // Test Case 3: [1], k=0 → [1]
    {
        vector<int> arr = {1};
        int k = 0;

        printVector("Input", arr);
        cout << "k = " << k << endl;

        rotateArray(arr, k);
        printVector("Rotated", arr);
        cout << endl;
    }

    // Test Case 4: [1,2,3,4,5], k=7 → k = 7 % 5 = 2 → [4,5,1,2,3]
    {
        vector<int> arr = {1, 2, 3, 4, 5};
        int k = 7;

        printVector("Input", arr);
        cout << "k = " << k << " (k %= n → k = 2)" << endl;

        rotateArray(arr, k);
        printVector("Rotated", arr);
        cout << endl;
    }

    return 0;
}
