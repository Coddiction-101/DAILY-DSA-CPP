#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findNumbers(vector<int> &nums)
    {
        int count = 0;
        for (int num : nums)
        {
            int digitCount = 0;

            // Count digits by dividing by 10
            while (num != 0)
            {
                num /= 10;
                digitCount++;
            }

            // Check if number of digits is even
            if (digitCount % 2 == 0)
            {
                count++;
            }
        }
        return count;
    }
};

int main()
{
    Solution solution;

    // Test Case 1
    {
        vector<int> nums = {12, 345, 2, 6, 7896};
        cout << "Test 1: nums = [12, 345, 2, 6, 7896]" << endl;
        cout << "Output: " << solution.findNumbers(nums);
        cout << " (Expected: 2)" << endl;
        cout << "Explanation: 12 (2 digits), 7896 (4 digits)" << endl
             << endl;
    }

    // Test Case 2
    {
        vector<int> nums = {555, 901, 482, 1771};
        cout << "Test 2: nums = [555, 901, 482, 1771]" << endl;
        cout << "Output: " << solution.findNumbers(nums);
        cout << " (Expected: 1)" << endl;
        cout << "Explanation: Only 1771 has 4 digits" << endl
             << endl;
    }

    // Test Case 3
    {
        vector<int> nums = {1, 22, 333, 4444};
        cout << "Test 3: nums = [1, 22, 333, 4444]" << endl;
        cout << "Output: " << solution.findNumbers(nums);
        cout << " (Expected: 2)" << endl;
        cout << "Explanation: 22 (2 digits), 4444 (4 digits)" << endl
             << endl;
    }

    return 0;
}
