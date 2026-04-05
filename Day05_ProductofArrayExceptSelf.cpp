#include <iostream>
#include <vector>
using namespace std;


vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, 1);  // result[i] will store the final answer

    // Step 1: Fill result with left product
    // result[i] = product of nums[0] * nums[1] * ... * nums[i-1]
    for (int i = 1; i < n; i++) {
        result[i] = result[i - 1] * nums[i - 1];
    }

    // Step 2: Multiply each result[i] with right product
    // rightProduct = product of nums[i+1] * nums[i+2] * ... * nums[n-1]
    int rightProduct = 1;
    for (int i = n - 1; i >= 0; i--) {
        result[i] *= rightProduct;  // multiply left product with right product
        rightProduct *= nums[i];    // update rightProduct for next (left) index
    }

    return result;
}

// Utility function to print a vector
void printVector(const string& label, const vector<int>& v) {
    cout << label << ": [";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i < v.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

// Main function for local testing
int main() {
    cout << "=== Day 5: Product of Array Except Self (LeetCode 238) ===" << endl;

    // Test Case 1: [1,2,3,4] → [24,12,8,6]
    {
        vector<int> nums = {1, 2, 3, 4};
        vector<int> res = productExceptSelf(nums);

        printVector("Input nums", nums);
        printVector("Result     ", res);
        cout << endl;
    }

    // Test Case 2: [-1,1,0,-3,3] → [0,0,9,0,0]
    {
        vector<int> nums = {-1, 1, 0, -3, 3};
        vector<int> res = productExceptSelf(nums);

        printVector("Input nums", nums);
        printVector("Result     ", res);
        cout << endl;
    }

    // Test Case 3: [2,3] → [3,2]
    {
        vector<int> nums = {2, 3};
        vector<int> res = productExceptSelf(nums);

        printVector("Input nums", nums);
        printVector("Result     ", res);
        cout << endl;
    }

    return 0;
}
