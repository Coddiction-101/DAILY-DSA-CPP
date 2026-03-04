/*
 * Day 44 - Daily DSA in C++
 * Problem: 20. Valid Parentheses (LeetCode)
 * Date: February 14, 2026
 * Difficulty: Easy
 * Topics: String, Stack
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 *
 * Problem Link:
 * https://leetcode.com/problems/valid-parentheses/
 *
 * -------------------------------------------------------------------
 * Problem Statement:
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
 * determine if the input string is valid.
 * 
 * An input string is valid if:
 * 1. Open brackets must be closed by the same type of brackets.
 * 2. Open brackets must be closed in the correct order.
 * 3. Every close bracket has a corresponding open bracket of the same type.
 *
 * -------------------------------------------------------------------
 * Examples:
 *
 *   Input:  s = "()"
 *   Output: true
 *
 *   Input:  s = "()[]{}"
 *   Output: true
 *
 *   Input:  s = "(]"
 *   Output: false
 *
 *   Input:  s = "([)]"
 *   Output: false
 *
 *   Input:  s = "{[]}"
 *   Output: true
 *
 * -------------------------------------------------------------------
 * Key Insight:
 * Stack (LIFO - Last In First Out):
 * - Opening brackets: Push to stack
 * - Closing brackets: Pop from stack and check if they match
 * - Valid if stack is empty at the end
 * 
 * Why Stack?
 * The last opened bracket must be the first to close (LIFO property)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;  // Stack to store opening brackets
        
        for(int c : s) {
            // If opening bracket, push to stack
            if(c == '(' || c == '{' || c == '[') {
                st.push(c);
            } 
            // If closing bracket, check matching
            else {
                // Stack empty means no matching opening bracket
                if(st.empty()) return false;
                
                char top = st.top();
                
                // Check if closing bracket matches the last opening bracket
                if((c == ')' && top == '(') ||
                   (c == '}' && top == '{') || 
                   (c == ']' && top == '[')) {
                    st.pop();  // Match found, remove from stack
                } else {
                    return false;  // Mismatch
                }
            }
        }
        
        // Valid only if all brackets are matched (stack is empty)
        return st.empty();
    }
};
// Main function for local testing
int main() {
    cout << "=== Day 44: Valid Parentheses ===" << endl;
    Solution solution;
    
    // Test Case 1
    {
        string s = "()";
        cout << "Test 1: s = \"" << s << "\"" << endl;
        cout << "Output: " << (solution.isValid(s) ? "true" : "false") << " (Expected: true)" << endl;
        cout << endl;
    }
    
    // Test Case 2
    {
        string s = "()[]{}";
        cout << "Test 2: s = \"" << s << "\"" << endl;
        cout << "Output: " << (solution.isValid(s) ? "true" : "false") << " (Expected: true)" << endl;
        cout << endl;
    }
    
    // Test Case 3
    {
        string s = "(]";
        cout << "Test 3: s = \"" << s << "\"" << endl;
        cout << "Output: " << (solution.isValid(s) ? "true" : "false") << " (Expected: false)" << endl;
        cout << endl;
    }
    
    // Test Case 4
    {
        string s = "([)]";
        cout << "Test 4: s = \"" << s << "\"" << endl;
        cout << "Output: " << (solution.isValid(s) ? "true" : "false") << " (Expected: false)" << endl;
        cout << endl;
    }
    
    // Test Case 5
    {
        string s = "{[]}";
        cout << "Test 5: s = \"" << s << "\"" << endl;
        cout << "Output: " << (solution.isValid(s) ? "true" : "false") << " (Expected: true)" << endl;
        cout << endl;
    }
    
    // Test Case 6 (Edge Case - Empty)
    {
        string s = "";
        cout << "Test 6: s = \"\" (empty)" << endl;
        cout << "Output: " << (solution.isValid(s) ? "true" : "false") << " (Expected: true)" << endl;
        cout << endl;
    }
    
    // Test Case 7 (Edge Case - Only Opening)
    {
        string s = "(((";
        cout << "Test 7: s = \"" << s << "\"" << endl;
        cout << "Output: " << (solution.isValid(s) ? "true" : "false") << " (Expected: false)" << endl;
        cout << endl;
    }
    
    return 0;
}

/*
 * Dry Run:
 * Input: s = "{[]}"
 * 
 * i=0, c='{': Opening → Push → Stack: ['{']
 * i=1, c='[': Opening → Push → Stack: ['{', '[']
 * i=2, c=']': Closing, top='[', match! → Pop → Stack: ['{']
 * i=3, c='}': Closing, top='{', match! → Pop → Stack: []
 * 
 * Stack empty → Return true ✓
 * 
 * -------------------------------------------------------------------
 * 
 * Input: s = "([)]"
 * 
 * i=0, c='(': Opening → Push → Stack: ['(']
 * i=1, c='[': Opening → Push → Stack: ['(', '[']
 * i=2, c=')': Closing, top='[', NOT match '(' → Return false ✗
 * 
 * -------------------------------------------------------------------
 * 
 * Key Points:
 * 
 * 1. Stack is LIFO (Last In First Out)
 *    - Perfect for matching nested brackets
 * 
 * 2. Three checks needed:
 *    - Stack empty before pop? (no opening bracket)
 *    - Brackets match? (correct type)
 *    - Stack empty at end? (all matched)
 * 
 * 3. Edge cases:
 *    - Empty string → true (valid)
 *    - Only opening → false (not closed)
 *    - Only closing → false (no opening)
 *    - Mismatch order → false
 */
