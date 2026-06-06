class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        vector<int> freq(101, 0);
        vector<int> result(2, 0);
        
        for (int num : nums) {
            freq[num]++;
        }
        
        for (int count : freq) {
            result[0] += count / 2;
            result[1] += count % 2;
        }
        
        return result;
    }
};
