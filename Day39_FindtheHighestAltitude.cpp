/*
 * Day 39 - Daily DSA in C++
 * Problem: 1732. Find the Highest Altitude (LeetCode)
 * Date: February 27, 2026
 * Difficulty: Easy
 * Topics: Array, Prefix Sum
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 *
 * Problem Link:
 * https://leetcode.com/problems/find-the-highest-altitude/
 *
 * -------------------------------------------------------------------
 * Problem Statement:
 * There is a biker going on a road trip. The road trip consists of n + 1 points 
 * at different altitudes. The biker starts at altitude 0.
 *
 * You are given an integer array gain of length n where gain[i] is the net gain 
 * in altitude between points i and i + 1.
 *
 * Return the highest altitude the biker reaches.
 *
 * -------------------------------------------------------------------
 * Example:
 *
 *   Input:  gain = [-5,1,5,0,-7]
 *   Output: 1
 *
 *   Explanation:
 *   Start altitude = 0
 *   After each step:
 *   0 → -5 → -4 → 1 → 1 → -6
 *   Highest altitude reached = 1
 *
 * -------------------------------------------------------------------
 * Key Insight:
 * This is a Prefix Sum problem.
 *
 * - Start from altitude = 0
 * - Keep adding gain[i] to current altitude
 * - Track maximum altitude reached during traversal
 *
 * Why it works:
 * - Altitude at any point = sum of all previous gains
 * - We just need the maximum running sum
 * - Single pass solution → O(n)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
     * Function: largestAltitude
     * Purpose: Return highest altitude reached during the trip
     *
     * Approach:
     * 1. Start with current altitude = 0
     * 2. Maintain a variable maxAltitude
     * 3. Traverse gain array
     * 4. Add gain[i] to current
     * 5. Update maxAltitude if needed
     */
    int largestAltitude(vector<int>& gain) {
        int current = 0;      // current altitude
        int maxAltitude = 0;  // highest altitude seen so far
        
        for(int i = 0; i < gain.size(); i++) {
            current += gain[i];               // update altitude
            maxAltitude = max(maxAltitude, current); // update maximum
        }
        
        return maxAltitude;
    }
};


// Main function for local testing
int main() {
    cout << "=== Day 38: Find the Highest Altitude ===" << endl;
    Solution solution;
    
    // Test Case 1
    {
        vector<int> gain = {-5,1,5,0,-7};
        cout << "Test 1: gain = [-5,1,5,0,-7]" << endl;
        cout << "Output: " << solution.largestAltitude(gain) << " (Expected: 1)" << endl;
        cout << endl;
    }
    
    // Test Case 2
    {
        vector<int> gain = {-4,-3,-2,-1,4,3,2};
        cout << "Test 2: gain = [-4,-3,-2,-1,4,3,2]" << endl;
        cout << "Output: " << solution.largestAltitude(gain) << " (Expected: 0)" << endl;
        cout << endl;
    }
    
    // Edge Case - All positive
    {
        vector<int> gain = {1,2,3};
        cout << "Test 3: gain = [1,2,3]" << endl;
        cout << "Output: " << solution.largestAltitude(gain) << " (Expected: 6)" << endl;
        cout << endl;
    }
    
    // Edge Case - All negative
    {
        vector<int> gain = {-1,-2,-3};
        cout << "Test 4: gain = [-1,-2,-3]" << endl;
        cout << "Output: " << solution.largestAltitude(gain) << " (Expected: 0)" << endl;
        cout << endl;
    }
    
    return 0;
}


/*
 * Dry Run:
 * Input: gain = [-5,1,5,0,-7]
 *
 * Start: current=0, maxAltitude=0
 *
 * i=0 → current = -5 → max=0
 * i=1 → current = -4 → max=0
 * i=2 → current = 1  → max=1
 * i=3 → current = 1  → max=1
 * i=4 → current = -6 → max=1
 *
 * Final Answer = 1
 *
 * -------------------------------------------------------------------
 *
 * Key Points:
 *
 * 1. Prefix Sum Concept:
 *    - Running total of array elements
 *
 * 2. Why max starts from 0?
 *    - Because biker starts at altitude 0
 *    - Even if all gains are negative, highest altitude is 0
 *
 * 3. Efficiency:
 *    - Single traversal → O(n)
 *    - No extra data structure → O(1)
 *
 * 4. Pattern Recognition:
 *    - Whenever problem says cumulative value
 *    - And asks maximum/minimum of it
 *    → Think Prefix Sum
 */
