#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        int i = 0;
        int n = nums.size();

        // 🔁 Cyclic Sort: place each number at correct index (value - 1)
        while (i < n)
        {
            int correctIndex = nums[i] - 1;

            if (nums[i] != nums[correctIndex])
            {
                swap(nums[i], nums[correctIndex]);
            }
            else
            {
                i++;
            }
        }

        // 📌 Collect missing numbers
        vector<int> result;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != i + 1)
            {
                result.push_back(i + 1);
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};

    vector<int> result = sol.findDisappearedNumbers(nums);

    cout << "Missing numbers: ";
    for (int num : result)
    {
        cout << num << " ";
    }

    return 0;
}
