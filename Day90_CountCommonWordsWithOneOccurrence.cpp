class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> freq1;
        unordered_map<string, int> freq2;

        for(int i = 0; i < words1.size(); i++) {
            freq1[words1[i]]++;
        }

        for(int j = 0; j < words2.size(); j++){
            freq2[words2[j]]++;
        }

        int count = 0;

        for(const auto& pair : freq1) {
            if( pair.second == 1 && freq2[pair.first] == 1){
                count++;
            }
        }
        return count;
    }
};
