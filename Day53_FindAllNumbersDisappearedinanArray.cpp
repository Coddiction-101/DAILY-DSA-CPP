/*
 * Day 53 - Daily DSA in C++
 * Problem: 448. Find All Numbers Disappeared in an Array (LeetCode)
 * Date: February 22, 2026
 * Difficulty: Easy
 * Topics: Array, Hash Table
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 *
 * Problem Link:
 * https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
 *
 * -------------------------------------------------------------------
 * Problem Statement:
 * Given an array nums of n integers where nums[i] is in the range [1, n], 
 * return an array of all the integers in the range [1, n] that do not 
 * appear in nums.
 *
 * -------------------------------------------------------------------
 * Examples:
 *
 *   Input:  nums = [4,3,2,7,8,2,3,1]
 *   Output: [5,6]
 *   Explanation: Array has values 1-8, missing 5 and 6
 *
 *   Input:  nums = [1,1]
 *   Output: [2]
 *   Explanation: Range is 1-2, only 1 present, 2 is missing
 *
 * -------------------------------------------------------------------
 * Key Insight:
 * HashSet Approach:
 * - Store all present numbers in a set
 * - Check which numbers from 1 to n are not in set
 * - Simple and intuitive
 * 
 * Alternative (O(1) space):
 * - Use array itself as HashMap by marking indices
 * - More complex but space-efficient
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
     * Function: findDisappearedNumbers
     * Purpose: Find all numbers from 1 to n that are missing from array.
     *
     * Approach - HashSet:
     * - Create a set with all numbers present in array
     * - Iterate from 1 to n
     * - If number not in set, it's missing
     * 
     * Steps:
     * 1. Create unordered_set from nums array
     * 2. For each i from 1 to n:
     *    - If i not in set, add to result
     * 3. Return result
     */
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // Store all present numbers in set for O(1) lookup
        unordered_set<int> present(nums.begin(), nums.end());
        
        vector<int> result;
        
        // Check each number from 1 to n
        for(int i = 1; i <= nums.size(); i++) {
            // If number not present in set, it's missing
            if(present.find(i) == present.end()) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};

int main() {
    cout << "=== Day 53: Find All Numbers Disappeared in an Array ===" << endl;
    Solution solution;
    
    // Test Case 1
    {
        vector<int> nums = {4,3,2,7,8,2,3,1};
        cout << "Test 1: nums = [4,3,2,7,8,2,3,1]" << endl;
        vector<int> result = solution.findDisappearedNumbers(nums);
        cout << "Output: [";
        for(int i = 0; i < result.size(); i++) {
            cout << result[i];
            if(i < result.size() - 1) cout << ",";
        }
        cout << "] (Expected: [5,6])" << endl;
        cout << "Explanation: Numbers 5 and 6 are missing" << endl << endl;
    }
    
    // Test Case 2
    {
        vector<int> nums = {1,1};
        cout << "Test 2: nums = [1,1]" << endl;
        vector<int> result = solution.findDisappearedNumbers(nums);
        cout << "Output: [";
        for(int i = 0; i < result.size(); i++) {
            cout << result[i];
            if(i < result.size() - 1) cout << ",";
        }
        cout << "] (Expected: [2])" << endl;
        cout << "Explanation: Number 2 is missing" << endl << endl;
    }
    
    // Test Case 3
    {
        vector<int> nums = {1,2,3,4,5};
        cout << "Test 3: nums = [1,2,3,4,5]" << endl;
        vector<int> result = solution.findDisappearedNumbers(nums);
        cout << "Output: [";
        for(int i = 0; i < result.size(); i++) {
            cout << result[i];
            if(i < result.size() - 1) cout << ",";
        }
        cout << "] (Expected: [])" << endl;
        cout << "Explanation: All numbers present" << endl << endl;
    }
    
    // Test Case 4
    {
        vector<int> nums = {2,2,2,2};
        cout << "Test 4: nums = [2,2,2,2]" << endl;
        vector<int> result = solution.findDisappearedNumbers(nums);
        cout << "Output: [";
        for(int i = 0; i < result.size(); i++) {
            cout << result[i];
            if(i < result.size() - 1) cout << ",";
        }
        cout << "] (Expected: [1,3,4])" << endl;
        cout << "Explanation: Only 2 is present" << endl << endl;
    }
    
    return 0;
}

/*
 * Dry Run:
 * Input: nums = [4,3,2,7,8,2,3,1]
 * n = 8
 * 
 * Step 1: Create set
 * present = {4, 3, 2, 7, 8, 1}
 * (duplicates automatically removed)
 * 
 * Step 2: Check 1 to 8
 * i = 1: 1 in set? YES → skip
 * i = 2: 2 in set? YES → skip
 * i = 3: 3 in set? YES → skip
 * i = 4: 4 in set? YES → skip
 * i = 5: 5 in set? NO → add to result
 * i = 6: 6 in set? NO → add to result
 * i = 7: 7 in set? YES → skip
 * i = 8: 8 in set? YES → skip
 * 
 * Result: [5, 6] ✓
 * 
 * -------------------------------------------------------------------
 * 
 * Key Points:
 * 
 * 1. Why unordered_set?
 *    - O(1) average lookup time
 *    - Automatically removes duplicates
 *    - Perfect for "presence check"
 * 
 * 2. Constructor usage:
 *    - unordered_set(nums.begin(), nums.end())
 *    - Creates set from array in one line
 *    - Clean and efficient
 * 
 * 3. Why check find() == end()?
 *    - find() returns iterator
 *    - end() means "not found"
 *    - Standard set lookup pattern
 * 
 * 4. Space tradeoff:
 *    - Uses O(n) extra space for set
 *    - But code is simple and clear
 *    - Good for readability
 * 
 * 5. Alternative (O(1) space):
 *    - Mark indices by negating values
 *    - More complex but space-efficient
 *    - Current approach prioritizes clarity
 */
