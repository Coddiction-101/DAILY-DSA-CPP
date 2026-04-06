#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Function to check unique occurrences
bool uniqueOccurrence(vector<int> &arr)
{
    unordered_map<int, int> freq;

    // Step 1: Frequency map
    for (int num : arr)
    {
        freq[num]++;
    }

    // Step 2: Store counts in set
    unordered_set<int> st;
    for (auto i : freq)
    {
        st.insert(i.second);
    }

    // Step 3: Compare sizes
    return freq.size() == st.size();   
}

int main()
{
    vector<int> arr = {1, 2, 2, 1, 1, 3};

    if (uniqueOccurrence(arr))
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }

    return 0;
}
