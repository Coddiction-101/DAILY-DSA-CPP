#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string toLowerCase(string s)
    {
        for (char &c : s)
        {
            // Check if character is uppercase (A-Z)
            if (c >= 'A' && c <= 'Z')
            {
                c = c + 32; // Convert to lowercase by adding 32
            }
        }
        return s;
    }
};

int main()
{
    Solution solution;

    // Test Case 1
    {
        string s = "Hello";
        cout << "Test 1: s = \"" << s << "\"" << endl;
        cout << "Output: \"" << solution.toLowerCase(s) << "\"" << endl;
    }

    // Test Case 2
    {
        string s = "LOVELY";
        cout << "Test 2: s = \"" << s << "\"" << endl;
        cout << "Output: \"" << solution.toLowerCase(s) << "\"" << endl;
    }

    // Test Case 3
    {
        string s = "here";
        cout << "Test 3: s = \"" << s << "\"" << endl;
        cout << "Output: \"" << solution.toLowerCase(s) << "\"" << endl;
    }

    return 0;
}

/*
 * ASCII Values:
 * 'A' = 65, 'a' = 97, difference = 32
 * 'Z' = 90, 'z' = 122, difference = 32
 *
 * Simply add 32 to convert uppercase to lowercase!
 */
