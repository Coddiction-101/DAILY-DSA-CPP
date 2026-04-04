#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int assignCookies(vector<int> &g, vector<int> &s)
{
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int i = 0;
    int j = 0;

    while (i < g.size() && j < s.size())
    {
        if (s[j] >= g[i])
        {
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }
    return i;
}

int main()
{
    vector<int> g = {1, 2, 3};
    vector<int> s = {1, 1};

    int result = assignCookies(g, s);

    cout << "Maximum satisfied children: " << result << endl;
    return 0;
}
