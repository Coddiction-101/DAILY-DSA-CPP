/*
 * Problem: 169. Majority Element (LeetCode)
 * Date: February 04, 2026
 * Difficulty: Easy
 * Topics: Arrays, Hash Table, Boyer-Moore Voting Algorithm
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * Problem Link: https://leetcode.com/problems/majority-element/
 *
 * Problem Statement:
 * Given an array nums of size n, return the majority element.
 * The majority element is the element that appears more than ⌊n / 2⌋ times.
 * You may assume that the majority element always exists in the array.
 *
 * Examples:
 *   Input:  nums = [3,2,3]
 *   Output: 3
 *   Explanation: 3 appears 2 times, which is more than 3/2 = 1.5 times.
 *
 *   Input:  nums = [2,2,1,1,1,2,2]
 *   Output: 2
 *   Explanation: 2 appears 4 times, which is more than 7/2 = 3.5 times.
 *
 * Key Insight:
 * Boyer-Moore Voting Algorithm:
 *   - The majority element appears MORE than n/2 times
 *   - If we pair each majority element with a different element,
 *     the majority element will STILL have unpaired instances remaining
 *   - We maintain a candidate and count; elements vote for or against
 *   - The surviving candidate is guaranteed to be the majority element
 */

#include <iostream>
#include <vector>
using namespace std;

/*
 * Function: majorityElement
 * Purpose: Find the element that appears more than n/2 times using Boyer-Moore algorithm.
 * Steps:
 *   1. Initialize count = 0 and candidate = 0
 *   2. Loop through each element:
 *        - If count is 0, select current element as new candidate
 *        - If current element equals candidate, increment count (vote for)
 *        - If current element differs from candidate, decrement count (vote against)
 *   3. Return the surviving candidate
 * 
 * Why it works?
 *   - Majority element appears > n/2 times, so it will always survive the voting
 *   - Even if candidate changes multiple times, majority will eventually win
 *   - Each cancellation removes one majority and one non-majority element
 *   - Since majority > n/2, it cannot be completely cancelled out
 */
int majorityElement(vector<int>& nums) {
    int count = 0;      // Counter for candidate frequency
    int candidate = 0;  // Current majority candidate
    
    // Phase 1: Find the candidate using voting
    for (int num : nums) {
        if (count == 0) {
            // Count reached 0, select new candidate
            candidate = num;
        }
        
        // Vote: increment if same, decrement if different
        count += (num == candidate) ? 1 : -1;
    }
    
    // Phase 2: Verification (not needed as problem guarantees majority exists)
    // But if we needed to verify:
    // int verify_count = 0;
    // for (int num : nums) {
    //     if (num == candidate) verify_count++;
    // }
    // return (verify_count > nums.size() / 2) ? candidate : -1;
    
    return candidate;
}

// Main function for local testing
int main() {
    cout << "=== Day 35: Majority Element ===" << endl;
    
    // Test Case 1: [3,2,3] → majority = 3
    {
        vector<int> nums = {3, 2, 3};
        int result = majorityElement(nums);
        cout << "Test 1: [3,2,3]" << endl;
        cout << "Majority Element: " << result << " (expected: 3)" << endl;
        cout << endl;
    }
    
    // Test Case 2: [2,2,1,1,1,2,2] → majority = 2
    {
        vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
        int result = majorityElement(nums);
        cout << "Test 2: [2,2,1,1,1,2,2]" << endl;
        cout << "Majority Element: " << result << " (expected: 2)" << endl;
        cout << endl;
    }
    
    // Test Case 3: [1] → majority = 1 (single element)
    {
        vector<int> nums = {1};
        int result = majorityElement(nums);
        cout << "Test 3: [1]" << endl;
        cout << "Majority Element: " << result << " (expected: 1)" << endl;
        cout << endl;
    }
    
    // Test Case 4: [5,5,5,5,5] → majority = 5 (all same)
    {
        vector<int> nums = {5, 5, 5, 5, 5};
        int result = majorityElement(nums);
        cout << "Test 4: [5,5,5,5,5]" << endl;
        cout << "Majority Element: " << result << " (expected: 5)" << endl;
        cout << endl;
    }
    
    // Test Case 5: [1,2,3,4,4,4,4] → majority = 4
    {
        vector<int> nums = {1, 2, 3, 4, 4, 4, 4};
        int result = majorityElement(nums);
        cout << "Test 5: [1,2,3,4,4,4,4]" << endl;
        cout << "Majority Element: " << result << " (expected: 4)" << endl;
        cout << endl;
    }
    
    // Test Case 6: [-1,-1,-1,2,2] → majority = -1 (negative numbers)
    {
        vector<int> nums = {-1, -1, -1, 2, 2};
        int result = majorityElement(nums);
        cout << "Test 6: [-1,-1,-1,2,2]" << endl;
        cout << "Majority Element: " << result << " (expected: -1)" << endl;
        cout << endl;
    }
    
    return 0;
}

/*
 * Dry Run Example:
 * Input: nums = [2,2,1,1,1,2,2]
 * 
 * Initial: count = 0, candidate = 0
 * 
 * i=0, num=2: count==0 → candidate=2, count=1
 * i=1, num=2: 2==2 → count=2
 * i=2, num=1: 1!=2 → count=1
 * i=3, num=1: 1!=2 → count=0
 * i=4, num=1: count==0 → candidate=1, count=1
 * i=5, num=2: 2!=1 → count=0
 * i=6, num=2: count==0 → candidate=2, count=1
 * 
 * Final: candidate = 2 (Majority Element) ✓
 * 
 * Key Points:
 * - Candidate changed from 2 → 1 → 2, but majority (2) survived
 * - Each pair cancellation: (2,1), (2,1), leaving unpaired 2s
 * - O(n) time with single pass, O(1) space
 * - No extra data structures needed
 */
