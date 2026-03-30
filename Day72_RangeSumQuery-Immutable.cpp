#include <iostream>
#include <vector>
using namespace std;

class NumArray
{
private:
    vector<int> prefix;

public:
    NumArray(vector<int> &nums)
    {

        prefix.resize(nums.size());

        prefix[0] = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            prefix[i] = prefix[i - 1] + nums[i];
        }
    }

    int sumRange(int left, int right)
    {
        if (left == 0)
        {
            return prefix[right];
        }

        return prefix[right] - prefix[left - 1];
    }
};

int main()
{

    vector<int> nums = {-2, 0, 3, -5, 2, -1};

    NumArray obj(nums);

    cout << "Sum (0,2): " << obj.sumRange(0, 2) << endl; // Expected: 1
    cout << "Sum (2,5): " << obj.sumRange(2, 5) << endl; // Expected: -1
    cout << "Sum (0,5): " << obj.sumRange(0, 5) << endl; // Expected: -3

    return 0;
}
