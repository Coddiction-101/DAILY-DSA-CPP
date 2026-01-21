/*
 * Problem: 283. Move Zeroes (LeetCode)
 * Date: January 06, 2026
 * Difficulty: Easy
 * Topics: Array, Two Pointers, In-Place
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * Problem Link: https://leetcode.com/problems/move-zeroes/description/
 *
 * Problem Statement:
 * Given an integer array nums, move all 0's to the end of it while maintaining the
 * relative order of the non-zero elements. Do it in-place (modify nums itself).
 *
 * Examples:
 *   Input:  [1,0,1,3,1,2,4,0]
 *   Output: [1,1,3,1,2,4,0,0]
 *
 * Key Insight: Two Pointers (Read + Write)
 * - We want all non-zero elements at the front, in original order → zeros automatically go to the end.
 * - Use a pointer `position` to track where the next non-zero element should go.
 * - Traverse with `i` (read pointer):
 *     - If nums[i] != 0 → move it to nums[position] and increment position.
 * - Since we’re modifying in-place, we can simply return the modified nums.
 */

#include <iostream>
#include <vector>
using namespace std;

/*
 * Function: moveZeros / moveZeroes
 * Purpose: Move all zeros to the end of the array, keeping non-zero elements in order.
 * Steps:
 *   1. Initialize `position = 0` → this is the next write index for a non-zero element.
 *   2. Traverse each index `i` from 0 to n-1:
 *        - If nums[i] != 0 → swap it to nums[position] and move position forward.
 *   3. After the loop, all non-zero elements are at the front, zeros at the end.
 *   4. Return the modified nums array.
 *
 * Why it works?
 * - We are effectively building a new “non-zero front” portion of the array in-place.
 * - Each non-zero element is moved to its correct position in the result.
 * - Time: O(n), Space: O(1) extra.
 */
vector<int> moveZeros(vector<int>& nums) {
    int position = 0;  // Where to place the next non-zero element

    // Traverse all elements
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            // Move non-zero element to the front
            swap(nums[i], nums[position]);
            position++;  // Move write pointer forward
        }
    }

    return nums;  // Return the modified array (nums is changed in-place)
}

// Utility function to print a vector
void printVector(const vector<int>& nums, const string& label) {
    cout << label << ": [";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << " ";
    }
    cout << "]" << endl;
}

// Main function for local testing
int main() {
    cout << "=== Day 6: Move Zeroes (LeetCode 283) ===" << endl;

    // Test Case 1: [1,0,1,3,1,2,4,0] → [1,1,3,1,2,4,0,0]
    {
        vector<int> arr = {1, 0, 1, 3, 1, 2, 4, 0};
        printVector("Input", arr);

        vector<int> res = moveZeros(arr);  // modifies arr in-place
        printVector("Output", res);
        cout << endl;
    }

    // Test Case 2: [0,1,0,3,12] → [1,3,12,0,0]
    {
        vector<int> arr = {0, 1, 0, 3, 12};
        printVector("Input", arr);

        vector<int> res = moveZeros(arr);  // modifies arr in-place
        printVector("Output", res);
        cout << endl;
    }

    // Test Case 3: [0] → [0]
    {
        vector<int> arr = {0};
        printVector("Input", arr);

        vector<int> res = moveZeros(arr);
        printVector("Output", res);
        cout << endl;
    }

    // Test Case 4: [1,2,3] → [1,2,3] (no zeros)
    {
        vector<int> arr = {1, 2, 3};
        printVector("Input", arr);

        vector<int> res = moveZeros(arr);
        printVector("Output", res);
        cout << endl;
    }

    return 0;
}
