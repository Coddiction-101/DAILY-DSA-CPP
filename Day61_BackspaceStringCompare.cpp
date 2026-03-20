class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1, j = t.size() - 1;

        while (i >= 0 || j >= 0) {
            int skipS = 0, skipT = 0;

            // find next valid char in s
            while (i >= 0 && (s[i] == '#' || skipS > 0)) {
                if (s[i] == '#') skipS++;
                else skipS--;
                i--;
            }

            // find next valid char in t
            while (j >= 0 && (t[j] == '#' || skipT > 0)) {
                if (t[j] == '#') skipT++;
                else skipT--;
                j--;
            }

            // compare characters
            if (i >= 0 && j >= 0 && s[i] != t[j]) return false;

            // check mismatch in length
            if ((i >= 0) != (j >= 0)) return false;

            i--; 
            j--;
        }

        return true;
    }
};
