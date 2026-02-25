/*
 * Day 37 - Daily DSA in C++
 * Problem: 647. Palindromic Substrings (LeetCode)
 * Date: February 06, 2026
 * Difficulty: Medium
 * Topics: String, Dynamic Programming
 *
 * Time Complexity: O(n²)
 * Space Complexity: O(n²)
 *
 * Problem Link:
 * https://leetcode.com/problems/palindromic-substrings/
 *
 * -------------------------------------------------------------------
 * Problem Statement:
 * Given a string s, return the number of palindromic substrings in it.
 * A string is a palindrome when it reads the same backward as forward.
 * A substring is a contiguous sequence of characters within the string.
 *
 * -------------------------------------------------------------------
 * Examples:
 *
 *   Input:  s = "abc"
 *   Output: 3
 *   Explanation: Three palindromic strings: "a", "b", "c"
 *
 *   Input:  s = "aaa"
 *   Output: 6
 *   Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa"
 *
 * -------------------------------------------------------------------
 * Key Insight:
 * Dynamic Programming Approach:
 * - Create 2D DP table where dp[i][j] = true if s[i...j] is palindrome
 * - Build from smaller substrings to larger ones
 * - Process by length to ensure dependencies are already computed
 * 
 * Recurrence Relation:
 * dp[i][j] = (s[i] == s[j]) && dp[i+1][j-1]
 * 
 * Build Order:
 * 1. Length 1: All single characters are palindromes (base case)
 * 2. Length 2: Check if adjacent characters match
 * 3. Length 3+: Use recurrence relation with previously computed values
 */
#include <bits/stdc++.h>
using namespace std;
class code {
public:
    /*
     * Function: countSubstrings
     * Purpose: Count the total number of palindromic substrings.
     *
     * Approach:
     * - Use 2D DP table to store palindrome information
     * - dp[i][j] = true if substring from index i to j is palindrome
     * - Build table systematically by substring length
     * 
     * Steps:
     * 1. Initialize: Mark all single characters as palindromes
     * 2. Check pairs: Mark adjacent matching characters as palindromes
     * 3. Build larger: For length 3+, check if outer chars match AND inner is palindrome
     * 4. Count: Increment count for each palindrome found
     */
    int countSubstrings(string s) {
        int n = s.length();
        
        // Create DP table - dp[i][j] = true if s[i...j] is palindrome
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int count = 0;
        
        // Step 1: Handle single characters (length = 1)
        // Every single character is a palindrome
        for(int i = 0; i < n; i++) {
            dp[i][i] = true;  // s[i] by itself is always palindrome
            count++;          // Count each single character
        }
        
        // Step 2: Handle pairs (length = 2)
        // Two characters form palindrome if they're same
        for(int i = 0; i < n - 1; i++) {
            if(s[i] == s[i + 1]) {      // Adjacent characters match
                dp[i][i + 1] = true;     // Mark as palindrome
                count++;                  // Increment count
            }
        }
        
        // Step 3: Handle length 3 to n
        // Build from smaller to larger substrings
        for(int len = 3; len <= n; len++) {
            for(int i = 0; i <= n - len; i++) {
                int j = i + len - 1;  // Calculate ending index
                
                // s[i...j] is palindrome if:
                // 1. Outer characters match: s[i] == s[j]
                // 2. Inner substring is palindrome: dp[i+1][j-1]
                if(s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    count++;
                }
            }
        }
        
        return count;
    }
};
// Main function for local testing
int main() {
    cout << "=== Day 37: Palindromic Substrings ===" << endl;
    code cc;
    
    // Test Case 1
    {
        string s = "abc";
        cout << "Test 1: s = \"" << s << "\"" << endl;
        cout << "Output: " << cc.countSubstrings(s) << " (Expected: 3)" << endl;
        cout << "Palindromes: \"a\", \"b\", \"c\"" << endl;
        cout << endl;
    }
    
    // Test Case 2
    {
        string s = "aaa";
        cout << "Test 2: s = \"" << s << "\"" << endl;
        cout << "Output: " << cc.countSubstrings(s) << " (Expected: 6)" << endl;
        cout << "Palindromes: \"a\", \"a\", \"a\", \"aa\", \"aa\", \"aaa\"" << endl;
        cout << endl;
    }
    
    // Test Case 3
    {
        string s = "aba";
        cout << "Test 3: s = \"" << s << "\"" << endl;
        cout << "Output: " << cc.countSubstrings(s) << " (Expected: 4)" << endl;
        cout << "Palindromes: \"a\", \"b\", \"a\", \"aba\"" << endl;
        cout << endl;
    }
    
    // Test Case 4
    {
        string s = "abba";
        cout << "Test 4: s = \"" << s << "\"" << endl;
        cout << "Output: " << cc.countSubstrings(s) << " (Expected: 6)" << endl;
        cout << "Palindromes: \"a\", \"b\", \"b\", \"a\", \"bb\", \"abba\"" << endl;
        cout << endl;
    }
    
    // Test Case 5 (Edge Case)
    {
        string s = "a";
        cout << "Test 5: s = \"" << s << "\"" << endl;
        cout << "Output: " << cc.countSubstrings(s) << " (Expected: 1)" << endl;
        cout << "Palindromes: \"a\"" << endl;
        cout << endl;
    }
    
    return 0;
}

/*
 * Dry Run:
 * Input: s = "aba"
 * 
 * n = 3
 * dp = [[false, false, false],
 *       [false, false, false],
 *       [false, false, false]]
 * count = 0
 * 
 * Step 1: Length 1
 * i=0: dp[0][0] = true, count = 1  → "a"
 * i=1: dp[1][1] = true, count = 2  → "b"
 * i=2: dp[2][2] = true, count = 3  → "a"
 * 
 * Step 2: Length 2
 * i=0: s[0]='a', s[1]='b' → not equal, skip
 * i=1: s[1]='b', s[2]='a' → not equal, skip
 * count still = 3
 * 
 * Step 3: Length 3
 * len=3, i=0, j=2:
 * s[0]='a', s[2]='a' → match ✓
 * dp[1][1]=true → inner palindrome ✓
 * dp[0][2] = true, count = 4  → "aba"
 * 
 * Final count = 4 ✓
 * 
 * -------------------------------------------------------------------
 * 
 * Dry Run:
 * Input: s = "aaa"
 * 
 * Step 1: Length 1
 * count = 3 → "a", "a", "a"
 * 
 * Step 2: Length 2
 * i=0: s[0]='a', s[1]='a' → match, count = 4 → "aa"
 * i=1: s[1]='a', s[2]='a' → match, count = 5 → "aa"
 * 
 * Step 3: Length 3
 * len=3, i=0, j=2:
 * s[0]='a', s[2]='a' → match
 * dp[1][1]=true → inner palindrome
 * count = 6 → "aaa"
 * 
 * Final count = 6 ✓
 * 
 * -------------------------------------------------------------------
 * 
 * Key Points:
 * 
 * 1. Why process by length?
 *    - Ensures dp[i+1][j-1] is computed before dp[i][j]
 *    - Bottom-up approach: small substrings → large substrings
 * 
 * 2. Calculating j:
 *    - j = i + len - 1
 *    - For substring of length 'len' starting at 'i'
 *    - Example: i=0, len=3 → j=2 (covers indices 0,1,2)
 * 
 * 3. Base cases:
 *    - Length 1: Always palindrome (single character)
 *    - Length 2: Palindrome only if characters match
 * 
 * 4. Recurrence:
 *    - dp[i][j] depends on dp[i+1][j-1]
 *    - Outer match + inner palindrome = full palindrome
 * 
 * 5. Complexity:
 *    - Time: O(n²) - filling n×n table
 *    - Space: O(n²) - storing DP table
 * 
 * 6. Alternative approach:
 *    - Expand Around Center: O(n²) time, O(1) space
 *    - Trade-off: DP is more intuitive, Expand is space-efficient
 */
