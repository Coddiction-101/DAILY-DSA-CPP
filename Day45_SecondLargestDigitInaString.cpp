/*
 * Day 45 - Daily DSA in C++
 * Problem: 1796. Second Largest Digit in a String (LeetCode)
 * Date: February 15, 2026
 * Difficulty: Easy
 * Topics: String, Hash Table
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1) - max 10 digits
 *
 * Problem Link:
 * https://leetcode.com/problems/second-largest-digit-in-a-string/
 *
 * -------------------------------------------------------------------
 * Problem Statement:
 * Given an alphanumeric string s, return the second largest numerical digit 
 * that appears in s, or -1 if it does not exist.
 * 
 * An alphanumeric string is a string consisting of lowercase English letters 
 * and digits.
 *
 * -------------------------------------------------------------------
 * Examples:
 *
 *   Input:  s = "dfa12321afd"
 *   Output: 2
 *   Explanation: Digits are 1, 2, 3, 2, 1. Second largest is 2.
 *
 *   Input:  s = "abc1111"
 *   Output: -1
 *   Explanation: Only one unique digit (1), no second largest.
 *
 * -------------------------------------------------------------------
 * Key Insight:
 * Track Largest and Second Largest:
 * - Iterate through string
 * - For each digit character, update largest and second largest
 * - Ignore non-digit characters
 * - Return second largest (or -1 if doesn't exist)
 * 
 * Two Variables Approach:
 * - largest: Stores the largest digit seen
 * - secondLargest: Stores the second largest digit seen
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int secondHighest(string s) {
        int largest = -1;         // Largest digit found
        int secondLargest = -1;   // Second largest digit found
        
        for(char c : s) {
            // Check if character is a digit
            if(isdigit(c)) {
                int digit = c - '0';  // Convert char to int
                
                // If this digit is larger than current largest
                if(digit > largest) {
                    secondLargest = largest;  // Old largest becomes second
                    largest = digit;          // Update largest
                }
                // If digit is between second largest and largest
                else if(digit > secondLargest && digit < largest) {
                    secondLargest = digit;    // Update second largest
                }
                // If digit equals largest or second largest, ignore
                // (we only want unique values in ranking)
            }
        }
        
        return secondLargest;
    }
};
// Main function for local testing
int main() {
    cout << "=== Day 45: Second Largest Digit in a String ===" << endl;
    Solution solution;
    
    // Test Case 1
    {
        string s = "dfa12321afd";
        cout << "Test 1: s = \"" << s << "\"" << endl;
        cout << "Output: " << solution.secondHighest(s) << " (Expected: 2)" << endl;
        cout << "Explanation: Digits are 1,2,3,2,1. Second largest is 2." << endl;
        cout << endl;
    }
    
    // Test Case 2
    {
        string s = "abc1111";
        cout << "Test 2: s = \"" << s << "\"" << endl;
        cout << "Output: " << solution.secondHighest(s) << " (Expected: -1)" << endl;
        cout << "Explanation: Only one unique digit (1)." << endl;
        cout << endl;
    }
    
    // Test Case 3
    {
        string s = "ck077";
        cout << "Test 3: s = \"" << s << "\"" << endl;
        cout << "Output: " << solution.secondHighest(s) << " (Expected: 0)" << endl;
        cout << "Explanation: Digits are 0,7,7. Second largest is 0." << endl;
        cout << endl;
    }
    
    // Test Case 4
    {
        string s = "abc";
        cout << "Test 4: s = \"" << s << "\"" << endl;
        cout << "Output: " << solution.secondHighest(s) << " (Expected: -1)" << endl;
        cout << "Explanation: No digits in string." << endl;
        cout << endl;
    }
    
    // Test Case 5
    {
        string s = "sjhtz8344";
        cout << "Test 5: s = \"" << s << "\"" << endl;
        cout << "Output: " << solution.secondHighest(s) << " (Expected: 4)" << endl;
        cout << "Explanation: Digits are 8,3,4,4. Second largest is 4." << endl;
        cout << endl;
    }
    
    return 0;
}

/*
 * Dry Run:
 * Input: s = "dfa12321afd"
 * 
 * Initial: largest = -1, secondLargest = -1
 * 
 * c='d': Not a digit, skip
 * c='f': Not a digit, skip
 * c='a': Not a digit, skip
 * 
 * c='1': digit=1
 *   1 > -1 (largest) → secondLargest=-1, largest=1
 * 
 * c='2': digit=2
 *   2 > 1 (largest) → secondLargest=1, largest=2
 * 
 * c='3': digit=3
 *   3 > 2 (largest) → secondLargest=2, largest=3
 * 
 * c='2': digit=2
 *   2 < 3 (largest) and 2 == 2 (secondLargest) → no change
 * 
 * c='1': digit=1
 *   1 < 3 (largest) and 1 < 2 (secondLargest) → no change
 * 
 * c='a','f','d': Not digits, skip
 * 
 * Final: secondLargest = 2 ✓
 * 
 * -------------------------------------------------------------------
 * 
 * Key Points:
 * 
 * 1. Why two variables?
 *    - Need to track both largest and second largest
 *    - Update both as we find new digits
 * 
 * 2. Character to digit conversion:
 *    - c - '0' converts char '5' to int 5
 *    - Works because ASCII values are sequential
 * 
 * 3. Update conditions:
 *    - If digit > largest: Update both
 *    - If largest > digit > secondLargest: Update second only
 *    - Otherwise: No update (duplicate or smaller)
 * 
 * 4. Edge cases:
 *    - No digits → secondLargest stays -1
 *    - One unique digit → secondLargest stays -1
 *    - All same digits → secondLargest stays -1
 */
