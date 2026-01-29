 /**
 * Day 29: LC 347 - Top K Frequent Elements
 * Steps:
 * 1. HashMap: Count frequency → freq[num]++
 * 2. Buckets: buckets[freq] = nums → bucket sort  
 * 3. Reverse: From high freq → collect k elements
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Count frequency
        unordered_map<int, int> freq;
        for(int num : nums) freq[num]++;
        
        // Step 2: Buckets by frequency (bucket sort)
        vector<vector<int>> buckets(nums.size() + 1);
        for(auto& p : freq) buckets[p.second].push_back(p.first);
        
        // Step 3: Collect top k from highest frequency
        vector<int> result;
        for(int i = buckets.size() - 1; i >= 0; i--) {
            for(int num : buckets[i]) {
                result.push_back(num);
                if(result.size() == k) return result;
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    
   
    vector<int> nums = {1,2,2,3,3,3};
    int k = 2;
    
    vector<int> result = sol.topKFrequent(nums, k);
    
    cout << "Top " << k << " frequent: [";
    for(size_t i = 0; i < result.size(); i++) {
        cout << result[i];
        if(i < result.size() - 1) cout << ",";
    }
    cout << "]" << endl;  // [3,2]
    
    return 0;
}

