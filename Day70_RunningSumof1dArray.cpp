#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        int sum = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            nums[i] = sum;
        }

        return nums;
    }
};

int main()
{
    Solution solution;

    // Test Case 1
    {
        vector<int> nums = {1, 2, 3, 4};
        cout << "Test 1: nums = [1,2,3,4]" << endl;
        vector<int> result = solution.runningSum(nums);
        cout << "Output: [";
        for (int i = 0; i < result.size(); i++)
        {
            cout << result[i];
            if (i < result.size() - 1)
                cout << ",";
        }
        cout << "]" << endl;
        cout << "Expected: [1,3,6,10]" << endl
             << endl;
    }

    // Test Case 2
    {
        vector<int> nums = {1, 1, 1, 1, 1};
        cout << "Test 2: nums = [1,1,1,1,1]" << endl;
        vector<int> result = solution.runningSum(nums);
        cout << "Output: [";
        for (int i = 0; i < result.size(); i++)
        {
            cout << result[i];
            if (i < result.size() - 1)
                cout << ",";
        }
        cout << "]" << endl;
        cout << "Expected: [1,2,3,4,5]" << endl
             << endl;
    }

    // Test Case 3
    {
        vector<int> nums = {3, 1, 2, 10, 1};
        cout << "Test 3: nums = [3,1,2,10,1]" << endl;
        vector<int> result = solution.runningSum(nums);
        cout << "Output: [";
        for (int i = 0; i < result.size(); i++)
        {
            cout << result[i];
            if (i < result.size() - 1)
                cout << ",";
        }
        cout << "]" << endl;
        cout << "Expected: [3,4,6,16,17]" << endl
             << endl;
    }

    return 0;
}
