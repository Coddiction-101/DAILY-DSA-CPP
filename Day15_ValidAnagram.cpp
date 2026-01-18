#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
 * Problem: Valid Anagram (LeetCode 242)
 *
 * Given two strings s and t, return true if t is an anagram of s, and false otherwise.
 *
 * An anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
 * using all the original letters exactly once.
 *
 * Example:
 *   Input:  s = "anagram", t = "nagaram"
 *   Output: true
 *
 *   Input:  s = "rat", t = "car"
 *   Output: false
 *
 * Constraints:
 * - 1 <= s.length, t.length <= 5 * 10^4
 * - s and t consist of lowercase English letters.
 */

class Solution {
public:
    bool isAnagram(string s, string t) {
        // Step 1: If lengths are different, they can't be anagrams
        if (s.length() != t.length()) {
            return false;
        }

        // Step 2: Frequency array for 26 lowercase letters
        // We use a vector of size 26, initialized to 0
        vector<int> count(26, 0);

        // Step 3: Traverse both strings together
        // For each character in s, increment its count
        // For each character in t, decrement its count
        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++;  // 'a' -> 0, 'b' -> 1, ..., 'z' -> 25
            count[t[i] - 'a']--;
        }

        // Step 4: Check if all counts are zero
        // If any count is non-zero, the strings are not anagrams
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) {
                return false;
            }
        }

        // Step 5: All counts are zero → s and t are anagrams
        return true;
    }
};

// Driver code to test the solution
int main() {
    Solution sol;

    // Test case 1: valid anagram
    string s1 = "anagram";
    string t1 = "nagaram";
    cout << "Test 1: " << sol.isAnagram(s1, t1) << " (Expected: 1)" << endl;

    // Test case 2: not an anagram
    string s2 = "rat";
    string t2 = "car";
    cout << "Test 2: " << sol.isAnagram(s2, t2) << " (Expected: 0)" << endl;

    // Test case 3: same string
    string s3 = "listen";
    string t3 = "silent";
    cout << "Test 3: " << sol.isAnagram(s3, t3) << " (Expected: 1)" << endl;

    // Test case 4: different lengths
    string s4 = "hello";
    string t4 = "helloo";
    cout << "Test 4: " << sol.isAnagram(s4, t4) << " (Expected: 0)" << endl;

    return 0;
}
