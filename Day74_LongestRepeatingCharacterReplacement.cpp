#include <iostream>
#include <string>
using namespace std;

int characterReplacement(string s, int k)
{
    int freq[26] = {0};
    int left = 0, maxFreq = 0, maxLen = 0;

    for (int right = 0; right < s.size(); right++)
    {
        maxFreq = max(maxFreq, ++freq[s[right] - 'A']);

        while ((right - left + 1) - maxFreq > k)
            freq[s[left++] - 'A']--;

        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

int main()
{
    cout << characterReplacement("AABABBA", 1);
    return 0;
}
