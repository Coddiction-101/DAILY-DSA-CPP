/*
 * Problem: 217. Contains Duplicate (LeetCode)
 * Date: January 03, 2026
 * Difficulty: Easy
 * Topics: Array, Hash Table, Set
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * Problem Link: https://leetcode.com/problems/contains-duplicate/description/
 *
 * Problem Statement:
 * Given an integer array nums, return true if any value appears at least twice in the array,
 * and return false if every element is distinct.
 *
 * Examples:
 *   Input:  nums = [1,2,3,1]
 *   Output: true
 *
 *   Input:  nums = [1,2,3,4]
 *   Output: false
 *
 * Key Insight:
 * - We want to know if any element repeats.
 * - We can use a set to store elements we have already seen.
 * - For each element:
 *     - If it is already in the set → duplicate found → return true.
 *     - Else → add it to the set.
 * - If we finish the loop → no duplicate → return false.
 */

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/*
 * Function: findDuplicates / containsDuplicate
 * Purpose: Check if any element appears at least twice in the array.
 * Steps:
 *   1. Create an unordered_set to store elements we have already seen.
 *   2. Traverse each element in the array:
 *        - If current element is already present in set → duplicate → return true.
 *        - Else → insert it into the set.
 *   3. If no duplicate found after full traversal → return false.
 *
 * Why it works?
 * - Set gives O(1) average insertion and lookup.
 * - We immediately return true as soon as we find a duplicate.
 * - This is O(n) time and O(n) space in worst case.
 */

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> seen;

    for (int x : nums) {
        if (seen.count(x)) {
            // Duplicate found
            return true;
        }
        // First time seeing this element → add to set
        seen.insert(x);
    }

    // No duplicates found
    return false;
}

// Utility function to print result with label
void printResult(const vector<int>& nums, bool result, const string& label) {
    cout << label << ": [";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << ", ";
    }
    cout << "] → " << (result ? "true" : "false") << endl;
}

// Main function for local testing
int main() {
    cout << "=== Day 3: Contains Duplicate (LeetCode 217) ===" << endl;

    // Test Case 1: [1,2,3,1] → true (duplicate)
    {
        vector<int> nums = {1, 2, 3, 1};
        bool result = containsDuplicate(nums);
        printResult(nums, result, "Test 1");
        cout << endl;
    }

    // Test Case 2: [1,2,3,4] → false (no duplicate)
    {
        vector<int> nums = {1, 2, 3, 4};
        bool result = containsDuplicate(nums);
        printResult(nums, result, "Test 2");
        cout << endl;
    }

    // Test Case 3: [1,1] → true
    {
        vector<int> nums = {1, 1};
        bool result = containsDuplicate(nums);
        printResult(nums, result, "Test 3");
        cout << endl;
    }

    // Test Case 4: [] → false (empty array)
    {
        vector<int> nums = {};
        bool result = containsDuplicate(nums);
        printResult(nums, result, "Test 4");
        cout << endl;
    }

    return 0;
}
