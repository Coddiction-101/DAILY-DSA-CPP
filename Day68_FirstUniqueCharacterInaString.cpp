#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
Problem: First Unique Character in a String

Goal:
Return the index of the first non-repeating character.
If none exists, return -1.

Approach:
1. Count frequency of each character using array (size 26 for a-z)
2. Traverse string again and find first character with freq == 1
*/

int firstUniqChar(string s) {
    // Step 1: Create frequency array for 26 lowercase letters
    vector<int> freq(26, 0);

    // Step 2: Count frequency of each character
    for(char ch : s) {
        freq[ch - 'a']++;   // map 'a'->0, 'b'->1 ... 'z'->25
    }

    // Step 3: Find first character with frequency 1
    for(int i = 0; i < s.length(); i++) {
        if(freq[s[i] - 'a'] == 1) {
            return i;  // return index of first unique character
        }
    }

    // Step 4: If no unique character found
    return -1;
}

int main() {
    string s;

    cout << "Enter string: ";
    cin >> s;

    int result = firstUniqChar(s);

    if(result != -1) {
        cout << "First unique character index: " << result << endl;
        cout << "Character: " << s[result] << endl;
    } else {
        cout << "No unique character found (-1)" << endl;
    }

    return 0;
}
