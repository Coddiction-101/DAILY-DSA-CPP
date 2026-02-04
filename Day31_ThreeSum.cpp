/**
 * Day 31: LC 15 - 3Sum
 * Pattern: Sorting + Two Pointers
 * Time Complexity: O(n^2)
 * Space Complexity: O(1) (excluding output)
 *
 * Repo: DAILY-DSA-CPP/Day_31/three_sum.cpp
 *
 * Key Idea:
 * - Sort the array
 * - Fix one element
 * - Use two pointers to find remaining two elements
 * - Skip duplicates to avoid repeated triplets
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        // Sort the array to apply two pointers
        sort(nums.begin(), nums.end());

        int n = nums.size();

        for (int i = 0; i < n; i++) {
            // Skip duplicate fixed elements
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    // Valid triplet found
                    result.push_back({nums[i], nums[left], nums[right]});

                    // Skip duplicates for left pointer
                    while (left < right && nums[left] == nums[left + 1])
                        left++;

                    // Skip duplicates for right pointer
                    while (left < right && nums[right] == nums[right - 1])
                        right--;

                    // Move both pointers
                    left++;
                    right--;
                }
                else if (sum < 0) {
                    // Need a larger sum → move left pointer
                    left++;
                }
                else {
                    // Need a smaller sum → move right pointer
                    right--;
                }
            }
        }
        return result;
    }
};

// Utility function to print result
void printResult(const vector<vector<int>>& result) {
    cout << "[";
    for (size_t i = 0; i < result.size(); i++) {
        cout << "[";
        for (size_t j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
            if (j < result[i].size() - 1) cout << ", ";
        }
        cout << "]";
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;

    // Test cases (LeetCode style)
    vector<vector<int>> testCases = {
        {-1, 0, 1, 2, -1, -4},
        {0, 1, 1},
        {0, 0, 0},
        {-2, 0, 1, 1, 2}
    };

    for (auto& nums : testCases) {
        cout << "Input: ";
        printResult({nums});

        auto result = sol.threeSum(nums);

        cout << "Output: ";
        printResult(result);
        cout << endl;
    }

    cout << "All test cases executed successfully! Two Pointers + Deduplication mastered 🚀" << endl;
    return 0;
}

