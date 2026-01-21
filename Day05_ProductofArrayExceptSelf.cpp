/*
 * Problem: 238. Product of Array Except Self (LeetCode)
 * Date: January 05, 2026
 * Difficulty: Medium
 * Topics: Array, Prefix/Suffix Product
 * Time Complexity: O(n)
 * Space Complexity: O(1) extra (excluding output array)
 * Problem Link: https://leetcode.com/problems/product-of-array-except-self/description/
 *
 * Problem Statement:
 * Given an integer array nums, return an array result such that:
 *   result[i] = product of all elements of nums except nums[i].
 *
 * Constraints:
 * - You must do it in O(n) time and without using division.
 *
 * Example:
 *   Input:  nums = [1,2,3,4]
 *   Output: [24, 12, 8, 6]
 *   Explanation:
 *     result[0] = 2*3*4 = 24
 *     result[1] = 1*3*4 = 12
 *     result[2] = 1*2*4 =  8
 *     result[3] = 1*2*3 =  6
 *
 * Key Insight: Prefix × Suffix (Two‑Pass, In‑Place Style)
 * - For each index i:
 *     result[i] = (product of all elements on left) × (product of all elements on right)
 * - Step 1: Build left product in result array:
 *     result[i] = result[i-1] * nums[i-1]
 *     This stores product of all elements before i.
 * - Step 2: Traverse from right with a running rightProduct:
 *     result[i] *= rightProduct (rightProduct is product of elements after i)
 *     Then update rightProduct *= nums[i] for next iteration.
 * - This avoids using a separate left/right array → O(1) extra space.
 */

#include <iostream>
#include <vector>
using namespace std;

/*
 * Function: productExceptSelf
 * Purpose: Return an array where result[i] is the product of all elements except nums[i].
 * Steps:
 *   1. Initialize result with size n and all values = 1.
 *   2. First pass (left to right):
 *        - result[i] = result[i-1] * nums[i-1]
 *        - This stores left product (product of elements before i).
 *   3. Second pass (right to left):
 *        - Use a variable rightProduct (initially 1).
 *        - result[i] *= rightProduct  → now it has left × right product
 *        - rightProduct *= nums[i]    → prepare for next (smaller) index
 *   4. Return result.
 *
 * Why it works?
 * - We avoid division as required.
 * - We compute left product in one pass, then right product on the fly in the second pass.
 * - Space: only result[] array (allowed) + one extra variable.
 */
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, 1);  // result[i] will store the final answer

    // Step 1: Fill result with left product
    // result[i] = product of nums[0] * nums[1] * ... * nums[i-1]
    for (int i = 1; i < n; i++) {
        result[i] = result[i - 1] * nums[i - 1];
    }

    // Step 2: Multiply each result[i] with right product
    // rightProduct = product of nums[i+1] * nums[i+2] * ... * nums[n-1]
    int rightProduct = 1;
    for (int i = n - 1; i >= 0; i--) {
        result[i] *= rightProduct;  // multiply left product with right product
        rightProduct *= nums[i];    // update rightProduct for next (left) index
    }

    return result;
}

// Utility function to print a vector
void printVector(const string& label, const vector<int>& v) {
    cout << label << ": [";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i < v.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

// Main function for local testing
int main() {
    cout << "=== Day 5: Product of Array Except Self (LeetCode 238) ===" << endl;

    // Test Case 1: [1,2,3,4] → [24,12,8,6]
    {
        vector<int> nums = {1, 2, 3, 4};
        vector<int> res = productExceptSelf(nums);

        printVector("Input nums", nums);
        printVector("Result     ", res);
        cout << endl;
    }

    // Test Case 2: [-1,1,0,-3,3] → [0,0,9,0,0]
    {
        vector<int> nums = {-1, 1, 0, -3, 3};
        vector<int> res = productExceptSelf(nums);

        printVector("Input nums", nums);
        printVector("Result     ", res);
        cout << endl;
    }

    // Test Case 3: [2,3] → [3,2]
    {
        vector<int> nums = {2, 3};
        vector<int> res = productExceptSelf(nums);

        printVector("Input nums", nums);
        printVector("Result     ", res);
        cout << endl;
    }

    return 0;
}
