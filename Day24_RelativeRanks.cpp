#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
    Problem: 506. Relative Ranks

    Approach:
    - Store each score with its original index
    - Sort scores in descending order
    - Assign medals to top 3, ranks to the rest
    - Place results back using original indices

    Time Complexity: O(n log n)
    Space Complexity: O(n)
*/

vector<string> findRelativeRanks(vector<int>& score) {
    int n = score.size();

    // Pair: {score, original_index}
    vector<pair<int, int>> athletes;
    for (int i = 0; i < n; i++) {
        athletes.push_back({score[i], i});
    }

    // Sort by score in descending order
    sort(athletes.begin(), athletes.end(), greater<>());

    vector<string> result(n);

    for (int i = 0; i < n; i++) {
        int originalIndex = athletes[i].second;

        if (i == 0)
            result[originalIndex] = "Gold Medal";
        else if (i == 1)
            result[originalIndex] = "Silver Medal";
        else if (i == 2)
            result[originalIndex] = "Bronze Medal";
        else
            result[originalIndex] = to_string(i + 1);
    }

    return result;
}

// Local testing
int main() {
    vector<int> score = {10, 3, 8, 9, 4};
    vector<string> ranks = findRelativeRanks(score);

    for (string &s : ranks)
        cout << s << " ";

    return 0;
}

