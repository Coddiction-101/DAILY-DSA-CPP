/*
 * Problem: 88. Merge Sorted Array (LeetCode)
 * Link: https://leetcode.com/problems/merge-sorted-array/
 *
 * Description:
 * You are given two sorted arrays:
 * - nums1 of size m + n, where the first m elements are valid and the rest are 0.
 * - nums2 of size n.
 *
 * Merge nums2 into nums1 so that nums1 becomes a single sorted array.
 * Do this in-place. Don't return anything, modify nums1 in-place.
 *
 * Example:
 *   Input:  nums1 = [1,2,3,0,0,0], m=3, nums2 = [2,5,6], n=3
 *   Output: nums1 = [1,2,2,3,5,6]
 *
 * Approach:
 * - We cannot fill from the front because we might overwrite valid nums1 elements.
 * - So we fill from the end using three pointers:
 *   - i = m-1 → points to the last valid element in nums1
 *   - j = n-1 → points to the last element in nums2
 *   - k = m+n-1 → write position in nums1
 * - While both i and j are in range:
 *   - Compare nums1[i] and nums2[j]
 *   - Place the larger element at nums1[k] and move the pointer back
 * - After the loop:
 *   - If nums2 still has elements left, copy them into nums1 from k backwards
 *   - If nums1 has leftover elements, they are already in place → nothing to do
 *
 * Time Complexity: O(m + n)
 * Space Complexity: O(1)
 */

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;      // last valid index in nums1
        int j = n - 1;      // last index in nums2
        int k = m + n - 1;  // last index in nums1 (fill from the end)

        // Step 1: Compare from end and place the larger element at nums1[k]
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }

        // Step 2: Copy remaining elements from nums2 (if any)
        // If nums1 still has elements, they are already in place at correct indices
        while (j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};

