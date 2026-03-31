#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int freq[26] = {0};

        for (char c : magazine)
            freq[c - 'a']++;

        for (char c : ransomNote) {
            if (freq[c - 'a'] == 0)
                return false;
            freq[c - 'a']--;
        }

        return true;
    }
};

int main() {
    Solution obj;

    string ransomNote = "aa";
    string magazine = "aab";

    cout << (obj.canConstruct(ransomNote, magazine) ? "True" : "False");

    return 0;
}
