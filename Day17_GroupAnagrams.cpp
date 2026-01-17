#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
 * Problem: Group Anagrams (LeetCode 49)
 *
 * Given an array of strings strs, group all anagrams together.
 * Return a list of lists, where each inner list contains strings that are anagrams of each other.
 *
 * Example:
 *   Input:  strs = ["eat","tea","tan","ate","nat","bat"]
 *   Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
 *
 * Constraints:
 * - Only lowercase English letters.
 * - Order of groups and strings within groups doesn't matter.
 */

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        // Map to group strings by their sorted version
        // Key: sorted string (e.g., "eat" -> "aet")
        // Value: list of original strings that are anagrams
        unordered_map<string, vector<string>> groups;

        // Step 1: For each string, sort it to get the key
        for (const string &s : strs)
        {
            string key = s;
            sort(key.begin(), key.end()); // sorted version is the anagram key

            // Add the original string to the group with this key
            groups[key].push_back(s);
        }

        // Step 2: Extract all groups into the result
        vector<vector<string>> result;
        for (const auto &pair : groups)
        {
            result.push_back(pair.second);
        }

        return result;
    }
};

// Driver code to test the solution
int main()
{
    Solution sol;

    // Test case 1
    vector<string> strs1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result1 = sol.groupAnagrams(strs1);

    cout << "Test 1:" << endl;
    for (const auto &group : result1)
    {
        cout << "[";
        for (size_t i = 0; i < group.size(); i++)
        {
            cout << "\"" << group[i] << "\"";
            if (i < group.size() - 1)
                cout << ",";
        }
        cout << "]" << endl;
    }

    // Test case 2: all anagrams
    vector<string> strs2 = {"abc", "bca", "cab"};
    vector<vector<string>> result2 = sol.groupAnagrams(strs2);

    cout << "\nTest 2:" << endl;
    for (const auto &group : result2)
    {
        cout << "[";
        for (size_t i = 0; i < group.size(); i++)
        {
            cout << "\"" << group[i] << "\"";
            if (i < group.size() - 1)
                cout << ",";
        }
        cout << "]" << endl;
    }

    // Test case 3: no anagrams
    vector<string> strs3 = {"abc", "def", "xyz"};
    vector<vector<string>> result3 = sol.groupAnagrams(strs3);

    cout << "\nTest 3:" << endl;
    for (const auto &group : result3)
    {
        cout << "[";
        for (size_t i = 0; i < group.size(); i++)
        {
            cout << "\"" << group[i] << "\"";
            if (i < group.size() - 1)
                cout << ",";
        }
        cout << "]" << endl;
    }

    return 0;
}
