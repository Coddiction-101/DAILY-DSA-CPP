 #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zeros = 0;      // Count of zeros in current window
        int left = 0;       // Left pointer of window
        int maxlen = 0;     // Maximum length found
        
        for(int right = 0; right < nums.size(); right++) {
            // Expand window: if 0, increment zero count
            if(nums[right] == 0) {
                zeros++;
            }
            
            // Shrink window: if more than 1 zero, move left
            while(zeros > 1) {
                if(nums[left] == 0) {
                    zeros--;
                }
                left++;
            }
            
            // Update max length
            // right - left gives window size - 1 (accounting for deletion)
            maxlen = max(maxlen, right - left);
        }
        
        return maxlen;
    }
};

 int main() {
     Solution solution;
    
    // Test Case 1
    {
        vector<int> nums = {1,1,0,1};
        cout << "Test 1: nums = [1,1,0,1]" << endl;
        cout << "Output: " << solution.longestSubarray(nums);
        cout << " (Expected: 3)" << endl;
        cout << "Explanation: Delete 0, get [1,1,1]" << endl << endl;
    }
    
    // Test Case 2
    {
        vector<int> nums = {0,1,1,1,0,1,1,0,1};
        cout << "Test 2: nums = [0,1,1,1,0,1,1,0,1]" << endl;
        cout << "Output: " << solution.longestSubarray(nums);
        cout << " (Expected: 5)" << endl;
        cout << "Explanation: Delete middle 0" << endl << endl;
    }
    
    // Test Case 3
    {
        vector<int> nums = {1,1,1};
        cout << "Test 3: nums = [1,1,1]" << endl;
        cout << "Output: " << solution.longestSubarray(nums);
        cout << " (Expected: 2)" << endl;
        cout << "Explanation: Must delete one element" << endl << endl;
    }
    
    // Test Case 4
    {
        vector<int> nums = {0,0,0};
        cout << "Test 4: nums = [0,0,0]" << endl;
        cout << "Output: " << solution.longestSubarray(nums);
        cout << " (Expected: 0)" << endl;
        cout << "Explanation: All zeros" << endl << endl;
    }
    
    // Test Case 5
    {
        vector<int> nums = {1,0,1,1,0,1};
        cout << "Test 5: nums = [1,0,1,1,0,1]" << endl;
        cout << "Output: " << solution.longestSubarray(nums);
        cout << " (Expected: 3)" << endl;
        cout << "Explanation: Delete either 0, get max 3" << endl << endl;
    }
    
    return 0;
}

/*
 * Why right - left instead of right - left + 1?
 * - Normal window size = right - left + 1
 * - But we MUST delete one element
 * - So final length = (right - left + 1) - 1 = right - left
 * 
 * This automatically handles the deletion requirement!
 */
