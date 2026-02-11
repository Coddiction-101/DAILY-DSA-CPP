/*
 * Day 33 - Daily DSA in C++
 * Problem: 605. Can Place Flowers (LeetCode)
 * Date: February 02, 2026
 * Difficulty: Easy
 * Topics: Arrays, Greedy
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 *
 * Problem Link:
 * https://leetcode.com/problems/can-place-flowers/
 *
 * -------------------------------------------------------------------
 * Problem Statement:
 * You are given an integer array flowerbed where:
 *   - 0 represents an empty plot
 *   - 1 represents a plot where a flower is already planted
 *
 * You are also given an integer n representing the number of new flowers
 * you want to plant.
 *
 * Rules:
 *   - No two flowers can be planted in adjacent plots.
 *
 * Task:
 *   Return true if n new flowers can be planted without violating the
 *   adjacency rule, otherwise return false.
 *
 * -------------------------------------------------------------------
 * Examples:
 *
 *   Input:  flowerbed = [1,0,0,0,1], n = 1
 *   Output: true
 *
 *   Input:  flowerbed = [1,0,0,0,1], n = 2
 *   Output: false
 *
 *   Input:  flowerbed = [0,0,0,0], n = 2
 *   Output: true
 *
 * -------------------------------------------------------------------
 * Key Insight:
 * We traverse the flowerbed from left to right and greedily place flowers
 * whenever it is safe to do so.
 *
 * A flower can be planted at index i if:
 *   - flowerbed[i] == 0
 *   - Left neighbor is empty OR i is the first index
 *   - Right neighbor is empty OR i is the last index
 *
 * Once a flower is planted:
 *   - Mark the position as occupied
 *   - Decrement n
 *   - If n becomes 0, we can stop early and return true
 */

#include <bits/stdc++.h>
using namespace std;

class code {
public:
    /*
     * Function: canPlaceFlowers
     * Purpose: Determine whether it is possible to plant n flowers
     *          without any two being adjacent.
     *
     * Approach:
     *   - Iterate through the flowerbed.
     *   - Check left and right neighbors safely using boundary conditions.
     *   - Plant a flower greedily when possible.
     *   - Stop early if all required flowers are planted.
     */
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();

        for (int i = 0; i < size; i++) {

            if (flowerbed[i] == 0) {

                bool leftEmpty = (i == 0 || flowerbed[i - 1] == 0);
                bool rightEmpty = (i == size - 1 || flowerbed[i + 1] == 0);

                if (leftEmpty && rightEmpty) {
                    flowerbed[i] = 1; // plant flower
                    n--;

                    if (n == 0)
                        return true;
                }
            }
        }
        return n <= 0;
    }
};

// Main function for local testing
int main() {
    cout << "=== Day 33: Can Place Flowers ===" << endl;

    code cc;

    // Test Case 1
    {
        vector<int> flowerbed = {1, 0, 0, 0, 1};
        int n = 1;
        cout << "Test 1: [1,0,0,0,1], n = 1 -> "
             << (cc.canPlaceFlowers(flowerbed, n) ? "True" : "False")
             << " (Expected: True)" << endl;
    }

    // Test Case 2
    {
        vector<int> flowerbed = {1, 0, 0, 0, 1};
        int n = 2;
        cout << "Test 2: [1,0,0,0,1], n = 2 -> "
             << (cc.canPlaceFlowers(flowerbed, n) ? "True" : "False")
             << " (Expected: False)" << endl;
    }

    // Test Case 3
    {
        vector<int> flowerbed = {0, 0, 0, 0};
        int n = 2;
        cout << "Test 3: [0,0,0,0], n = 2 -> "
             << (cc.canPlaceFlowers(flowerbed, n) ? "True" : "False")
             << " (Expected: True)" << endl;
    }

    // Test Case 4 (Edge Case)
    {
        vector<int> flowerbed = {0};
        int n = 1;
        cout << "Test 4: [0], n = 1 -> "
             << (cc.canPlaceFlowers(flowerbed, n) ? "True" : "False")
             << " (Expected: True)" << endl;
    }

    return 0;
}
