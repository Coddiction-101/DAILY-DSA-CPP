class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";

        unordered_map<char, int> need;
        for (char c : t) need[c]++;

        int required = need.size();
        int formed = 0;

        unordered_map<char, int> window;

        int left = 0;
        int minLen = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            window[c]++;

            if (need.count(c) && window[c] == need[c]) {
                formed++;
            }

            while (left <= right && formed == required) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                char leftChar = s[left];
                window[leftChar]--;

                if (need.count(leftChar) && window[leftChar] < need[leftChar]) {
                    formed--;
                }

                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
