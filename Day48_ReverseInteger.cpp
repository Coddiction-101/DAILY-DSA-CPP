/*
 * Day 46 - Daily DSA in C++
 * Problem: 7. Reverse Integer (LeetCode)
 * Difficulty: Medium
 * Topics: Math
 *
 * Time Complexity: O(log x) - number of digits
 * Space Complexity: O(1)
 *
 * Problem Link:
 * https://leetcode.com/problems/reverse-integer/
 *
 * -------------------------------------------------------------------
 * Problem Statement:
 * Given a signed 32-bit integer x, return x with its digits reversed.
 * If reversing x causes the value to go outside the signed 32-bit integer 
 * range [-2³¹, 2³¹ - 1], then return 0.
 * 
 * Assume the environment does not allow you to store 64-bit integers 
 * (signed or unsigned).
 *
 * -------------------------------------------------------------------
 * Examples:
 *
 *   Input:  x = 123
 *   Output: 321
 *
 *   Input:  x = -123
 *   Output: -321
 *
 *   Input:  x = 120
 *   Output: 21
 *   Explanation: Trailing zeros are removed
 *
 *   Input:  x = 0
 *   Output: 0
 *
 * -------------------------------------------------------------------
 * Key Insight:
 * Math-Based Reversal with Overflow Check:
 * - Extract digits from right to left using modulo (%)
 * - Build reversed number by multiplying by 10 and adding digit
 * - Check for overflow BEFORE multiplication to avoid integer overflow
 * 
 * Overflow Detection:
 * - INT_MAX = 2,147,483,647
 * - INT_MIN = -2,147,483,648
 * - If rev > INT_MAX/10, next multiplication will overflow
 * - If rev < INT_MIN/10, next multiplication will underflow
 * 
 * Why check BEFORE multiplication?
 * - If we multiply first, overflow already happened
 * - Check rev > INT_MAX/10 prevents overflow in next step
 * 
 * Visual Example:
 * x = 123
 * Step 1: digit=3, rev=3
 * Step 2: digit=2, rev=32
 * Step 3: digit=1, rev=321
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    /*
     * Function: reverse
     * Purpose: Reverse the digits of a signed 32-bit integer.
     *
     * Approach - Math-Based Reversal:
     * - Extract last digit using modulo: x % 10
     * - Build reversed number: rev = rev * 10 + digit
     * - Remove last digit: x = x / 10
     * - Check overflow BEFORE each multiplication
     * 
     * Overflow Prevention:
     * - Before rev = rev * 10 + digit
     * - Check: rev > INT_MAX/10 or rev < INT_MIN/10
     * - If true, next step will overflow → return 0
     * 
     * Steps:
     * 1. While x is not 0:
     *    a. Extract rightmost digit (x % 10)
     *    b. Check if adding this digit will cause overflow
     *    c. If safe, build reversed number
     *    d. Remove processed digit from x
     * 2. Return reversed number
     */
    int reverse(int x) {
        int rev = 0;  // Reversed number being built
        
        // Process all digits of x
        while(x != 0) {
            // Extract the rightmost digit
            int digit = x % 10;
            
            // CRITICAL: Check for overflow BEFORE multiplication
            // Why divide INT_MAX and INT_MIN by 10?
            // - If rev > INT_MAX/10, then rev*10 will exceed INT_MAX
            // - If rev < INT_MIN/10, then rev*10 will go below INT_MIN
            // 
            // Example overflow scenario:
            // INT_MAX = 2,147,483,647
            // INT_MAX/10 = 214,748,364
            // If rev = 214,748,365 (> INT_MAX/10)
            // Then rev * 10 = 2,147,483,650 > INT_MAX → OVERFLOW!
            if(rev > INT_MAX/10 || rev < INT_MIN/10) {
                return 0;  // Would overflow, return 0 as specified
            }
            
            // Safe to proceed: Build reversed number
            // Multiply current result by 10 to shift left
            // Add the extracted digit
            rev = rev * 10 + digit;
            
            // Remove the processed digit from x
            // Integer division automatically truncates
            x /= 10;
            
            // Example iteration for x=123:
            // Iteration 1: digit=3, rev=0*10+3=3, x=12
            // Iteration 2: digit=2, rev=3*10+2=32, x=1
            // Iteration 3: digit=1, rev=32*10+1=321, x=0
        }
        
        // Return the fully reversed number
        return rev;
    }
};
// Main function for local testing
int main() {
    cout << "=== Day 46: Reverse Integer ===" << endl;
    Solution solution;
    
    // Test Case 1: Positive number
    {
        int x = 123;
        cout << "Test 1: x = " << x << endl;
        cout << "Output: " << solution.reverse(x) << " (Expected: 321)" << endl;
        cout << "Explanation: Reverse digits of 123" << endl;
        cout << endl;
    }
    
    // Test Case 2: Negative number
    {
        int x = -123;
        cout << "Test 2: x = " << x << endl;
        cout << "Output: " << solution.reverse(x) << " (Expected: -321)" << endl;
        cout << "Explanation: Sign is preserved" << endl;
        cout << endl;
    }
    
    // Test Case 3: Trailing zeros
    {
        int x = 120;
        cout << "Test 3: x = " << x << endl;
        cout << "Output: " << solution.reverse(x) << " (Expected: 21)" << endl;
        cout << "Explanation: Leading zeros in reversed number are dropped" << endl;
        cout << endl;
    }
    
    // Test Case 4: Zero
    {
        int x = 0;
        cout << "Test 4: x = " << x << endl;
        cout << "Output: " << solution.reverse(x) << " (Expected: 0)" << endl;
        cout << "Explanation: Zero remains zero" << endl;
        cout << endl;
    }
    
    // Test Case 5: Overflow case
    {
        int x = 1534236469;
        cout << "Test 5: x = " << x << endl;
        cout << "Output: " << solution.reverse(x) << " (Expected: 0)" << endl;
        cout << "Explanation: Reversed would be 9646324351 > INT_MAX" << endl;
        cout << endl;
    }
    
    // Test Case 6: Single digit
    {
        int x = 9;
        cout << "Test 6: x = " << x << endl;
        cout << "Output: " << solution.reverse(x) << " (Expected: 9)" << endl;
        cout << "Explanation: Single digit remains same" << endl;
        cout << endl;
    }
    
    return 0;
}

/*
 * Dry Run:
 * Input: x = 123
 * 
 * Initial: rev = 0
 * 
 * Iteration 1:
 * x = 123
 * digit = 123 % 10 = 3
 * Overflow check: 0 > INT_MAX/10? No, 0 < INT_MIN/10? No → Safe
 * rev = 0 * 10 + 3 = 3
 * x = 123 / 10 = 12
 * 
 * Iteration 2:
 * x = 12
 * digit = 12 % 10 = 2
 * Overflow check: 3 > INT_MAX/10? No, 3 < INT_MIN/10? No → Safe
 * rev = 3 * 10 + 2 = 32
 * x = 12 / 10 = 1
 * 
 * Iteration 3:
 * x = 1
 * digit = 1 % 10 = 1
 * Overflow check: 32 > INT_MAX/10? No, 32 < INT_MIN/10? No → Safe
 * rev = 32 * 10 + 1 = 321
 * x = 1 / 10 = 0
 * 
 * Loop ends (x = 0)
 * Return rev = 321 ✓
 * 
 * -------------------------------------------------------------------
 * 
 * Dry Run - Negative Number:
 * Input: x = -123
 * 
 * Initial: rev = 0
 * 
 * Iteration 1:
 * x = -123
 * digit = -123 % 10 = -3 (in C++, % preserves sign)
 * rev = 0 * 10 + (-3) = -3
 * x = -123 / 10 = -12
 * 
 * Iteration 2:
 * x = -12
 * digit = -12 % 10 = -2
 * rev = -3 * 10 + (-2) = -32
 * x = -12 / 10 = -1
 * 
 * Iteration 3:
 * x = -1
 * digit = -1 % 10 = -1
 * rev = -32 * 10 + (-1) = -321
 * x = -1 / 10 = 0
 * 
 * Return rev = -321 ✓
 * 
 * -------------------------------------------------------------------
 * 
 * Dry Run - Overflow Case:
 * Input: x = 1534236469
 * 
 * Reversed would be: 9646324351
 * INT_MAX = 2,147,483,647
 * 9646324351 > 2,147,483,647 → OVERFLOW!
 * 
 * At some iteration:
 * rev = 964632435
 * Next digit = 1
 * Check: 964632435 > INT_MAX/10 (214748364)? YES!
 * Return 0 ✓
 * 
 * -------------------------------------------------------------------
 * 
 * Key Points:
 * 
 * 1. Modulo and Division:
 *    - x % 10: Extracts rightmost digit
 *    - x / 10: Removes rightmost digit
 *    - Works for both positive and negative
 * 
 * 2. Sign Handling:
 *    - In C++, % and / preserve sign
 *    - -123 % 10 = -3 (not 7)
 *    - -123 / 10 = -12 (not -13)
 *    - No special handling needed!
 * 
 * 3. Overflow Check Timing:
 *    - MUST check BEFORE multiplication
 *    - Checking after is too late
 *    - rev > INT_MAX/10 predicts overflow
 * 
 * 4. Why INT_MAX/10?
 *    - INT_MAX = 2,147,483,647
 *    - If rev > 214,748,364 (INT_MAX/10)
 *    - Then rev * 10 will exceed INT_MAX
 *    - Prevents overflow in next step
 * 
 * 5. Edge case - Trailing zeros:
 *    - 120 reversed → 021 → 21
 *    - Leading zeros automatically dropped
 *    - Integer type doesn't store leading zeros
 * 
 * 6. Single digit:
 *    - Loop runs once
 *    - Returns same digit
 * 
 * 7. Zero:
 *    - Loop doesn't run (x = 0)
 *    - Returns 0
 * 
 * 8. Time Complexity:
 *    - O(log₁₀ x) - proportional to number of digits
 *    - 123 has 3 digits → 3 iterations
 *    - More precisely: O(log x)
 * 
 * 9. Space Complexity:
 *    - O(1) - only using constant variables
 *    - No arrays, no recursion stack
 * 
 * 10. Interview Tips:
 *     - Explain overflow check clearly
 *     - Mention sign handling in C++
 *     - Test with negative numbers
 *     - Test with trailing zeros
 *     - Test overflow case
 */
