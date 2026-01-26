#include <iostream>
#include <vector>
using namespace std;

/*
    Problem: 704. Binary Search

    Given:
    - A sorted array of integers
    - A target value

    Task:
    - Return the index of the target if found
    - Otherwise, return -1

    Key Insight:
    - Since the array is sorted, Binary Search is the optimal approach

    Time Complexity: O(log n)
    Space Complexity: O(1)
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        // Binary Search Loop
        while (left <= right) {
            // Prevent potential overflow
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
                return mid;              // target found
            else if (nums[mid] < target)
                left = mid + 1;          // search right half
            else
                right = mid - 1;         // search left half
        }

        return -1; // target not found
    }
};

// -------- Local Testing --------
int main() {
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;

    Solution sol;
    int result = sol.search(nums, target);

    cout << "Index of target: " << result << endl;
    return 0;
}

