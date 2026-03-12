/*
 * Day 54 - Daily DSA in C++
 * Problem: 66. Plus One (LeetCode)
 * Difficulty: Easy
 * Topics: Array, Math
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1) average, O(n) worst case
 *
 * Problem Link:
 * https://leetcode.com/problems/plus-one/
 *
 * -------------------------------------------------------------------
 * Problem Statement:
 * You are given a large integer represented as an integer array digits, 
 * where each digits[i] is the ith digit of the integer. The digits are 
 * ordered from most significant to least significant in left-to-right order. 
 * The large integer does not contain any leading 0's.
 * 
 * Increment the large integer by one and return the resulting array of digits.
 *
 * -------------------------------------------------------------------
 * Examples:
 *
 *   Input:  digits = [1,2,3]
 *   Output: [1,2,4]
 *   Explanation: 123 + 1 = 124
 *
 *   Input:  digits = [4,3,2,1]
 *   Output: [4,3,2,2]
 *   Explanation: 4321 + 1 = 4322
 *
 *   Input:  digits = [9]
 *   Output: [1,0]
 *   Explanation: 9 + 1 = 10
 *
 *   Input:  digits = [9,9,9]
 *   Output: [1,0,0,0]
 *   Explanation: 999 + 1 = 1000
 *
 * -------------------------------------------------------------------
 * Key Insight:
 * Carry Propagation:
 * - Start from rightmost digit (least significant)
 * - Add 1
 * - If < 10, done (no carry)
 * - If = 10, set to 0 and carry to next digit
 * - If all digits become 0, add 1 at front
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
     * Function: plusOne
     * Purpose: Add 1 to large integer represented as digit array.
     *
     * Approach - Right to Left with Carry:
     * - Traverse from rightmost digit
     * - Increment current digit
     * - If < 10, no carry → return
     * - If = 10, set to 0 and continue (carry)
     * - If loop completes, all were 9 → insert 1 at front
     * 
     * Steps:
     * 1. Iterate from right to left
     * 2. Add 1 to current digit
     * 3. If no overflow (< 10), return immediately
     * 4. If overflow, set to 0 and continue
     * 5. After loop, if still here → all 9s → add 1 at front
     */
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        // Traverse from right to left (least to most significant)
        for(int i = n - 1; i >= 0; i--) {
            // Increment current digit
            digits[i]++;
            
            // If no carry (digit < 10), we're done
            // This is the most common case
            if(digits[i] < 10) {
                return digits;
            }
            
            // Carry occurred (digit became 10)
            // Set current digit to 0 and continue to next
            digits[i] = 0;
        }
        
        // If we reach here, all digits were 9
        // Example: [9,9,9] became [0,0,0]
        // Need to add 1 at the beginning
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

// Main function for local testing
int main() {
    cout << "=== Day 54: Plus One ===" << endl;
    Solution solution;
    
    // Test Case 1: Simple increment
    {
        vector<int> digits = {1,2,3};
        cout << "Test 1: digits = [1,2,3]" << endl;
        vector<int> result = solution.plusOne(digits);
        cout << "Output: [";
        for(int i = 0; i < result.size(); i++) {
            cout << result[i];
            if(i < result.size() - 1) cout << ",";
        }
        cout << "] (Expected: [1,2,4])" << endl;
        cout << "Explanation: 123 + 1 = 124" << endl << endl;
    }
    
    // Test Case 2: No carry
    {
        vector<int> digits = {4,3,2,1};
        cout << "Test 2: digits = [4,3,2,1]" << endl;
        vector<int> result = solution.plusOne(digits);
        cout << "Output: [";
        for(int i = 0; i < result.size(); i++) {
            cout << result[i];
            if(i < result.size() - 1) cout << ",";
        }
        cout << "] (Expected: [4,3,2,2])" << endl;
        cout << "Explanation: 4321 + 1 = 4322" << endl << endl;
    }
    
    // Test Case 3: Single 9
    {
        vector<int> digits = {9};
        cout << "Test 3: digits = [9]" << endl;
        vector<int> result = solution.plusOne(digits);
        cout << "Output: [";
        for(int i = 0; i < result.size(); i++) {
            cout << result[i];
            if(i < result.size() - 1) cout << ",";
        }
        cout << "] (Expected: [1,0])" << endl;
        cout << "Explanation: 9 + 1 = 10" << endl << endl;
    }
    
    // Test Case 4: All 9s
    {
        vector<int> digits = {9,9,9};
        cout << "Test 4: digits = [9,9,9]" << endl;
        vector<int> result = solution.plusOne(digits);
        cout << "Output: [";
        for(int i = 0; i < result.size(); i++) {
            cout << result[i];
            if(i < result.size() - 1) cout << ",";
        }
        cout << "] (Expected: [1,0,0,0])" << endl;
        cout << "Explanation: 999 + 1 = 1000" << endl << endl;
    }
    
    // Test Case 5: Carry in middle
    {
        vector<int> digits = {1,9,9};
        cout << "Test 5: digits = [1,9,9]" << endl;
        vector<int> result = solution.plusOne(digits);
        cout << "Output: [";
        for(int i = 0; i < result.size(); i++) {
            cout << result[i];
            if(i < result.size() - 1) cout << ",";
        }
        cout << "] (Expected: [2,0,0])" << endl;
        cout << "Explanation: 199 + 1 = 200" << endl << endl;
    }
    
    return 0;
}

/*
 * Dry Run:
 * Input: digits = [1,2,9]
 * 
 * i = 2 (rightmost):
 * digits[2]++ → 9 becomes 10
 * 10 < 10? NO
 * digits[2] = 0
 * Array: [1,2,0]
 * 
 * i = 1:
 * digits[1]++ → 2 becomes 3
 * 3 < 10? YES → return [1,3,0] ✓
 * 
 * -------------------------------------------------------------------
 * 
 * Dry Run:
 * Input: digits = [9,9,9]
 * 
 * i = 2:
 * digits[2]++ → 9 becomes 10
 * 10 < 10? NO
 * digits[2] = 0
 * Array: [9,9,0]
 * 
 * i = 1:
 * digits[1]++ → 9 becomes 10
 * 10 < 10? NO
 * digits[1] = 0
 * Array: [9,0,0]
 * 
 * i = 0:
 * digits[0]++ → 9 becomes 10
 * 10 < 10? NO
 * digits[0] = 0
 * Array: [0,0,0]
 * 
 * Loop ends
 * Insert 1 at beginning
 * Result: [1,0,0,0] ✓
 * 
 * -------------------------------------------------------------------
 * 
 * Key Points:
 * 
 * 1. Why traverse right to left?
 *    - Addition starts from least significant digit
 *    - Carry propagates left
 *    - Natural direction for this operation
 * 
 * 2. Early return optimization:
 *    - Most numbers don't end in 9
 *    - Can return immediately (no carry)
 *    - Very efficient for common case
 * 
 * 3. Why digits[i] < 10?
 *    - After increment, can be 0-9 (no carry) or 10 (carry)
 *    - If < 10, no carry needed
 *    - If = 10, need to carry
 * 
 * 4. Insert at beginning:
 *    - Only happens when all digits are 9
 *    - Rare case but must handle
 *    - Creates new array with extra space
 * 
 * 5. Space complexity:
 *    - O(1) for most cases (modify in-place)
 *    - O(n) for all 9s (new array needed)
 */
