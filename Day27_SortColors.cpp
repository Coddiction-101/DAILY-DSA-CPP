#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;                 // Boundary for 0s
        int mid = 0;                 // Current element index
        int high = nums.size() - 1;  // Boundary for 2s

        // Traverse the array once
        while (mid <= high) {

            // If current element is 0
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;   // expand 0s region
                mid++;   // move forward
            }
            // If current element is 1
            else if (nums[mid] == 1) {
                mid++;   // already in correct region
            }
            // If current element is 2
            else {
                swap(nums[mid], nums[high]);
                high--;  // expand 2s region
                // mid NOT incremented here
                // because swapped value needs re-check
            }
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 0, 2, 1, 1, 0}; // sample input

    // Call the sortColors function
    solution.sortColors(nums);

    // Output the sorted array
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
