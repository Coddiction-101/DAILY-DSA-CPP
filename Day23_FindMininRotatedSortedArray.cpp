/**
 * Problem: 153. Find Minimum in Rotated Sorted Array
 * Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
 * Difficulty: Medium
 * Topics: Array, Binary Search
 * 
 * Time:  O(log n)
 * Space: O(1)
 */

class Solution {
public:
    /**
     * Finds the minimum element in a rotated sorted array (all elements unique).
     * 
     * Core idea:
     * - In a rotated sorted array, one half around mid is always sorted.
     * - If nums[mid] < nums[right] → right half is sorted → min is in left half or at mid.
     * - Else → right half is not sorted → min is in right half (after mid).
     * - Keep shrinking search space until left == right.
     * 
     * Edge Cases:
     *   - [1] → 1
     *   - [2,1] → 1
     *   - [3,4,5,1,2] → 1
     *   - [11,13,15,17] → 11 (no rotation)
     * 
     * @param nums: rotated sorted array
     * @return: minimum element in nums
     */
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] < nums[right]) {
                // Right half is sorted → min is in left half or at mid
                right = mid;
            } else {
                // Right half is not sorted → min is in right half (after mid)
                left = mid + 1;
            }
        }

        // When left == right, that is the minimum element
        return nums[left];
    }
};

/*
 * Example Usage (for testing in local IDE / LeetCode):
 *
 * Solution sol;
 * vector<int> nums1 = {3, 4, 5, 1, 2};
 * cout << sol.findMin(nums1) << endl; // Output: 1
 *
 * vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
 * cout << sol.findMin(nums2) << endl; // Output: 0
 */

