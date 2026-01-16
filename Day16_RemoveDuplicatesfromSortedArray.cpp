#include <iostream>
#include <vector>
using namespace std;

/*
 * Problem: Remove Duplicates from Sorted Array (LeetCode 26)
 *
 * Given a sorted array nums in non-decreasing order,
 * remove the duplicates in-place such that each unique element appears only once.
 *
 * Return k = number of unique elements.
 * The first k elements of nums should contain the unique elements in original order.
 *
 * Example:
 *   Input:  nums = [1,1,2]
 *   Output: 2, nums = [1,2,_]
 *
 *   Input:  nums = [0,0,1,1,1,2,2,3,3,4]
 *   Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
 *
 * Constraints:
 * - Must be done in-place (no extra array).
 * - Relative order must be preserved.
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Edge case: empty array
        if (nums.empty()) {
            return 0;
        }

        // Two-pointer approach:
        // k = write pointer (next position for a unique element)
        // i = read pointer (traverse the array)
        int k = 1;  // first element is always unique

        // Traverse from index 1 to end
        for (int i = 1; i < nums.size(); i++) {
            // If current element is different from the last unique element
            if (nums[i] != nums[k-1]) {
                // Place this unique element at position k
                nums[k] = nums[i];
                k++;  // move write pointer forward
            }
            // If nums[i] == nums[k-1], it's a duplicate → skip it
        }

        // k is the number of unique elements
        return k;
    }
};

// Driver code to test the solution
int main() {
    Solution sol;

    // Test case 1: [1,1,2]
    vector<int> nums1 = {1, 1, 2};
    int k1 = sol.removeDuplicates(nums1);
    cout << "Test 1: k = " << k1 << ", nums = [";
    for (int i = 0; i < k1; i++) {
        cout << nums1[i];
        if (i < k1 - 1) cout << ",";
    }
    cout << "]" << endl;

    // Test case 2: [0,0,1,1,1,2,2,3,3,4]
    vector<int> nums2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int k2 = sol.removeDuplicates(nums2);
    cout << "Test 2: k = " << k2 << ", nums = [";
    for (int i = 0; i < k2; i++) {
        cout << nums2[i];
        if (i < k2 - 1) cout << ",";
    }
    cout << "]" << endl;

    // Test case 3: all duplicates [1,1,1]
    vector<int> nums3 = {1, 1, 1};
    int k3 = sol.removeDuplicates(nums3);
    cout << "Test 3: k = " << k3 << ", nums = [";
    for (int i = 0; i < k3; i++) {
        cout << nums3[i];
        if (i < k3 - 1) cout << ",";
    }
    cout << "]" << endl;

    return 0;
}
