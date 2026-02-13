/*
 * Problem: 151. Reverse Words in a String
 * Day: 35
 * Difficulty: Medium
 * Topics: String, Two Pointers
 *
 * -------------------------------------------------------
 * Problem Statement:
 * Given a string s, reverse the order of the words.
 *
 * Rules:
 * - Remove leading and trailing spaces.
 * - Reduce multiple spaces between words to a single space.
 * - Words are separated by spaces.
 *
 * Example:
 * Input:  "  the sky   is blue  "
 * Output: "blue is sky the"
 *
 * -------------------------------------------------------
 * Approach:
 * 1. Traverse the string and extract individual words.
 * 2. Skip extra spaces.
 * 3. Store words in a vector.
 * 4. Rebuild the string in reverse order.
 *
 * -------------------------------------------------------
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

class Solution {
public:
    string reverseWords(string s) {

        vector<string> words;
        int n = s.length();
        int i = 0;

        // Step 1: Extract words
        while (i < n) {

            // Skip spaces
            while (i < n && s[i] == ' ') {
                i++;
            }

            if (i >= n) break;

            int start = i;

            // Collect characters until next space
            while (i < n && s[i] != ' ') {
                i++;
            }

            words.push_back(s.substr(start, i - start));
        }

        // Step 2: Build result in reverse order
        string result;

        for (int j = words.size() - 1; j >= 0; j--) {
            result += words[j];

            // Add space between words (not after last word)
            if (j != 0) {
                result += " ";
            }
        }

        return result;
    }
};

