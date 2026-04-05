#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        // Create sets to remove duplicates and enable O(1) lookup
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());
        
        vector<int> list1;  // Elements in nums1 but not in nums2
        vector<int> list2;  // Elements in nums2 but not in nums1
        
        // Find elements in set1 not in set2
        for(int num : set1) {
            if(set2.find(num) == set2.end()) {
                list1.push_back(num);
            }
        }
        
        // Find elements in set2 not in set1
        for(int num : set2) {
            if(set1.find(num) == set1.end()) {
                list2.push_back(num);
            }
        }
        
        return {list1, list2};
    }
};

int main() {
    cout << "=== Day 77: Find the Difference of Two Arrays ===" << endl;
    Solution solution;
    
    // Test Case 1
    {
        vector<int> nums1 = {1, 2, 3};
        vector<int> nums2 = {2, 4, 6};
        cout << "Test 1: nums1 = [1,2,3], nums2 = [2,4,6]" << endl;
        vector<vector<int>> result = solution.findDifference(nums1, nums2);
        cout << "Output: [[";
        for(int i = 0; i < result[0].size(); i++) {
            cout << result[0][i];
            if(i < result[0].size() - 1) cout << ",";
        }
        cout << "],[";
        for(int i = 0; i < result[1].size(); i++) {
            cout << result[1][i];
            if(i < result[1].size() - 1) cout << ",";
        }
        cout << "]]" << endl;
        cout << "Expected: [[1,3],[4,6]]" << endl << endl;
    }
    
    // Test Case 2
    {
        vector<int> nums1 = {1, 2, 3, 3};
        vector<int> nums2 = {1, 1, 2, 2};
        cout << "Test 2: nums1 = [1,2,3,3], nums2 = [1,1,2,2]" << endl;
        vector<vector<int>> result = solution.findDifference(nums1, nums2);
        cout << "Output: [[";
        for(int i = 0; i < result[0].size(); i++) {
            cout << result[0][i];
            if(i < result[0].size() - 1) cout << ",";
        }
        cout << "],[";
        for(int i = 0; i < result[1].size(); i++) {
            cout << result[1][i];
            if(i < result[1].size() - 1) cout << ",";
        }
        cout << "]]" << endl;
        cout << "Expected: [[3],[]]" << endl << endl;
    }
    
    return 0;
}
 
