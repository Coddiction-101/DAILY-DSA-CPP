#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;  // value -> index

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];  // what we need to add with nums[i] to get target

            // If complement is already in map, we found our pair
            if (mp.find(complement) != mp.end()) {
                return {mp[complement], i};
            }

            // Store current value and its index
            mp[nums[i]] = i;
        }

        // According to the problem, we always have exactly one solution,
        // so this line is just for compilation; it will never be hit
        return {};
    }
};

// Utility function to print a vector
void printVector(const vector<int>& v, const string& label) {
    cout << label << ": [";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i < v.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

// Main function for local testing
int main() {
    Solution sol;

    // Test Case 1: [2,7,11,15], target = 9 → [0,1]
    {
        cout << "=== Test Case 1: [2,7,11,15], target = 9 ===" << endl;
        vector<int> nums = {2, 7, 11, 15};
        int target = 9;

        cout << "nums: ";
        for (int x : nums) cout << x << " ";
        cout << endl;
        cout << "target: " << target << endl;

        vector<int> result = sol.twoSum(nums, target);
        printVector(result, "Result");
        cout << endl;
    }

    // Test Case 2: [3,2,4], target = 6 → [1,2]
    {
        cout << "=== Test Case 2: [3,2,4], target = 6 ===" << endl;
        vector<int> nums = {3, 2, 4};
        int target = 6;

        cout << "nums: ";
        for (int x : nums) cout << x << " ";
        cout << endl;
        cout << "target: " << target << endl;

        vector<int> result = sol.twoSum(nums, target);
        printVector(result, "Result");
        cout << endl;
    }

    // Test Case 3: [3,3], target = 6 → [0,1]
    {
        cout << "=== Test Case 3: [3,3], target = 6 ===" << endl;
        vector<int> nums = {3, 3};
        int target = 6;

        cout << "nums: ";
        for (int x : nums) cout << x << " ";
        cout << endl;
        cout << "target: " << target << endl;

        vector<int> result = sol.twoSum(nums, target);
        printVector(result, "Result");
        cout << endl;
    }

    return 0;
}
