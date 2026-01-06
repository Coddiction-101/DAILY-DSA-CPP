#include <iostream>
#include <vector>
using namespace std;

vector<int> moveZeros(vector<int> &nums)
{
    int position = 0;    
    for (int i = 0; i < nums.size(); i++)
    {

        if (nums[i] != 0) {
            swap(nums[i], nums[position]);
            position++;
        }
    }
    return nums;
}

int main()
{
    vector<int> arr = {1, 0, 1, 3, 1, 2, 4, 0};
    vector<int> res = moveZeros(arr);

    for (int x : res) cout << x << " ";
    return 0;
}
