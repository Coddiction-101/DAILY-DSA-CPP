#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int MOD = 1e9 + 7;

        sort(nums.begin(), nums.end());

        int n = nums.size();
        int left = 0, right = n - 1;

        // powers of 2
        vector<int> power(n);
        power[0] = 1;
        for (int i = 1; i < n; i++) {
            power[i] = (power[i - 1] * 2) % MOD;
        }

        int count = 0;

        while (left <= right) {

            if (nums[left] + nums[right] <= target) {
                count = (count + power[right - left]) % MOD;
                left++;
            }
            else {
                right--;
            }
        }

        return count;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {3, 5, 6, 7};
    int target = 9;

    cout << obj.numSubseq(nums, target) << endl;

    return 0;
}
