/*
 * Problem: 162. Find Peak Element (LeetCode)
 * Link: https://leetcode.com/problems/find-peak-element/
 *
 * Problem Statement:
 * Given a 0-indexed integer array nums, find a peak element, and return its index.
 * A peak element is an element that is strictly greater than both its neighbors.
 *
 * You may imagine that nums[-1] = nums[n] = -∞ (so boundary elements only need to be > one neighbor).
 * You can return the index of any peak if there are multiple.
 *
 * Constraints:
 * - 1 <= nums.length <= 1000
 * - nums[i] != nums[i+1] for all valid i
 * - Time: O(log n), Space: O(1)
 *
 * Examples:
 *   Input: nums = [1,2,3,1]       → Output: 2 (because nums[2]=3 is a peak)
 *   Input: nums = [1,2,1,3,5,6,4] → Output: 1 or 5 or another peak index
 *
 * Intuition:
 * - We can't do linear scan because we need O(log n).
 * - Notice: the array has boundaries -∞, so at least one peak always exists.
 * - We use binary search by checking nums[mid] vs nums[mid+1]:
 *   - If nums[mid] > nums[mid + 1] → we are on a “downward” slope → peak is on the left (including mid).
 *   - Else → we are on an “upward” slope → peak is on the right.
 * - We search for the first index where nums[mid] > nums[mid+1] (or mid is last element).
 *
 * Why is that index a peak?
 * - If nums[mid] > nums[mid+1], and the previous point was not “downward”, then:
 *   - nums[mid] > nums[mid+1] (right neighbor)
 *   - nums[mid-1] < nums[mid] (or mid=0, so left neighbor is -∞) → so mid is a peak.
 *
 * Time: O(log n)
 * Space: O(1)
 */

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        int firstTrueIndex = -1;  // will store the first index where condition is true

        // Binary search: find first index such that nums[mid] > nums[mid+1]
        // (last element is always considered "downward" since nums[n] = -∞)
        while (left <= right) {
            int mid = left + (right - left) / 2;  // safe mid calculation

            // Feasible condition: nums[mid] > nums[mid+1]
            // If mid is last index, we treat it as feasible (going down)
            if (mid == n - 1 || nums[mid] > nums[mid + 1]) {
                firstTrueIndex = mid;
                right = mid - 1;  // search in left half
            } else {
                left = mid + 1;   // search in right half
            }
        }

        return firstTrueIndex;
    }
};

