// Day 1: Two Sum (LeetCode #1)
// Date: January 01, 2026
// Difficulty: Easy
// Topics: Array, Hash Table
// Time Complexity: O(n)
// Space Complexity: O(n)
// Problem Link: https://leetcode.com/problems/two-sum/description/
// Key Insight: Use unordered_map to store indices for O(1) lookups

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (mp.find(complement) != mp.end()) {
                return {mp[complement], i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};

// Add main function for local testing if you want (optional)
int main() {
    // Test cases here
    return 0;
}
