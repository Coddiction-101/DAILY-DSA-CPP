// Missing Number (LeetCode 268)
// Given array nums containing n distinct numbers in range [0, n], find the missing one.

#include <iostream>  
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int expectedSum = n * (n + 1) / 2;  // sum of 0 to n
        int actualSum = 0;
        
        for (int num : nums) {
            actualSum += num;
        }
        
        return expectedSum - actualSum;  // the missing number
    }
};

int main() {
    Solution s;
    vector<int> n = {1, 2, 0, 4};  // missing 3
    int k = s.missingNumber(n);
    cout << k << endl;  // prints 3

    return 0;
}
