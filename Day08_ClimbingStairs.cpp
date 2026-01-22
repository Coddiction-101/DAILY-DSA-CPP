/*
 * Problem: 70. Climbing Stairs (LeetCode)
 * Difficulty: Easy
 * Topics: Dynamic Programming, Fibonacci
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * Link: https://leetcode.com/problems/climbing-stairs/
 *
 * Statement:
 * You are climbing a staircase. It takes n steps to reach the top.
 * Each time you can either climb 1 or 2 steps.
 * Return the number of distinct ways to reach the top.
 */

#include <iostream>
using namespace std;

/*
 * Idea:
 * Let ways[i] = number of ways to reach step i.
 * You can come to step i:
 *   - from step i-1 with a 1-step move
 *   - from step i-2 with a 2-step move
 * So:
 *   ways[i] = ways[i-1] + ways[i-2]
 *
 * This is exactly Fibonacci-like.
 * Base:
 *   ways[0] = 1 (1 way to stay at ground)
 *   ways[1] = 1 (1 way to reach first step)
 *
 * We can keep only last two values instead of full array.
 */
int climbStairs(int n) {
    // For n = 0 or 1, both are 1 way.
    if (n <= 1) return 1;

    // prev2 = ways[i-2], prev1 = ways[i-1]
    int prev2 = 1;  // ways[0]
    int prev1 = 1;  // ways[1]

    // Compute ways up to n
    for (int i = 2; i <= n; i++) {
        int current = prev1 + prev2; // ways[i] = ways[i-1] + ways[i-2]
        prev2 = prev1;               // shift window
        prev1 = current;
    }

    return prev1; // ways[n]
}

int main() {
    cout << "=== Climbing Stairs (LeetCode 70) ===" << endl;

    int n1 = 2;
    int n2 = 3;
    int n3 = 4;
    int n4 = 5;

    cout << "n = " << n1 << " → ways = " << climbStairs(n1) << " (expected 2)" << endl;
    cout << "n = " << n2 << " → ways = " << climbStairs(n2) << " (expected 3)" << endl;
    cout << "n = " << n3 << " → ways = " << climbStairs(n3) << " (expected 5)" << endl;
    cout << "n = " << n4 << " → ways = " << climbStairs(n4) << " (expected 8)" << endl;

    return 0;
}

