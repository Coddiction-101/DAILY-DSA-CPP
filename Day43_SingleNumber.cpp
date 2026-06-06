class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        
        for(int bit = 0; bit < 32; bit++) {
            int count = 0;
            
            for(int num : nums) {
                if(num & (1 << bit)) {
                    count++;
                }
            }
            
            if(count % 2 == 1) {
                result |= (1 << bit);
            }
        }
        
        return result;
    }
};
