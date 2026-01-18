/*
 * Problem: 35. Search Insert Position (LeetCode)
 *
 * Given a sorted array of distinct integers and a target value, return the index
 * if the target is found. If not, return the index where it would be inserted
 * in order.
 *
 * Example:
 *  nums = [1,3,5,6], target = 5  -> output: 2
 *  nums = [1,3,5,6], target = 2  -> output: 1
 *  nums = [1,3,5,6], target = 7  -> output: 4
 *
 * Approach: Binary Search
 * - Since the array is sorted, we use binary search instead of linear search.
 * - If target is found at mid, return mid.
 * - If target is smaller than nums[mid], search in the left half.
 * - If target is greater than nums[mid], search in the right half.
 * - If we exit the loop without finding target, 'left' will be the position
 *   where target should be inserted to maintain sorted order.
 *
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        // Standard binary search
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                // Target found at index mid
                return mid;
            } else if (nums[mid] < target) {
                // Target lies in the right half
                left = mid + 1;
            } else {
                // Target lies in the left half
                right = mid - 1;
            }
        }

        // Target not found:
        // 'left' is the index where target should be inserted
        return left;
    }
};

