#include <bits/stdc++.h>
using namespace std;

class Code {
public:
    string mergeStringAlternately(string word1, string word2) {
        string result = "";
        size_t i = 0, j = 0;

        // Loop continues as long as ANY string has characters left
        while (i < word1.length() || j < word2.length()) {

            // Pick from word1 if it still has characters
            if (i < word1.length()) {
                result.push_back(word1[i]);
                i++;
            }

            // Pick from word2 if it still has characters
            if (j < word2.length()) {
                result.push_back(word2[j]);
                j++;
            }
        }
        return result;
    }
};

int main() {
    Code cc;

    string word1, word2;
    cin >> word1;
    cin >> word2;

    string merged = cc.mergeStringAlternately(word1, word2);
    cout << "Merged string: " << merged << endl;

    return 0;
}

