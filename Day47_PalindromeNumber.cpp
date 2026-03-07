/*
 * Problem: 9. Palindrome Number (LeetCode)
 * Difficulty: Easy
 * Topics: Math, Integer Manipulation
 * Time Complexity: O(log10(n))
 * Space Complexity: O(1)
 * Problem Link: https://leetcode.com/problems/palindrome-number/
 *
 * Problem Statement:
 * Given an integer x, return true if x is a palindrome,
 * and false otherwise.
 *
 * A palindrome number reads the same forward and backward.
 *
 * Example:
 * Input:  x = 121
 * Output: true
 *
 * Input:  x = -121
 * Output: false
 *
 * Input:  x = 10
 * Output: false
 *
 * Explanation:
 * - 121 reversed → 121 → palindrome
 * - -121 reversed → 121- → not valid
 * - 10 reversed → 01 → not same
 *
 * Key Idea:
 * Reverse the digits of the number and compare it with the original.
 * If both numbers are equal, then the number is a palindrome.
 */

class Solution {
public:
    bool isPalindrome(int x) {

        // Negative numbers cannot be palindrome
        // because of the minus sign
        if (x < 0) {
            return false;
        }

        int original = x;   // store original number
        long rev = 0;       // reversed number

        // Reverse the digits of the number
        while (x != 0) {

            int digit = x % 10;        // extract last digit
            rev = rev * 10 + digit;    // append digit to reversed number
            x /= 10;                   // remove last digit
        }

        // Compare reversed number with original
        return original == rev;
    }
};
