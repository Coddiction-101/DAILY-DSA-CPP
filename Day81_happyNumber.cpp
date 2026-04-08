#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;  
        
        while(n != 1) {
            int sum = 0;
            
            while(n > 0) {
                int digit = n % 10;
                sum += digit * digit;
                n /= 10;
            }
            
            if(seen.count(sum)) return false;
            
            seen.insert(sum);
            n = sum;
        }
        
        return true; 
    }
};

int main() {
    cout << "=== Day 81: Happy Number ===" << endl;
    Solution solution;
    
    // Test Case 1
    {
        int n = 19;
        cout << "Test 1: n = " << n << endl;
        cout << "Output: " << (solution.isHappy(n) ? "true" : "false");
        cout << " (Expected: true)" << endl;
        cout << "Process: 1²+9²=82 → 8²+2²=68 → 6²+8²=100 → 1²+0²+0²=1" << endl << endl;
    }
    
    // Test Case 2
    {
        int n = 2;
        cout << "Test 2: n = " << n << endl;
        cout << "Output: " << (solution.isHappy(n) ? "true" : "false");
        cout << " (Expected: false)" << endl;
        cout << "Gets stuck in a cycle" << endl << endl;
    }
    
    // Test Case 3
    {
        int n = 1;
        cout << "Test 3: n = " << n << endl;
        cout << "Output: " << (solution.isHappy(n) ? "true" : "false");
        cout << " (Expected: true)" << endl;
        cout << "Already 1!" << endl << endl;
    }
    
    return 0;
}
