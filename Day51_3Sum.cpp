 /*
 * Problem: 15. 3Sum (LeetCode)
 * Topics: Array, Two Pointers, Sorting
 *
 * Time Complexity: O(n²)
 * Space Complexity: O(1) - excluding output storage
 *
 * -------------------------------------------------------------------
 * Problem Statement:
 * Given an integer array nums, return all unique triplets 
 * [nums[i], nums[j], nums[k]] such that:
 *
 *      i != j, i != k, j != k
 *      nums[i] + nums[j] + nums[k] == 0
 *
 * The solution set must not contain duplicate triplets.
 *
 * -------------------------------------------------------------------
 * Examples:
 *
 *   Input:  nums = [-1,0,1,2,-1,-4]
 *   Output: [[-1,-1,2],[-1,0,1]]
 *
 *   Explanation:
 *   -1 + -1 + 2 = 0
 *   -1 + 0 + 1 = 0
 *
 *   Input: nums = [0,1,1]
 *   Output: []
 *
 *   Input: nums = [0,0,0]
 *   Output: [[0,0,0]]
 *
 * -------------------------------------------------------------------
 * Key Insight:
 * Sorting + Two Pointers
 *
 * Steps:
 * - Sort the array
 * - Fix one element nums[i]
 * - Use two pointers (left, right) to find two numbers
 *   that sum to -nums[i]
 *
 * Pattern:
 *   nums[i] + nums[left] + nums[right] = 0
 *
 *   → nums[left] + nums[right] = -nums[i]
 *
 * Move pointers based on comparison with target.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    /*
     * Function: threeSum
     * Purpose: Find all unique triplets whose sum is zero.
     *
     * Approach:
     * 1. Sort the array
     * 2. Fix one number at index i
     * 3. Use two pointers to find pair with sum = -nums[i]
     * 4. Skip duplicates to ensure unique triplets
     *
     * Steps:
     * - Sort nums
     * - Loop i from 0 to n-3
     * - Skip duplicate i values
     * - Set left = i+1, right = n-1
     * - Compute sum = nums[left] + nums[right]
     * - Compare with target
     */

    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> result;

        // Step 1: Sort array
        sort(nums.begin(), nums.end());

        int n = nums.size();

        // Step 2: Fix first element
        for(int i = 0; i < n - 2; i++) {

            // Skip duplicates for first element
            if(i > 0 && nums[i] == nums[i-1])
                continue;

            int left = i + 1;
            int right = n - 1;

            int target = -nums[i];

            // Step 3: Two pointer search
            while(left < right) {

                int sum = nums[left] + nums[right];

                if(sum == target) {

                    result.push_back({nums[i], nums[left], nums[right]});

                    // Skip duplicate values
                    while(left < right && nums[left] == nums[left+1])
                        left++;

                    while(left < right && nums[right] == nums[right-1])
                        right--;

                    left++;
                    right--;
                }

                else if(sum < target)
                    left++;

                else
                    right--;
            }
        }

        return result;
    }
};


int main() {

    Solution solution;

    // Test Case 1
    {
        vector<int> nums = {-1,0,1,2,-1,-4};

        auto result = solution.threeSum(nums);

        cout << "Test 1: [-1,0,1,2,-1,-4]" << endl;

        for(auto &triplet : result){
            cout << "[ ";
            for(int x : triplet) cout << x << " ";
            cout << "] ";
        }

        cout << endl;
        cout << "Expected: [-1,-1,2] [-1,0,1]" << endl;
        cout << endl;
    }

    // Test Case 2
    {
        vector<int> nums = {0,0,0};

        auto result = solution.threeSum(nums);

        cout << "Test 2: [0,0,0]" << endl;

        for(auto &triplet : result){
            cout << "[ ";
            for(int x : triplet) cout << x << " ";
            cout << "] ";
        }

        cout << endl;
        cout << "Expected: [0,0,0]" << endl;
        cout << endl;
    }

    return 0;
}

/*
 * Dry Run:
 *
 * Input:
 * nums = [-1,0,1,2,-1,-4]
 *
 * Step 1: Sort
 * [-4,-1,-1,0,1,2]
 *
 * i = 0 → nums[i] = -4
 * target = 4
 *
 * left=1 (-1), right=5 (2)
 * sum=1 < 4 → left++
 *
 * Continue until pointers meet
 * No triplet
 *
 * i = 1 → nums[i] = -1
 * target = 1
 *
 * left=2 (-1), right=5 (2)
 * sum = 1 → valid triplet
 * [-1,-1,2]
 *
 * Move pointers skipping duplicates
 *
 * left=3 (0), right=4 (1)
 * sum=1 → valid
 * [-1,0,1]
 *
 * Result:
 * [[-1,-1,2],[-1,0,1]]
 *
 * -------------------------------------------------------------------
 *
 * Key Points:
 *
 * 1. Sorting enables two-pointer strategy.
 *
 * 2. Why skip duplicates?
 *    Prevent repeating same triplets.
 *
 * 3. Two-pointer logic:
 *    - sum < target → move left++
 *    - sum > target → move right--
 *
 * 4. Complexity:
 *    - Sorting → O(n log n)
 *    - Two pointer loop → O(n²)
 *
 *    Overall → O(n²)
 *
 * 5. Space Complexity:
 *    O(1) auxiliary (result not counted).
 *
 * -------------------------------------------------------------------
 *
 * Pattern Learned:
 *
 * Sorting + Two Pointers
 *
 * Used in many problems:
 * - 3Sum
 * - 4Sum
 * - Container With Most Water
 * - Two Sum II
 *
 */
