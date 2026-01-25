#include <iostream>
#include <vector>
using namespace std;

/*
    Problem: 34. Find First and Last Position of Element in Sorted Array

    Idea:
    - The array is sorted → use Binary Search
    - We need two positions:
        1. First occurrence of target
        2. Last occurrence of target
    - Perform two binary searches with slight modifications

    Time Complexity: O(log n)
    Space Complexity: O(1)
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {findFirst(nums, target), findLast(nums, target)};
    }

    // Binary search to find the first occurrence
    int findFirst(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int ans = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                ans = mid;          // possible answer
                right = mid - 1;    // move left to find earlier occurrence
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return ans;
    }

    // Binary search to find the last occurrence
    int findLast(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int ans = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                ans = mid;         // possible answer
                left = mid + 1;    // move right to find later occurrence
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return ans;
    }
};

