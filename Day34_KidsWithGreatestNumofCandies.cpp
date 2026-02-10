#include <bits/stdc++.h>
using namespace std;

/*
    Problem:
    For each kid, check whether giving them extraCandies
    can make their total candies greater than or equal
    to the current maximum candies among all kids.
*/

class code
{
public:
    vector<bool> kidzwithCandies(vector<int> &candies, int extraCandies)
    {
        // Step 1: Find the current maximum candies
        int maxCandies = *max_element(candies.begin(), candies.end());

        // Step 2: Store result for each kid
        vector<bool> result;

        // Step 3: Check each kid independently
        for (int i = 0; i < candies.size(); i++)
        {
            // If after adding extraCandies,
            // this kid can reach or exceed maxCandies
            if (candies[i] + extraCandies >= maxCandies)
            {
                result.push_back(true);
            }
            else
            {
                result.push_back(false);
            }
        }

        return result;
    }
};

int main()
{
    code cc;

    // Number of kids
    int n;
    cin >> n;

    // Candies array input
    vector<int> candies(n);
    for (int i = 0; i < n; i++)
    {
        cin >> candies[i];
    }

    // Extra candies given to any one kid
    int extraCandies;
    cin >> extraCandies;

    // Function call
    vector<bool> result = cc.kidzwithCandies(candies, extraCandies);

    // Output result
    for (bool val : result)
    {
        cout << (val ? "True " : "False ");
    }

    return 0;
}
