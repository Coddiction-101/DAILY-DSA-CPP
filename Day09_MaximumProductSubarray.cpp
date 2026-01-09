#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class code
{
public:
    int maxProductSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int MaxEndingHere = nums[0];
        int MinEndingHere = nums[0];
        int GlobalMax = nums[0];

        for (int i = 1; i < n; i++)
        {
            int prevMax = MaxEndingHere;
            int prevMin = MinEndingHere;

            MaxEndingHere = max({nums[i], prevMax * nums[i], prevMin * nums[i]});
            MinEndingHere = min({nums[i], prevMax * nums[i], prevMin * nums[i]});

            GlobalMax = max(GlobalMax, MaxEndingHere);
        }
        return GlobalMax;
    }
};

int main()
{
    code cc;
    vector<int> nums1 = {2, 3, -2, 4};
    cout << "Max Product Subarray Is: " << cc.maxProductSubarray(nums1) << endl;
    return 0;
}
