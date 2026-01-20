/*
 * Problem: 1. Two Sum (LeetCode)
 * Date: January 01, 2026
 * Difficulty: Easy
 * Topics: Array, Hash Table
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * Problem Link: https://leetcode.com/problems/two-sum/description/
 *
 * Problem Statement:
 * Given an array of integers nums and an integer target, return indices of the two numbers
 * such that they add up to target. You may assume that each input would have exactly one solution,
 * and you may not use the same element twice.
 *
 * Example:
 *   Input: nums = [2,7,11,15], target = 9
 *   Output: [0,1]
 *   Explanation: Because nums[0] + nums[1] = 2 + 7 = 9, we return [0, 1].
 *
 * Key Insight:
 * - We want to find two indices i, j such that nums[i] + nums[j] = target.
 * - For each nums[i], we need to check if (target - nums[i]) already exists in the array.
 * - We can use an unordered_map to store {value: index} for O(1) lookup.
 * - As we iterate, we add current nums[i] → i to map, so future elements can find it.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;  // value -> index

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];  // what we need to add with nums[i] to get target

            // If complement is already in map, we found our pair
            if (mp.find(complement) != mp.end()) {
                return {mp[complement], i};
            }

            // Store current value and its index
            mp[nums[i]] = i;
        }

        // According to the problem, we always have exactly one solution,
        // so this line is just for compilation; it will never be hit
        return {};
    }
};

// Utility function to print a vector
void printVector(const vector<int>& v, const string& label) {
    cout << label << ": [";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i < v.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

// Main function for local testing
int main() {
    Solution sol;

    // Test Case 1: [2,7,11,15], target = 9 → [0,1]
    {
        cout << "=== Test Case 1: [2,7,11,15], target = 9 ===" << endl;
        vector<int> nums = {2, 7, 11, 15};
        int target = 9;

        cout << "nums: ";
        for (int x : nums) cout << x << " ";
        cout << endl;
        cout << "target: " << target << endl;

        vector<int> result = sol.twoSum(nums, target);
        printVector(result, "Result");
        cout << endl;
    }

    // Test Case 2: [3,2,4], target = 6 → [1,2]
    {
        cout << "=== Test Case 2: [3,2,4], target = 6 ===" << endl;
        vector<int> nums = {3, 2, 4};
        int target = 6;

        cout << "nums: ";
        for (int x : nums) cout << x << " ";
        cout << endl;
        cout << "target: " << target << endl;

        vector<int> result = sol.twoSum(nums, target);
        printVector(result, "Result");
        cout << endl;
    }

    // Test Case 3: [3,3], target = 6 → [0,1]
    {
        cout << "=== Test Case 3: [3,3], target = 6 ===" << endl;
        vector<int> nums = {3, 3};
        int target = 6;

        cout << "nums: ";
        for (int x : nums) cout << x << " ";
        cout << endl;
        cout << "target: " << target << endl;

        vector<int> result = sol.twoSum(nums, target);
        printVector(result, "Result");
        cout << endl;
    }

    return 0;
}
