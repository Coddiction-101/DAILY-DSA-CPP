/**
 * Day 28: LeetCode 3 - Longest Substring Without Repeating Characters
 * Pattern: Sliding Window
 * Time Complexity: O(n)
 * Space Complexity: O(min(n, charset))
 *
 * Idea:
 * - Use a sliding window [left, right]
 * - Maintain a set to track unique characters in the window
 * - If a duplicate is found, shrink the window from the left
 * - Keep updating the maximum window size
 *
 * Repo Path:
 * DAILY-DSA-CPP/Day_28/longest_substring_no_repeat.cpp
 */

#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        // Set to store unique characters in the current window
        unordered_set<char> window;

        int left = 0;      // Left pointer of the sliding window
        int maxLen = 0;    // Stores the maximum length found

        // Expand the window using right pointer
        for (int right = 0; right < s.length(); right++) {

            // If duplicate character found,
            // shrink the window until it's removed
            while (window.count(s[right])) {
                window.erase(s[left]);
                left++;
            }

            // Add current character to the window
            window.insert(s[right]);

            // Update maximum window size
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

int main() {
    Solution sol;

    // Test cases: {input_string, expected_output}
    vector<pair<string, int>> tests = {
        {"abcabcbb", 3},   // "abc"
        {"bbbbb", 1},      // "b"
        {"pwwkew", 3},     // "wke"
        {"", 0},           // empty string
        {"a", 1},          // single character
        {"dvdf", 3}        // "vdf"
    };

    for (auto& test : tests) {
        int result = sol.lengthOfLongestSubstring(test.first);
        cout << "Input: \"" << test.first << "\"\n";
        cout << "Output: " << result;
        cout << (result == test.second ? " => PASS" : " => FAIL") << "\n\n";
    }

    cout << "All tests passed. Sliding Window pattern reinforced.\n";
    return 0;
}
