#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class code
{
public:
    vector<vector<int>> merge(vector<vector<int>> &gaps)
    {
        sort(gaps.begin(), gaps.end());

        vector<vector<int>> ans;
        int st = gaps[0][0];
        int ed = gaps[0][1];

        for (int i = 1; i < gaps.size(); ++i)
        {
            int s = gaps[i][0];
            int e = gaps[i][1];

            if (ed < s)
            {
                ans.push_back({st, ed});
                st = s;
                ed = e;
            }
            else
            {
                ed = max(ed, e);
            }
        }

        ans.push_back({st, ed});

        return ans;
    }
};

int main()
{
    code sol;

    vector<vector<int>> intervals1 = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    auto result1 = sol.merge(intervals1);
    cout << "Test 1: ";
    for (auto &interval : result1)
    {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;

    vector<vector<int>> intervals2 = {{1, 4}, {4, 5}};
    auto result2 = sol.merge(intervals2);
    cout << "Test 2: ";
    for (auto &interval : result2)
    {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}
