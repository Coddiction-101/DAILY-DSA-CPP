#include <vector>
#include <algorithm>
using namespace std;

/*
 * Problem: LeetCode 135 - Candy (Hard)
 *
 * There are n children in a line, each with a rating.
 * We must give candies such that:
 *   1. Every child gets at least 1 candy.
 *   2. A child with a higher rating than their neighbor must get more candies than that neighbor.
 *
 * Goal: Minimize the total number of candies.
 *
 * Example:
 *   ratings = [1, 0, 2] → answer = 5 (candies [2,1,2])
 *   ratings = [1, 2, 2] → answer = 4 (candies [1,2,1])
 *
 * Approach: Two-Pass Greedy
 *
 * Why two passes?
 * - A single left-to-right pass only ensures that a higher rating child has more than the left neighbor.
 * - But it may violate the right neighbor constraint.
 *
 * Idea:
 * - We need to satisfy constraints from both sides:
 *   - Left side: if rating[i] > rating[i-1], then candies[i] > candies[i-1]
 *   - Right side: if rating[i] > rating[i+1], then candies[i] > candies[i+1]
 *
 * Steps:
 * 1. Left pass: go left to right, ensure each child has more than left neighbor if rating is higher.
 * 2. Right pass: go right to left, ensure each child has more than right neighbor if rating is higher.
 * 3. Final candies: for each child, take max(left_requirement, right_requirement).
 *
 * Time:  O(n) - three passes over the array.
 * Space: O(n) - two extra arrays of size n.
 */

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n == 0) return 0;

        // left[i] = minimum candies needed to satisfy the left neighbor constraint
        vector<int> left(n, 1);

        // right[i] = minimum candies needed to satisfy the right neighbor constraint
        vector<int> right(n, 1);

        // Step 1: Left to right pass
        // If current rating is higher than left neighbor, give one more than left
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                left[i] = left[i - 1] + 1;
            }
            // If rating is <= left, we can keep left[i] = 1 (minimum)
        }

        // Step 2: Right to left pass
        // If current rating is higher than right neighbor, give one more than right
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                right[i] = right[i + 1] + 1;
            }
            // If rating is <= right, we can keep right[i] = 1 (minimum)
        }

        // Step 3: Combine both constraints
        // For each child, final candies = max(left[i], right[i])
        int total = 0;
        for (int i = 0; i < n; i++) {
            total += max(left[i], right[i]);
        }

        return total;
    }
};

// Example usage (for local testing)
/*
int main() {
    Solution sol;
    vector<int> ratings1 = {1, 0, 2};
    vector<int> ratings2 = {1, 2, 2};

    cout << sol.candy(ratings1) << endl; // Output: 5
    cout << sol.candy(ratings2) << endl; // Output: 4

    return 0;
}
*/
