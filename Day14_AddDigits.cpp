// Problem: Add Digits (LeetCode 258)
// Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.

#include <iostream>
using namespace std;

class Solution {
public:
    // Method 1: Simple loop (easy to understand)
    // - While num has more than one digit, keep summing its digits
    // - Extract digits using % 10 and / 10
    // - Update num = sum and repeat
    int addDigits(int num) {
        // Keep going until num becomes a single digit (less than 10)
        while (num >= 10) {
            int sum = 0;  // to store sum of digits of current num

            // Extract each digit and add to sum
            while (num > 0) {
                sum += num % 10;  // add last digit to sum
                num /= 10;        // remove last digit
            }

            // Now num becomes the new sum
            num = sum;
        }

        // Now num is a single digit, return it
        return num;
    }

    // Method 2: Math trick (digital root) - O(1)
    // - If num == 0, answer is 0
    // - Else, answer is 1 + (num - 1) % 9
    // This is the digital root formula
    int addDigitsMath(int num) {
        if (num == 0) {
            return 0;
        }
        return 1 + (num - 1) % 9;
    }
};

// Driver code to test both methods
int main() {
    Solution s;

    // Test case 1: 38 → 3+8=11 → 1+1=2
    cout << "38 -> " << s.addDigits(38) << endl;        // 2
    cout << "38 (math) -> " << s.addDigitsMath(38) << endl;  // 2

    // Test case 2: 0 → 0
    cout << "0 -> " << s.addDigits(0) << endl;          // 0
    cout << "0 (math) -> " << s.addDigitsMath(0) << endl;    // 0

    // Test case 3: 123 → 1+2+3=6
    cout << "123 -> " << s.addDigits(123) << endl;      // 6
    cout << "123 (math) -> " << s.addDigitsMath(123) << endl;  // 6

    // Test case 4: 999 → 9+9+9=27 → 2+7=9
    cout << "999 -> " << s.addDigits(999) << endl;      // 9
    cout << "999 (math) -> " << s.addDigitsMath(999) << endl;  // 9

    return 0;
}
