/*
 * Problem: 76. Minimum Window Substring (LeetCode)
 * Date: February 01, 2026
 * Difficulty: Hard
 * Topics: Hash Table, String, Sliding Window
 * Time Complexity: O(m + n) where m = s.length(), n = t.length()
 * Space Complexity: O(1) - fixed size hash maps (at most 128 ASCII characters)
 * Problem Link: https://leetcode.com/problems/minimum-window-substring/
 *
 * Problem Statement:
 * Given two strings s and t of lengths m and n respectively, return the minimum window
 * substring of s such that every character in t (including duplicates) is included in
 * the window. If there is no such substring, return the empty string "".
 *
 * Examples:
 *   Input:  s = "ADOBECODEBANC", t = "ABC"
 *   Output: "BANC"
 *   Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from t.
 *
 *   Input:  s = "a", t = "a"
 *   Output: "a"
 *   Explanation: The entire string s is the minimum window.
 *
 *   Input:  s = "a", t = "aa"
 *   Output: ""
 *   Explanation: Both 'a's from t must be included, but s has only one.
 *
 * Key Insight:
 * Sliding Window with Two Pointers:
 *   1. Use two pointers (left, right) to create a window
 *   2. Expand right to include characters until window is valid (contains all of t)
 *   3. Contract left to minimize window while keeping it valid
 *   4. Track the minimum valid window found
 * 
 * HashMap approach:
 *   - freq_t: frequency of characters needed from t
 *   - freq_window: frequency of characters in current window
 *   - required: total unique characters needed
 *   - formed: unique characters in window that match required frequency
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

/*
 * Function: minWindow
 * Purpose: Find the minimum window substring containing all characters of t.
 * Steps:
 *   1. Build frequency map for t (freq_t)
 *   2. Use two pointers (left=0, right=0) for sliding window
 *   3. Expand right: add s[right] to window, check if it matches freq_t
 *   4. When window is valid (contains all chars of t):
 *        - Update minimum window if current is smaller
 *        - Contract left: remove s[left], try to minimize window
 *   5. Return the minimum window found
 * 
 * Why it works?
 *   - We expand window until it's valid (has all chars from t)
 *   - Then we shrink from left to find minimum valid window
 *   - We track best window and update when we find smaller valid ones
 *   - Two pointers ensure we visit each character at most twice: O(m + n)
 */
string minWindow(string s, string t) {
    if (s.empty() || t.empty() || s.length() < t.length()) {
        return "";
    }
    
    // Step 1: Build frequency map for t
    unordered_map<char, int> freq_t;  // Characters needed from t
    for (char c : t) {
        freq_t[c]++;
    }
    
    int required = freq_t.size();  // Unique characters needed
    int formed = 0;                // Unique characters matched in current window
    
    // Frequency map for current window
    unordered_map<char, int> freq_window;
    
    // Pointers for sliding window
    int left = 0, right = 0;
    
    // Track minimum window
    int min_len = INT_MAX;   // Length of minimum window
    int min_left = 0;        // Starting index of minimum window
    
    // Step 2: Expand window with right pointer
    while (right < s.length()) {
        // Add character from right to window
        char c = s[right];
        freq_window[c]++;
        
        // Check if current character's frequency matches requirement
        if (freq_t.count(c) && freq_window[c] == freq_t[c]) {
            formed++;  // One more unique character matched
        }
        
        // Step 3: Try to contract window from left
        // While window is valid (contains all characters from t)
        while (left <= right && formed == required) {
            // Update minimum window if current is smaller
            if (right - left + 1 < min_len) {
                min_len = right - left + 1;
                min_left = left;
            }
            
            // Remove character from left to shrink window
            char left_char = s[left];
            freq_window[left_char]--;
            
            // Check if removing this character breaks validity
            if (freq_t.count(left_char) && freq_window[left_char] < freq_t[left_char]) {
                formed--;  // Lost one unique character match
            }
            
            left++;  // Move left pointer to shrink window
        }
        
        right++;  // Move right pointer to expand window
    }
    
    // Step 4: Return minimum window (or empty string if not found)
    return min_len == INT_MAX ? "" : s.substr(min_left, min_len);
}

// Main function for local testing
int main() {
    cout << "=== Day 32: Minimum Window Substring ===" << endl;
    
    // Test Case 1: s = "ADOBECODEBANC", t = "ABC"
    {
        string s = "ADOBECODEBANC", t = "ABC";
        string result = minWindow(s, t);
        cout << "Test 1: s = \"" << s << "\", t = \"" << t << "\"" << endl;
        cout << "Result: \"" << result << "\" (expected: \"BANC\")" << endl;
        cout << endl;
    }
    
    // Test Case 2: s = "a", t = "a"
    {
        string s = "a", t = "a";
        string result = minWindow(s, t);
        cout << "Test 2: s = \"" << s << "\", t = \"" << t << "\"" << endl;
        cout << "Result: \"" << result << "\" (expected: \"a\")" << endl;
        cout << endl;
    }
    
    // Test Case 3: s = "a", t = "aa"
    {
        string s = "a", t = "aa";
        string result = minWindow(s, t);
        cout << "Test 3: s = \"" << s << "\", t = \"" << t << "\"" << endl;
        cout << "Result: \"" << result << "\" (expected: \"\")" << endl;
        cout << endl;
    }
    
    // Test Case 4: s = "ADOBECODEBANC", t = "AABC"
    {
        string s = "ADOBECODEBANC", t = "AABC";
        string result = minWindow(s, t);
        cout << "Test 4: s = \"" << s << "\", t = \"" << t << "\"" << endl;
        cout << "Result: \"" << result << "\" (expected: \"ADOBEC\" or \"CODEBANC\")" << endl;
        cout << endl;
    }
    
    // Test Case 5: s = "ab", t = "b"
    {
        string s = "ab", t = "b";
        string result = minWindow(s, t);
        cout << "Test 5: s = \"" << s << "\", t = \"" << t << "\"" << endl;
        cout << "Result: \"" << result << "\" (expected: \"b\")" << endl;
        cout << endl;
    }
    
    return 0;
}

/*
 * Dry Run Example:
 * Input: s = "ADOBECODEBANC", t = "ABC"
 * 
 * freq_t = {A:1, B:1, C:1}, required = 3
 * 
 * Initial: left=0, right=0, formed=0, min_len=INT_MAX
 * 
 * Expansion phase:
 * right=0, s[0]='A': freq_window={A:1}, formed=1
 * right=1, s[1]='D': freq_window={A:1,D:1}, formed=1
 * right=2, s[2]='O': freq_window={A:1,D:1,O:1}, formed=1
 * right=3, s[3]='B': freq_window={A:1,D:1,O:1,B:1}, formed=2
 * right=4, s[4]='E': freq_window={A:1,D:1,O:1,B:1,E:1}, formed=2
 * right=5, s[5]='C': freq_window={A:1,D:1,O:1,B:1,E:1,C:1}, formed=3 ✓ VALID!
 * 
 * Contraction phase (formed==required):
 * Window "ADOBEC" (len=6), update min_len=6, min_left=0
 * Remove 'A': formed=2, left=1
 * 
 * Continue expansion:
 * right=6, s[6]='O': formed=2
 * ...continue until right=9, s[9]='A': formed=3 ✓ VALID!
 * Window "ODEBANC" (len=7), skip (not smaller)
 * Remove chars from left...
 * 
 * Eventually find "BANC" at indices [9-12]:
 * Window "BANC" (len=4), update min_len=4, min_left=9
 * 
 * Final: return s.substr(9, 4) = "BANC" ✓
 * 
 * Key Points:
 * - Sliding window with two pointers: expand right, contract left
 * - HashMap to track character frequencies
 * - formed vs required to check window validity
 * - Update minimum only when window is valid
 * - Time: O(m+n), Space: O(1) - at most 128 ASCII chars in maps
 */
