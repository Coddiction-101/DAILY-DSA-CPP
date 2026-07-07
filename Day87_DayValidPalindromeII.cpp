class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            if (s[left] != s[right]) {

                int i = left + 1;
                int j = right;

                while (i < j && s[i] == s[j]) {
                    i++;
                    j--;
                }

                if (i >= j) {
                    return true;
                }

                i = left;
                j = right - 1;

                while (i < j && s[i] == s[j]) {
                    i++;
                    j--;
                }

                return i >= j;
            }

            left++;
            right--;
        }

        return true;
    }
};
