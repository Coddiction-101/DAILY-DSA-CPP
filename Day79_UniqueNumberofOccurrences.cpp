class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;

        for (int num : arr) {
            freq[num]++;
        }

        unordered_set<int> st;

        for (auto it : freq) {
            st.insert(it.second);
        }

        return freq.size() == st.size();
    }
};
