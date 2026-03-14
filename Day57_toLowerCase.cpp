#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string toLowerCase(string s) {
        for(char &c : s) {
            // Checked if uppercase letter (A-Z)
            if(c >= 'A' && c <= 'Z') {
                c = c + 32;
            }
        }
        return s;
    }
};

int main() {
    cout << "=== Day 56 Problem 1: To Lower Case ===" << endl;
    Solution solution;
    
     {
        string s = "Hello";
        cout << "Test 1: s = \"" << s << "\"" << endl;
        cout << "Output: \"" << solution.toLowerCase(s) << "\"";
     }
    
     {
        string s = "LOVELY";
        cout << "Test 2: s = \"" << s << "\"" << endl;
        cout << "Output: \"" << solution.toLowerCase(s) << "\"";
     }
    
    // Test Case 3
    {
        string s = "here";
        cout << "Test 3: s = \"" << s << "\"" << endl;
        cout << "Output: \"" << solution.toLowerCase(s) << "\"";
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
