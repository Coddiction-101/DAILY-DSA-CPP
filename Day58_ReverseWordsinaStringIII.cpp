#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int i = 0;
        
        while (i < n) {
            int start = i;  
            
            while (i < n && s[i] != ' ') {
                i++;
            }
            
            int end = i - 1; 
            
            int left = start, right = end;
            while (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
            
            i++;  
        }
        return s;
    }
};

int main() {
     Solution solution;
    
    // Test case 1
    {
        string s = "Let's Code";
        cout << "Test 1: s = \"" << s << "\"\n";
        cout << "Output: \"" << solution.reverseWords(s) << "\"\n";
        cout << "Expected: \"s'teL ekat edoCteeL tsetnoc\"\n\n";
    }

    // Test case 2
    {
        string s = "God Ding";
        cout << "Test 2: s = \"" << s << "\"\n";
        cout << "Output: \"" << solution.reverseWords(s) << "\"\n";
        cout << "Expected: \"doG gniD\"\n\n";
    }

    // Test case 3
    {
        string s = "a";
        cout << "Test 3: s = \"" << s << "\"\n";
        cout << "Output: \"" << solution.reverseWords(s) << "\"\n";
        cout << "Expected: \"a\"\n\n";
    }

    return 0;
}
