class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        int i = 0, n = s.size();

        while (i < n) {
            while (i < n && s[i] == ' ') i++;
            if (i >= n) break;

            int start = i;

            while (i < n && s[i] != ' ') i++;

            words.push_back(s.substr(start, i - start));
        }

        string result;

        for (int j = words.size() - 1; j >= 0; j--) {
            result += words[j];
            if (j != 0) result += " ";
        }

        return result;
    }
};
