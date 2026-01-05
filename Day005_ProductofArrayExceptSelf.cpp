
#include<iostream>
#include<vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, 1);

    // Compute the left product
    for(int i = 1; i< n; i++) {
        result[i] = result[i - 1] * nums[i - 1];
    }

    //Compute the right product
    int rightProduct = 1;
    for(int i = n - 1; i >= 0; i--) {
        result[i] *= rightProduct;
        rightProduct *= nums[i];
    }
    return result;
}

int main(){
    vector<int> nums = {1, 2, 3 , 4};
    vector<int> res = productExceptSelf(nums);

    cout <<"Result: ";
    for(int x : res) cout << x <<" ";
    return 0;
}
