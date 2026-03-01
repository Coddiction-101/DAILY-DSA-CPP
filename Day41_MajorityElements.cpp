/*
 * Day 41 - Daily DSA in C++
 * Problem: 169. Majority Element (LeetCode)
 * Date: February 11, 2026
 * Difficulty: Easy
 * Topics: Array, Hash Table, Divide and Conquer, Sorting, Counting
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 *
 * Problem Link:
 * https://leetcode.com/problems/majority-element/
 *
 * -------------------------------------------------------------------
 * Problem Statement:
 * Given an array nums of size n, return the majority element.
 * 
 * The majority element is the element that appears more than ⌊n/2⌋ times.
 * You may assume that the majority element always exists in the array.
 *
 * -------------------------------------------------------------------
 * Examples:
 *
 *   Input:  nums = [3,2,3]
 *   Output: 3
 *   Explanation: 3 appears 2 times (more than 3/2 = 1)
 *
 *   Input:  nums = [2,2,1,1,1,2,2]
 *   Output: 2
 *   Explanation: 2 appears 4 times (more than 7/2 = 3)
 *
 * -------------------------------------------------------------------
 * Key Insight:
 * Boyer-Moore Voting Algorithm:
 * - Think of it as elements "voting" against each other
 * - Majority element (appears > n/2 times) will survive
 * - When different elements meet, they "cancel out"
 * - The element that remains is the majority
 * 
 * Why it works:
 * - Majority element count > all other elements combined
 * - Even if all others cancel out the majority
 * - Majority will still have votes remaining
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    /*
     * Function: majorityElement
     * Purpose: Find the element that appears more than n/2 times.
     *
     * Approach - Boyer-Moore Voting Algorithm:
     * - Maintain a candidate and a count
     * - When count is 0, pick new candidate
     * - When we see candidate, increment count
     * - When we see different element, decrement count
     * - The surviving candidate is the majority element
     * 
     * Steps:
     * 1. Initialize: count=0, candidate=0
     * 2. For each element:
     *    - If count=0: Choose this as new candidate
     *    - If element==candidate: count++
     *    - If element!=candidate: count--
     * 3. Return candidate (guaranteed to be majority)
     */
    int majorityElement(vector<int>& nums) {
        int count = 0;      // Vote count for current candidate
        int candidate = 0;  // Current majority candidate
        
        // Phase 1: Find the candidate through voting
        for(int num : nums) {
            // When count reaches 0, we need a new candidate
            // This happens when previous candidate was cancelled out
            if(count == 0) {
                candidate = num;  // Set new candidate
            }
            
            // Voting phase:
            // - If current element matches candidate, increase vote (+1)
            // - If different element, decrease vote (-1) [cancellation]
            count += (num == candidate) ? 1 : -1;
        }
        
        // Phase 2: Return the candidate
        // Note: Problem guarantees majority exists, so no verification needed
        return candidate;
    }
};
// Main function for local testing
int main() {
    cout << "=== Day 41: Majority Element ===" << endl;
    Solution solution;
    
    // Test Case 1
    {
        vector<int> nums = {3,2,3};
        cout << "Test 1: nums = [3,2,3]" << endl;
        cout << "Output: " << solution.majorityElement(nums) << " (Expected: 3)" << endl;
        cout << "Explanation: 3 appears 2 times (more than 3/2 = 1)" << endl;
        cout << endl;
    }
    
    // Test Case 2
    {
        vector<int> nums = {2,2,1,1,1,2,2};
        cout << "Test 2: nums = [2,2,1,1,1,2,2]" << endl;
        cout << "Output: " << solution.majorityElement(nums) << " (Expected: 2)" << endl;
        cout << "Explanation: 2 appears 4 times (more than 7/2 = 3)" << endl;
        cout << endl;
    }
    
    // Test Case 3 (Edge Case - Single Element)
    {
        vector<int> nums = {1};
        cout << "Test 3: nums = [1]" << endl;
        cout << "Output: " << solution.majorityElement(nums) << " (Expected: 1)" << endl;
        cout << "Explanation: Single element is always majority" << endl;
        cout << endl;
    }
    
    // Test Case 4 (All Same)
    {
        vector<int> nums = {5,5,5,5};
        cout << "Test 4: nums = [5,5,5,5]" << endl;
        cout << "Output: " << solution.majorityElement(nums) << " (Expected: 5)" << endl;
        cout << "Explanation: All elements are same" << endl;
        cout << endl;
    }
    
    // Test Case 5 (Majority at End)
    {
        vector<int> nums = {1,2,3,4,4,4,4};
        cout << "Test 5: nums = [1,2,3,4,4,4,4]" << endl;
        cout << "Output: " << solution.majorityElement(nums) << " (Expected: 4)" << endl;
        cout << "Explanation: 4 appears 4 times (more than 7/2 = 3)" << endl;
        cout << endl;
    }
    
    return 0;
}

/*
 * Dry Run:
 * Input: nums = [2,2,1,1,1,2,2]
 * 
 * Initial: count=0, candidate=0
 * 
 * i=0, num=2: count==0 → candidate=2, count=1
 * i=1, num=2: count=2 (2 supports 2)
 * i=2, num=1: count=1 (1 opposes 2, cancellation)
 * i=3, num=1: count=0 (another cancellation)
 * i=4, num=1: count==0 → candidate=1, count=1
 * i=5, num=2: count=0 (2 opposes 1)
 * i=6, num=2: count==0 → candidate=2, count=1
 * 
 * Return: 2 ✓
 * 
 * -------------------------------------------------------------------
 * 
 * Why Boyer-Moore Works:
 * 
 * Let majority element appear m times
 * Let all others combined appear o times
 * Given: m > n/2, which means m > o
 * 
 * In worst case:
 * - Every other element cancels one majority element
 * - Cancellations = o
 * - Remaining majority = m - o > 0 (since m > o)
 * - Majority element will always remain!
 * 
 * -------------------------------------------------------------------
 * 
 * Alternative Approaches:
 * 
 * 1. HashMap (O(n) space):
 *    unordered_map<int, int> freq;
 *    for(int num : nums) {
 *        freq[num]++;
 *        if(freq[num] > n/2) return num;
 *    }
 * 
 * 2. Sorting (O(n log n) time):
 *    sort(nums.begin(), nums.end());
 *    return nums[n/2];
 *    (Majority must be at middle after sorting)
 * 
 * Boyer-Moore is OPTIMAL: O(n) time, O(1) space!
 * 
 * -------------------------------------------------------------------
 * 
 * Key Points:
 * 
 * 1. Why count becomes 0?
 *    - Equal number of candidate and non-candidate seen
 *    - They cancelled each other out, need new candidate
 * 
 * 2. Order doesn't matter:
 *    - Majority will emerge regardless of arrangement
 * 
 * 3. Edge cases handled:
 *    - Single element: Becomes candidate immediately
 *    - All same: count keeps increasing
 *    - Majority at end: Eventually becomes candidate
 * 
 * 4. Interview tip:
 *    - Mention all three approaches
 *    - Explain Boyer-Moore as optimal
 *    - Show understanding of voting logic
 */
