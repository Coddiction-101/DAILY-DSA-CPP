/**
 * Day 30: LC 42 - Trapping Rain Water ⭐⭐⭐
 * Two Pointers: Process lower side first
 * 1. leftMax = max height seen from left
 * 2. rightMax = max height seen from right  
 * 3. Water = min(leftMax, rightMax) - height[i]
 * O(n) time, O(1) space
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        int water = 0;
        
        while (left < right) {
            if (height[left] < height[right]) {
                // Process left side (lower)
                leftMax = max(leftMax, height[left]);
                water += leftMax - height[left];
                left++;
            } else {
                // Process right side (lower)  
                rightMax = max(rightMax, height[right]);
                water += rightMax - height[right];
                right--;
            }
        }
        return water;
    }
};

int main() {
    Solution sol;
    
    // Single test case for repo
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    int result = sol.trap(height);
    
    cout << "Trapped water: " << result << " units" << endl;  // 6
    return 0;
}

