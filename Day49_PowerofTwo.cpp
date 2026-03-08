/*
 * Day 49 - Daily DSA in C++
 * Problem: 231. Power of Two (LeetCode)
 * Topics: Math, Bit Manipulation
 *
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 *
 * -------------------------------------------------------------------
 * Problem Statement:
 * Given an integer n, return true if it is a power of two. 
 * Otherwise, return false.
 * 
 * An integer n is a power of two, if there exists an integer x 
 * such that n == 2^x.
 *
 * -------------------------------------------------------------------
 * Examples:
 *
 *   Input:  n = 1
 *   Output: true
 *   Explanation: 2^0 = 1
 *
 *   Input:  n = 16
 *   Output: true
 *   Explanation: 2^4 = 16
 *
 *   Input:  n = 3
 *   Output: false
 *   Explanation: Cannot be expressed as 2^x
 *
 * -------------------------------------------------------------------
 * Key Insight:
 * Division Approach:
 * - If n is power of 2, dividing by 2 repeatedly should give 1
 * - Keep dividing while n is even
 * - If we reach 1, it's a power of 2
 * 
 * Power of 2 Pattern:
 * - Powers of 2: 1, 2, 4, 8, 16, 32, 64...
 * - Only divisible by 2 until we reach 1
 * - Non-powers will leave remainder at some point
 * 
 * Alternative (Bit Manipulation):
 * - Powers of 2 have only ONE bit set in binary
 * - Can use: n > 0 && (n & (n-1)) == 0
 * - O(1) time but uses bit tricks
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    /*
     * Function: isPowerOfTwo
     * Purpose: Check if n is a power of 2.
     *
     * Approach - Repeated Division:
     * - First check if n is positive (negative can't be power of 2)
     * - Keep dividing n by 2 while it's even
     * - If we reach 1, it's a power of 2
     * - If we reach odd number > 1, it's not
     * 
     * Why it works:
     * - Powers of 2: 1, 2, 4, 8, 16, 32...
     * - Binary: 1, 10, 100, 1000, 10000, 100000...
     * - Only divisible by 2, no other factors
     * - Dividing by 2 repeatedly removes all factors
     * - Should be left with 1 if it's power of 2
     * 
     * Steps:
     * 1. Check if n <= 0 (not power of 2)
     * 2. While n is even (divisible by 2):
     *    - Divide n by 2
     * 3. Check if n equals 1
     */
    bool isPowerOfTwo(int n) {
        // Powers of 2 must be positive
        // 0, negative numbers cannot be powers of 2
        if(n <= 0) {
            return false;
        }
        
        // Keep dividing by 2 while n is even
        // This removes all factors of 2
        while(n % 2 == 0) {
            n /= 2;
            
            // Example for n = 16:
            // 16 / 2 = 8
            // 8 / 2 = 4
            // 4 / 2 = 2
            // 2 / 2 = 1
            // Loop ends, n = 1 ✓
            
            // Example for n = 6:
            // 6 / 2 = 3
            // 3 % 2 != 0, loop ends
            // n = 3 ✗
        }
        
        // If we reached 1, all factors were 2s
        // Therefore, original n was power of 2
        return n == 1;
    }
};
int main() {
    Solution solution;
    
    // Test Case 1: 2^0
    {
        int n = 1;
        cout << "Test 1: n = " << n << endl;
        cout << "Output: " << (solution.isPowerOfTwo(n) ? "true" : "false");
        cout << " (Expected: true)" << endl;
        cout << "Explanation: 2^0 = 1" << endl;
        cout << endl;
    }
    
    // Test Case 2: 2^4
    {
        int n = 16;
        cout << "Test 2: n = " << n << endl;
        cout << "Output: " << (solution.isPowerOfTwo(n) ? "true" : "false");
        cout << " (Expected: true)" << endl;
        cout << "Explanation: 2^4 = 16" << endl;
        cout << endl;
    }
    
    // Test Case 3: Not power of 2
    {
        int n = 3;
        cout << "Test 3: n = " << n << endl;
        cout << "Output: " << (solution.isPowerOfTwo(n) ? "true" : "false");
        cout << " (Expected: false)" << endl;
        cout << "Explanation: Cannot be expressed as 2^x" << endl;
        cout << endl;
    }
    
    // Test Case 4: Zero
    {
        int n = 0;
        cout << "Test 4: n = " << n << endl;
        cout << "Output: " << (solution.isPowerOfTwo(n) ? "true" : "false");
        cout << " (Expected: false)" << endl;
        cout << "Explanation: 0 is not a power of 2" << endl;
        cout << endl;
    }
    
    // Test Case 5: Negative
    {
        int n = -16;
        cout << "Test 5: n = " << n << endl;
        cout << "Output: " << (solution.isPowerOfTwo(n) ? "true" : "false");
        cout << " (Expected: false)" << endl;
        cout << "Explanation: Negative numbers cannot be powers of 2" << endl;
        cout << endl;
    }
    
    // Test Case 6: 2^1
    {
        int n = 2;
        cout << "Test 6: n = " << n << endl;
        cout << "Output: " << (solution.isPowerOfTwo(n) ? "true" : "false");
        cout << " (Expected: true)" << endl;
        cout << "Explanation: 2^1 = 2" << endl;
        cout << endl;
    }
    
    return 0;
}

/*
 * Dry Run:
 * Input: n = 16
 * 
 * Check: 16 > 0 → true, continue
 * 
 * Iteration 1:
 * 16 % 2 == 0 → true
 * n = 16 / 2 = 8
 * 
 * Iteration 2:
 * 8 % 2 == 0 → true
 * n = 8 / 2 = 4
 * 
 * Iteration 3:
 * 4 % 2 == 0 → true
 * n = 4 / 2 = 2
 * 
 * Iteration 4:
 * 2 % 2 == 0 → true
 * n = 2 / 2 = 1
 * 
 * Iteration 5:
 * 1 % 2 == 0 → false
 * Loop ends
 * 
 * Return: n == 1 → 1 == 1 → true ✓
 * 
 * -------------------------------------------------------------------
 * 
 * Dry Run:
 * Input: n = 6
 * 
 * Check: 6 > 0 → true, continue
 * 
 * Iteration 1:
 * 6 % 2 == 0 → true
 * n = 6 / 2 = 3
 * 
 * Iteration 2:
 * 3 % 2 == 0 → false
 * Loop ends
 * 
 * Return: n == 1 → 3 == 1 → false ✓
 * 
 * -------------------------------------------------------------------
 * 
 * Key Points:
 * 
 * 1. Why check n <= 0?
 *    - 0 is not a power of 2
 *    - Negative numbers cannot be powers of 2
 *    - Powers of 2 are always positive: 1, 2, 4, 8...
 * 
 * 2. Division approach:
 *    - Simple and intuitive
 *    - Keep removing factors of 2
 *    - If only 2s were factors, we reach 1
 * 
 * 3. Time complexity:
 *    - O(log n) - divide by 2 each iteration
 *    - For n = 16: 4 iterations (log₂ 16 = 4)
 * 
 * 4. Alternative - Bit manipulation:
 *    - return n > 0 && (n & (n-1)) == 0
 *    - O(1) time
 *    - Uses property: powers of 2 have single bit set
 *    - 16 = 10000, 15 = 01111, 16 & 15 = 0
 * 
 * 5. Edge cases handled:
 *    - Zero → false
 *    - Negative → false
 *    - One → true (2^0)
 *    - Even non-powers (6, 10) → false
 */
