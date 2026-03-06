/*
 * Problem: 912. Sort an Array (LeetCode)
 * Difficulty: Medium
 * Topics: Array, Sorting, Divide and Conquer, Merge Sort
 * Time Complexity: O(n log n)
 * Space Complexity: O(n)
 * Problem Link: https://leetcode.com/problems/sort-an-array/
 *
 * Problem Statement:
 * Given an array of integers nums, sort the array in ascending order
 * and return the sorted array.
 *
 * You must solve the problem without using built-in sorting functions
 * like sort() from the standard library.
 *
 * Example:
 *   Input:  nums = [5,2,3,1]
 *   Output: [1,2,3,5]
 *
 *   Input:  nums = [5,1,1,2,0,0]
 *   Output: [0,0,1,1,2,5]
 *
 * Key Insight: Merge Sort (Divide and Conquer)
 *
 * Merge Sort works in 3 main steps:
 *
 * 1. Divide
 *    Split the array into two halves recursively
 *
 * 2. Conquer
 *    Sort the left half and right half separately
 *
 * 3. Combine
 *    Merge the two sorted halves into one sorted array
 *
 * Why Merge Sort?
 * - Guaranteed O(n log n) time complexity
 * - Very stable and reliable sorting algorithm
 * - Great for learning divide and conquer strategy
 */

#include <iostream>
#include <vector>
using namespace std;

/*
 * Function: merge
 * Purpose: Merge two sorted halves of the array into a single sorted section
 *
 * Parameters:
 *   nums - original array
 *   left - starting index
 *   mid  - middle index
 *   right - ending index
 *
 * Example:
 * Left half  = [1,3,5]
 * Right half = [2,4,6]
 *
 * After merge:
 * Result = [1,2,3,4,5,6]
 */
void merge(vector<int>& nums, int left, int mid, int right) {

    vector<int> temp;  // temporary array to store merged result

    int i = left;      // pointer for left half
    int j = mid + 1;   // pointer for right half

    // Compare elements from both halves and store the smaller one
    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) {
            temp.push_back(nums[i]);
            i++;
        } else {
            temp.push_back(nums[j]);
            j++;
        }
    }

    // If elements remain in the left half
    while (i <= mid) {
        temp.push_back(nums[i]);
        i++;
    }

    // If elements remain in the right half
    while (j <= right) {
        temp.push_back(nums[j]);
        j++;
    }

    // Copy sorted elements back to the original array
    for (int k = left; k <= right; k++) {
        nums[k] = temp[k - left];
    }
}

/*
 * Function: mergeSort
 * Purpose: Recursively divide the array and sort it
 *
 * Steps:
 *   1. Find middle index
 *   2. Recursively sort left half
 *   3. Recursively sort right half
 *   4. Merge the sorted halves
 */
void mergeSort(vector<int>& nums, int left, int right) {

    // Base case: when array has one element
    if (left >= right) return;

    int mid = left + (right - left) / 2;

    // Sort left half
    mergeSort(nums, left, mid);

    // Sort right half
    mergeSort(nums, mid + 1, right);

    // Merge sorted halves
    merge(nums, left, mid, right);
}

/*
 * Function: sortArray
 * Purpose: Main function used by LeetCode
 * It calls mergeSort on the entire array
 */
vector<int> sortArray(vector<int>& nums) {

    mergeSort(nums, 0, nums.size() - 1);

    return nums;
}

/*
 * Utility function to print vector
 */
void printVector(const vector<int>& nums, const string& label) {
    cout << label << ": [";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << " ";
    }
    cout << "]" << endl;
}

/*
 * Main function for local testing
 */
int main() {

    cout << "=== Day 46: Sort an Array (LeetCode 912) ===" << endl;

    // Test Case 1
    {
        vector<int> arr = {5, 2, 3, 1};

        printVector(arr, "Input");

        sortArray(arr);

        printVector(arr, "Sorted");
        cout << endl;
    }

    // Test Case 2
    {
        vector<int> arr = {5, 1, 1, 2, 0, 0};

        printVector(arr, "Input");

        sortArray(arr);

        printVector(arr, "Sorted");
        cout << endl;
    }

    // Test Case 3
    {
        vector<int> arr = {10, 9, 8, 7, 6, 5};

        printVector(arr, "Input");

        sortArray(arr);

        printVector(arr, "Sorted");
        cout << endl;
    }

    return 0;
}
