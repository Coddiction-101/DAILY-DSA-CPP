#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list is not needed here

class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if (s1.size() > s2.size()) return false;

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        // Build frequency for s1
        for (char c : s1) {
            freq1[c - 'a']++;
        }

        // First window
        for (int i = 0; i < s1.size(); i++) {
            freq2[s2[i] - 'a']++;
        }

        // Check first window
        if (freq1 == freq2) return true;

        // Sliding window
        for (int i = s1.size(); i < s2.size(); i++) {
            freq2[s2[i] - 'a']++;                     // add new char
            freq2[s2[i - s1.size()] - 'a']--;         // remove old char

            if (freq1 == freq2) return true;
        }

        return false;
    }
};

int main() {
    Solution obj;

    string s1 = "ab";
    string s2 = "eidbaooo";

    if (obj.checkInclusion(s1, s2)) {
        cout << "True (Permutation exists)" << endl;
    } else {
        cout << "False (No permutation found)" << endl;
    }

    return 0;
}
