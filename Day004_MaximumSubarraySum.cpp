#include <iostream>
#include <vector>
using namespace std;

/*
    Problem: Maximum Subarray (LeetCode 53)

    Approach:
    - Kadane’s Algorithm
    - At each index, decide whether to:
        1) Start a new subarray
        2) Extend the previous subarray

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

int maxSubArraySum(vector<int> &nums)
{
    // Initialize current and maximum sum with first element
    int currentSum = nums[0];
    int maxSum = nums[0];

    // Traverse the array from second element
    for (int i = 1; i < nums.size(); i++)
    {
        // Either start fresh from nums[i] or extend previous subarray
        currentSum = max(nums[i], currentSum + nums[i]);

        // Update the maximum subarray sum found so far
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}

int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << "Max Subarray Sum: " << maxSubArraySum(nums);
    return 0;
}
