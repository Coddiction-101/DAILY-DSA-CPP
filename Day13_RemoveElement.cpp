#include <iostream>
#include <vector>
using namespace std;

// Remove all occurrences of 'val' from the array in-place
// Return the new length (number of remaining elements)
int removeElement(vector<int>& nums, int val) {
    int k = 0;  // k is the write pointer: where to put the next valid element

    // Traverse the array
    for (int i = 0; i < nums.size(); i++) {
        // If current element is not the value to remove
        if (nums[i] != val) {
            nums[k] = nums[i];  // put this valid element at position k
            k++;                 // move k forward for next valid element
        }
    }

    return k;  // k is now the new length of the array
}

int main() {
    vector<int> n = {1, 2, 2, 3, 4};
    int newLength = removeElement(n, 2);  // remove all 2's

    cout << "New length: " << newLength << endl;
    cout << "Remaining elements: ";
    for (int i = 0; i < newLength; i++) {
        cout << n[i] << " ";
    }
    cout << endl;

    return 0;
}
