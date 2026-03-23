#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int appendCharacters(string s, string t)
    {
        int i = 0, j = 0;

        while (i < s.size() && j < t.size())
        {
            if (s[i] == t[j])
            {
                j++;
            }
            i++;
        }

        return t.size() - j;
    }
};

int main()
{
    Solution obj;

    cout << obj.appendCharacters("coaching", "coding") << endl;
    cout << obj.appendCharacters("abcde", "a") << endl;
    cout << obj.appendCharacters("z", "abcde") << endl;
    return 0;
}
