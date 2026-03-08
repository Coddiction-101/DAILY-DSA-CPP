/*
 * Problem: 541. Reverse String II (LeetCode)
 * Topics: String, Two Pointers
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1) - in-place modification
 *
 * -------------------------------------------------------------------
 * Problem Statement:
 * Given a string s and an integer k, reverse the first k characters 
 * for every 2k characters counting from the start of the string.
 * 
 * If there are fewer than k characters left, reverse all of them.
 * If there are less than 2k but >= k characters, reverse the first 
 * k characters and leave the rest as original.
 *
 * -------------------------------------------------------------------
 * Examples:
 *
 *   Input:  s = "abcdefg", k = 2
 *   Output: "bacdfeg"
 *   Explanation:
 *   First 2k (4) chars: "abcd" → reverse first 2 → "bacd"
 *   Next 2k (4) chars: "efg" → reverse first 2 → "feg"
 *   Result: "bacdfeg"
 *
 *   Input:  s = "abcd", k = 2
 *   Output: "bacd"
 *   Explanation: Reverse first 2, leave rest
 *
 * -------------------------------------------------------------------
 * Key Insight:
 * Two Pointer Reversal in Chunks:
 * - Process string in chunks of 2k
 * - For each chunk, reverse first k characters
 * - Use two pointers to swap characters
 * 
 * Pattern:
 * - i = 0, 2k, 4k, 6k... (start of each 2k chunk)
 * - Reverse from i to min(i+k-1, end)
 * - Skip next k characters
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    /*
     * Function: reverseStr
     * Purpose: Reverse first k chars of every 2k chars.
     *
     * Approach - Two Pointers in Chunks:
     * - Iterate through string in steps of 2k
     * - For each position i (0, 2k, 4k...):
     *   - Reverse from i to min(i+k-1, end)
     *   - Use two pointers: left and right
     *   - Swap and move inward
     * 
     * Steps:
     * 1. Loop: i from 0 to n, step by 2k
     * 2. Set left = i
     * 3. Set right = min(i+k-1, n-1)
     * 4. Swap characters at left and right
     * 5. Move left forward, right backward
     * 6. Continue until left >= right
     */
    string reverseStr(string s, int k) {
        // Process string in chunks of 2k
        for(int i = 0; i < s.length(); i += 2 * k) {
            
            // Starting position of reversal
            int left = i;
            
            // Ending position of reversal
            // Either i+k-1 or end of string (whichever is smaller)
            int right = min(i + k - 1, (int)s.length() - 1);
            
            // Reverse using two pointers
            // Swap characters and move inward
            while(left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
            
            // Example for s = "abcdefg", k = 2:
            // i=0: left=0, right=min(1,6)=1
            //      Swap s[0] and s[1]: "ab" → "ba"
            //      left++, right-- → left=1, right=0, loop ends
            //      Result: "bacdefg"
            // 
            // i=4: left=4, right=min(5,6)=5
            //      Swap s[4] and s[5]: "ef" → "fe"
            //      left++, right-- → left=5, right=4, loop ends
            //      Result: "bacdfeg"
        }
        
        return s;
    }
};

int main() {
    Solution solution;
    
    // Test Case 1
    {
        string s = "abcdefg";
        int k = 2;
        cout << "Test 1: s = \"" << s << "\", k = " << k << endl;
        cout << "Output: \"" << solution.reverseStr(s, k) << "\"";
        cout << " (Expected: \"bacdfeg\")" << endl;
        cout << "Explanation: Reverse 2, skip 2, reverse 2, skip 1" << endl;
        cout << endl;
    }
    
    // Test Case 2
    {
        string s = "abcd";
        int k = 2;
        cout << "Test 2: s = \"" << s << "\", k = " << k << endl;
        cout << "Output: \"" << solution.reverseStr(s, k) << "\"";
        cout << " (Expected: \"bacd\")" << endl;
        cout << "Explanation: Reverse first 2, leave rest" << endl;
        cout << endl;
    }
    
    // Test Case 3
    {
        string s = "abcdefg";
        int k = 8;
        cout << "Test 3: s = \"" << s << "\", k = " << k << endl;
        cout << "Output: \"" << solution.reverseStr(s, k) << "\"";
        cout << " (Expected: \"gfedcba\")" << endl;
        cout << "Explanation: k > length, reverse entire string" << endl;
        cout << endl;
    }
    
    // Test Case 4
    {
        string s = "abcd";
        int k = 3;
        cout << "Test 4: s = \"" << s << "\", k = " << k << endl;
        cout << "Output: \"" << solution.reverseStr(s, k) << "\"";
        cout << " (Expected: \"cbad\")" << endl;
        cout << "Explanation: Reverse first 3" << endl;
        cout << endl;
    }
    
    return 0;
}

/*
 * Dry Run:
 * Input: s = "abcdefg", k = 2
 * 
 * Iteration 1: i = 0 (first 2k chunk)
 * left = 0
 * right = min(0+2-1, 6) = min(1, 6) = 1
 * 
 * Swap loop:
 * left=0, right=1: swap s[0] and s[1]
 *   "abcdefg" → "bacdefg"
 * left=1, right=0: left >= right, stop
 * 
 * Iteration 2: i = 4 (second 2k chunk)
 * left = 4
 * right = min(4+2-1, 6) = min(5, 6) = 5
 * 
 * Swap loop:
 * left=4, right=5: swap s[4] and s[5]
 *   "bacdefg" → "bacdfeg"
 * left=5, right=4: left >= right, stop
 * 
 * Iteration 3: i = 8
 * i >= 7 (length), loop ends
 * 
 * Return: "bacdfeg" ✓
 * 
 * -------------------------------------------------------------------
 * 
 * Key Points:
 * 
 * 1. Why i += 2*k?
 *    - Process in chunks of 2k
 *    - Reverse first k, skip next k
 *    - Move to next 2k chunk
 * 
 * 2. Why min(i+k-1, length-1)?
 *    - Handle edge case: less than k chars remaining
 *    - Reverse whatever is available
 *    - Don't go out of bounds
 * 
 * 3. Two pointer swap:
 *    - Standard technique for reversal
 *    - Start from ends, swap, move inward
 *    - Continue while left < right
 * 
 * 4. Edge cases:
 *    - k > length: Reverse entire string
 *    - k == length: Reverse entire string
 *    - Remaining < k: Reverse all remaining
 * 
 * 5. In-place modification:
 *    - Modifies original string
 *    - No extra space for new string
 *    - O(1) space complexity
 */
