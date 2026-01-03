#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool findDuplicates(vector<int> &nums)
{
    unordered_set<int> seen;

    for (int x : nums)
    {
        if (seen.count(x))
            return true;
        seen.insert(x);
    }
    return false;
}

int main()
{
    vector<int> n1 = {1, 2, 3, 4}; // 0
    vector<int> n2 = {1, 2, 3, 3}; // 1

    cout << "Contain Duplicate: " << findDuplicates(n1) << endl;
    cout << "Contain Duplicate: " << findDuplicates(n2) << endl;
    return 0;
}
