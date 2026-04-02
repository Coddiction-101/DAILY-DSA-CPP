#include <iostream>
#include <vector>
using namespace std;

/*
    Iteration:
    i = 0 → result[0] = nums[0] = 2
            result[1] = nums[3] = 3

    i = 1 → result[2] = nums[1] = 5
            result[3] = nums[4] = 4

    i = 2 → result[4] = nums[2] = 1
            result[5] = nums[5] = 7
*/

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> result(2 * n);

        for(int i = 0; i < n; i++) {
            result[2 * i] = nums[i];
            result[2 * i + 1] = nums[i + n];
        }

        return result;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {2, 5, 1, 3, 4, 7};
    int n = 3;

    vector<int> result = obj.shuffle(nums, n);

    cout << "Shuffled Array: ";
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
