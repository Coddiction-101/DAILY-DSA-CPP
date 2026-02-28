/*
 * Day 40 - Daily DSA in C++
 * Problem: 33. Search in Rotated Sorted Array (LeetCode)
 * Date: February 10, 2026
 * Difficulty: Medium
 * Topics: Array, Binary Search
 *
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 *
 * Problem Link:
 * https://leetcode.com/problems/search-in-rotated-sorted-array/
 *
 * -------------------------------------------------------------------
 * Problem Statement:
 * There is an integer array nums sorted in ascending order (with distinct values).
 * Prior to being passed to your function, nums is possibly rotated at an 
 * unknown pivot index k (1 <= k < nums.length) such that the resulting array is
 * [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).
 * 
 * For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and 
 * become [4,5,6,7,0,1,2].
 * 
 * Given the array nums after the possible rotation and an integer target, 
 * return the index of target if it is in nums, or -1 if it is not in nums.
 * 
 * You must write an algorithm with O(log n) runtime complexity.
 *
 * -------------------------------------------------------------------
 * Examples:
 *
 *   Input:  nums = [4,5,6,7,0,1,2], target = 0
 *   Output: 4
 *   Explanation: Original array [0,1,2,4,5,6,7] was rotated at index 4
 *
 *   Input:  nums = [4,5,6,7,0,1,2], target = 3
 *   Output: -1
 *   Explanation: 3 is not in the array
 *
 *   Input:  nums = [1], target = 0
 *   Output: -1
 *
 * -------------------------------------------------------------------
 * Key Insight:
 * Modified Binary Search:
 * - Rotated sorted array has TWO sorted portions
 * - At any mid point, ONE side is guaranteed to be sorted
 * - Identify which side is sorted
 * - Check if target lies in that sorted range
 * - Decide to go left or right based on this
 * 
 * Visual:
 * Array: [4,5,6,7,0,1,2]
 *         ↑sorted↑ ↑sorted↑
 * 
 * How to identify sorted side:
 * - If nums[left] <= nums[mid]: Left side is sorted
 * - Else: Right side is sorted (array broke on left)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    /*
     * Function: search
     * Purpose: Find target in rotated sorted array using modified binary search.
     *
     * Approach - Modified Binary Search:
     * - Use standard binary search with left, right, mid pointers
     * - Key difference: Handle rotation by identifying sorted side
     * - One side is always fully sorted
     * - Check if target is in sorted side
     * - Move pointers accordingly
     * 
     * Steps:
     * 1. Initialize: left=0, right=n-1
     * 2. While left <= right:
     *    a. Calculate mid
     *    b. Check if nums[mid] == target (found!)
     *    c. Identify which side is sorted
     *    d. Check if target is in sorted side
     *    e. Move left or right pointer
     * 3. If loop ends, return -1 (not found)
     */
    int search(vector<int>& nums, int target) {
        int left = 0;               // Start of search range
        int right = nums.size() - 1; // End of search range
        
        // Binary search loop
        while(left <= right) {
            // Calculate mid (avoid overflow)
            int mid = left + (right - left) / 2;
            
            // Case 1: Found target at mid
            if(nums[mid] == target) {
                return mid;
            }
            
            // Case 2: Determine which side is sorted
            // and decide where to search next
            
            // Left side is sorted [left...mid]
            // Check: nums[left] <= nums[mid]
            // This means no rotation point between left and mid
            if(nums[left] <= nums[mid]) {
                // Left side is sorted: nums[left] to nums[mid] is ascending
                
                // Check if target lies in this sorted range
                // Target must be: nums[left] <= target < nums[mid]
                if(nums[left] <= target && target < nums[mid]) {
                    // Target is in left sorted portion
                    right = mid - 1;  // Search left half
                } else {
                    // Target is NOT in left sorted portion
                    // Must be in right half (if it exists)
                    left = mid + 1;   // Search right half
                }
            }
            // Right side is sorted [mid...right]
            // This happens when rotation point is in left half
            else {
                // Right side is sorted: nums[mid] to nums[right] is ascending
                
                // Check if target lies in this sorted range
                // Target must be: nums[mid] < target <= nums[right]
                if(nums[mid] < target && target <= nums[right]) {
                    // Target is in right sorted portion
                    left = mid + 1;   // Search right half
                } else {
                    // Target is NOT in right sorted portion
                    // Must be in left half (if it exists)
                    right = mid - 1;  // Search left half
                }
            }
        }
        
        // Target not found in array
        return -1;
    }
};
// Main function for local testing
int main() {
    cout << "=== Day 40: Search in Rotated Sorted Array ===" << endl;
    cout << "🎉 MILESTONE: 40 Days of Consistent Problem Solving! 🎉" << endl;
    cout << endl;
    
    Solution solution;
    
    // Test Case 1
    {
        vector<int> nums = {4,5,6,7,0,1,2};
        int target = 0;
        cout << "Test 1: nums = [4,5,6,7,0,1,2], target = " << target << endl;
        cout << "Output: " << solution.search(nums, target) << " (Expected: 4)" << endl;
        cout << "Explanation: Target 0 is at index 4" << endl;
        cout << endl;
    }
    
    // Test Case 2
    {
        vector<int> nums = {4,5,6,7,0,1,2};
        int target = 3;
        cout << "Test 2: nums = [4,5,6,7,0,1,2], target = " << target << endl;
        cout << "Output: " << solution.search(nums, target) << " (Expected: -1)" << endl;
        cout << "Explanation: Target 3 not in array" << endl;
        cout << endl;
    }
    
    // Test Case 3 (Edge Case - Single Element)
    {
        vector<int> nums = {1};
        int target = 0;
        cout << "Test 3: nums = [1], target = " << target << endl;
        cout << "Output: " << solution.search(nums, target) << " (Expected: -1)" << endl;
        cout << "Explanation: Single element, target not found" << endl;
        cout << endl;
    }
    
    // Test Case 4 (No Rotation)
    {
        vector<int> nums = {1,2,3,4,5,6,7};
        int target = 5;
        cout << "Test 4: nums = [1,2,3,4,5,6,7], target = " << target << endl;
        cout << "Output: " << solution.search(nums, target) << " (Expected: 4)" << endl;
        cout << "Explanation: No rotation, standard binary search" << endl;
        cout << endl;
    }
    
    // Test Case 5 (Target at Rotation Point)
    {
        vector<int> nums = {4,5,6,7,0,1,2};
        int target = 4;
        cout << "Test 5: nums = [4,5,6,7,0,1,2], target = " << target << endl;
        cout << "Output: " << solution.search(nums, target) << " (Expected: 0)" << endl;
        cout << "Explanation: Target at start of rotated array" << endl;
        cout << endl;
    }
    
    return 0;
}

/*
 * Dry Run:
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * 
 * Initial: left=0, right=6
 * 
 * Iteration 1:
 * mid = 0 + (6-0)/2 = 3
 * nums[mid] = nums[3] = 7
 * target = 0, not equal to 7
 * 
 * Check which side is sorted:
 * nums[left]=4, nums[mid]=7 → 4 <= 7 (TRUE)
 * Left side [4,5,6,7] is sorted
 * 
 * Is target in left sorted range?
 * Check: 4 <= 0 < 7? → FALSE
 * Target NOT in left side
 * Search right: left = mid+1 = 4
 * 
 * State: left=4, right=6
 * 
 * Iteration 2:
 * mid = 4 + (6-4)/2 = 5
 * nums[mid] = nums[5] = 1
 * target = 0, not equal to 1
 * 
 * Check which side is sorted:
 * nums[left]=0, nums[mid]=1 → 0 <= 1 (TRUE)
 * Left side [0,1] is sorted
 * 
 * Is target in left sorted range?
 * Check: 0 <= 0 < 1? → TRUE
 * Target IS in left side
 * Search left: right = mid-1 = 4
 * 
 * State: left=4, right=4
 * 
 * Iteration 3:
 * mid = 4 + (4-4)/2 = 4
 * nums[mid] = nums[4] = 0
 * target = 0, EQUAL!
 * 
 * Return 4 ✓
 * 
 * -------------------------------------------------------------------
 * 
 * Key Points:
 * 
 * 1. Why nums[left] <= nums[mid] (with =)?
 *    - When left == mid, we need <= to handle correctly
 *    - Example: [3,1], left=0, mid=0 → 3 <= 3 is TRUE
 * 
 * 2. Sorted side identification:
 *    - If nums[left] <= nums[mid]: Left is sorted
 *    - Else: Right is sorted
 *    - ONE side is ALWAYS sorted (guaranteed)
 * 
 * 3. Range checks:
 *    - Left sorted: nums[left] <= target < nums[mid]
 *    - Right sorted: nums[mid] < target <= nums[right]
 *    - Note the < and <= carefully!
 * 
 * 4. Why O(log n)?
 *    - Each iteration halves search space
 *    - Standard binary search complexity
 * 
 * 5. Rotation point:
 *    - We don't explicitly find it
 *    - We work around it by checking sorted sides
 * 
 * 6. Edge cases handled:
 *    - Single element: left == right initially
 *    - No rotation: Works as standard binary search
 *    - Target at boundaries: <= and >= handle it
 * 
 * 7. Why this is a classic problem:
 *    - Tests binary search understanding
 *    - Tests edge case handling
 *    - Tests logical thinking
 *    - Common in FAANG interviews
 * 
 * 8. Pattern recognition:
 *    Array: [4,5,6,7,0,1,2]
 *           ↑______↑ ↑____↑
 *           sorted   sorted
 *    
 *    At any mid, ONE side is fully sorted
 *    Use that sorted side to make decision
 */
