/*
 * Day 52 - Daily DSA in C++
 * Problem: 263. Ugly Number (LeetCode)
 * Difficulty: Easy
 * Topics: Math
 *
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 *
 * Problem Link:
 * https://leetcode.com/problems/ugly-number/
 *
 * -------------------------------------------------------------------
 * Problem Statement:
 * An ugly number is a positive integer whose prime factors are limited 
 * to 2, 3, and 5.
 * 
 * Given an integer n, return true if n is an ugly number.
 *
 * -------------------------------------------------------------------
 * Examples:
 *
 *   Input:  n = 6
 *   Output: true
 *   Explanation: 6 = 2 × 3
 *
 *   Input:  n = 1
 *   Output: true
 *   Explanation: 1 has no prime factors (ugly by convention)
 *
 *   Input:  n = 14
 *   Output: false
 *   Explanation: 14 = 2 × 7 (includes 7)
 *
 * -------------------------------------------------------------------
 * Key Insight:
 * Keep dividing by 2, 3, and 5. If we reach 1, it's ugly.
 * If we get stuck on another number, it has other prime factors.
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isUgly(int n) {
        // Ugly numbers must be positive
        if(n <= 0) return false;
        
        // Remove all factors of 2
        while(n % 2 == 0) n /= 2;
        
        // Remove all factors of 3
        while(n % 3 == 0) n /= 3;
        
        // Remove all factors of 5
        while(n % 5 == 0) n /= 5;
        
        // If only 2, 3, 5 were factors, n should be 1 now
        return n == 1;
    }
};

// Main function for local testing
int main() {
    cout << "=== Day 52: Ugly Number ===" << endl;
    Solution solution;
    
    // Test Case 1
    {
        int n = 6;
        cout << "Test 1: n = " << n << endl;
        cout << "Output: " << (solution.isUgly(n) ? "true" : "false");
        cout << " (Expected: true)" << endl;
        cout << "Explanation: 6 = 2 × 3" << endl << endl;
    }
    
    // Test Case 2
    {
        int n = 1;
        cout << "Test 2: n = " << n << endl;
        cout << "Output: " << (solution.isUgly(n) ? "true" : "false");
        cout << " (Expected: true)" << endl;
        cout << "Explanation: 1 has no prime factors" << endl << endl;
    }
    
    // Test Case 3
    {
        int n = 14;
        cout << "Test 3: n = " << n << endl;
        cout << "Output: " << (solution.isUgly(n) ? "true" : "false");
        cout << " (Expected: false)" << endl;
        cout << "Explanation: 14 = 2 × 7 (includes 7)" << endl << endl;
    }
    
    // Test Case 4
    {
        int n = 0;
        cout << "Test 4: n = " << n << endl;
        cout << "Output: " << (solution.isUgly(n) ? "true" : "false");
        cout << " (Expected: false)" << endl;
        cout << "Explanation: 0 is not positive" << endl << endl;
    }
    
    // Test Case 5
    {
        int n = -6;
        cout << "Test 5: n = " << n << endl;
        cout << "Output: " << (solution.isUgly(n) ? "true" : "false");
        cout << " (Expected: false)" << endl;
        cout << "Explanation: Negative numbers are not ugly" << endl << endl;
    }
    
    return 0;
}

/*
 * Dry Run:
 * Input: n = 30
 * 
 * Check: 30 > 0 → true, continue
 * 
 * Divide by 2:
 * 30 % 2 == 0 → n = 30/2 = 15
 * 15 % 2 != 0 → stop
 * 
 * Divide by 3:
 * 15 % 3 == 0 → n = 15/3 = 5
 * 5 % 3 != 0 → stop
 * 
 * Divide by 5:
 * 5 % 5 == 0 → n = 5/5 = 1
 * 1 % 5 != 0 → stop
 * 
 * Return: n == 1 → 1 == 1 → true ✓
 * 
 * -------------------------------------------------------------------
 * 
 * Key Points:
 * 
 * 1. Why divide repeatedly?
 *    - Remove ALL occurrences of each prime factor
 *    - Example: 8 = 2³ needs three divisions by 2
 * 
 * 2. Why check n <= 0?
 *    - Ugly numbers are positive by definition
 *    - 0 and negatives return false immediately
 * 
 * 3. Why n == 1 at end?
 *    - If all factors were 2, 3, 5 → left with 1
 *    - If other factors exist → left with that number
 *    - Example: 14 = 2 × 7 → left with 7
 */
