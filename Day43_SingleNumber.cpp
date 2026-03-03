/*
 * Day 43 - Daily DSA in C++
 * Problem: 136. Single Number (LeetCode)
 * Difficulty: Easy
 * Topics: Array, Bit Manipulation
 *
 * Time Complexity: O(32 × n) = O(n)
 * Space Complexity: O(1)
 *
 * -------------------------------------------------------------------
 * Problem Statement:
 * Given a non-empty array of integers nums, every element appears twice 
 * except for one. Find that single one.
 * 
 * You must implement a solution with a linear runtime complexity and 
 * use only constant extra space.
 *
 * -------------------------------------------------------------------
 * Examples:
 *
 *   Input:  nums = [2,2,1]
 *   Output: 1
 *   Explanation: 1 appears once, 2 appears twice
 *
 *   Input:  nums = [4,1,2,1,2]
 *   Output: 4
 *   Explanation: 4 appears once, all others appear twice
 *
 *   Input:  nums = [1]
 *   Output: 1
 *   Explanation: Only one element
 *
 * -------------------------------------------------------------------
 * Key Insight:
 * Manual Bit Manipulation (Without using XOR operator):
 * - For each bit position (0 to 31), count how many numbers have that bit set
 * - If count is ODD: the single number has that bit set to 1
 * - If count is EVEN: the single number has that bit set to 0
 * 
 * Why this works:
 * - Numbers appearing twice contribute EVEN count to each bit
 * - Single number contributes 1 (ODD) to its set bits
 * - ODD count % 2 = 1, EVEN count % 2 = 0
 * 
 * This is essentially implementing XOR manually!
 * XOR property: a ^ a = 0, a ^ 0 = a
 * 
 * Visual Example:
 * nums = [4,1,2,1,2]
 * Binary:
 * 4 = 100
 * 1 = 001
 * 2 = 010
 * 1 = 001
 * 2 = 010
 * 
 * Bit 0: count = 2 (even) → result bit 0 = 0
 * Bit 1: count = 4 (even) → result bit 1 = 0
 * Bit 2: count = 1 (odd)  → result bit 2 = 1
 * Result = 100 (binary) = 4
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    /*
     * Function: singleNumber
     * Purpose: Find the element that appears only once (manual bit manipulation).
     *
     * Approach - Bit-by-Bit Counting:
     * Instead of using XOR operator (^), we manually implement XOR logic:
     * 1. Process each of 32 bit positions (0 to 31)
     * 2. For each bit position, count how many numbers have that bit set
     * 3. If count is odd, set that bit in result
     * 4. If count is even, leave that bit as 0 in result
     * 
     * Why 32 bits?
     * - Integer in C++ is typically 32 bits
     * - We check all possible bit positions
     * 
     * Bit Operations Used:
     * - (1 << bit): Creates a mask with only bit position 'bit' set to 1
     * - num & mask: Checks if bit is set in num (bitwise AND)
     * - result |= mask: Sets the bit in result (bitwise OR)
     * 
     * Steps:
     * 1. Iterate through all 32 bit positions
     * 2. For each bit, count numbers having that bit set
     * 3. If odd count, set that bit in result
     * 4. Return the final result
     */
    int singleNumber(vector<int>& nums) {
        int result = 0;  // Final answer, initially all bits are 0
        
        // Process each bit position from 0 (rightmost) to 31 (leftmost)
        // In a 32-bit integer: bit 0 is LSB, bit 31 is MSB
        for(int bit = 0; bit < 32; bit++) {
            int count = 0;  // Count of numbers having this bit set
            
            // Count how many numbers have the current bit set
            for(int num : nums) {
                // Check if bit at position 'bit' is set in num
                // (1 << bit) creates a mask: 0001 for bit 0, 0010 for bit 1, etc.
                // num & mask returns non-zero if bit is set
                if(num & (1 << bit)) {
                    count++;  // This number has the bit set
                }
                
                // Example for bit=2, num=4 (binary: 100):
                // (1 << 2) = 100 (binary)
                // 4 & 100 = 100 (non-zero) → bit is set
                //
                // Example for bit=0, num=4 (binary: 100):
                // (1 << 0) = 001 (binary)
                // 4 & 001 = 000 (zero) → bit is not set
            }
            
            // After counting, check if count is odd
            // Pairs cancel out (even count), single number makes it odd
            if(count % 2 == 1) {
                // Odd count means single number has this bit set
                // Set this bit in result using OR operation
                result |= (1 << bit);
                
                // Example: Setting bit 2 in result
                // result = 000, (1 << 2) = 100
                // result |= 100 → result becomes 100
            }
            
            // If count is even, we do nothing
            // That bit remains 0 in result (already initialized to 0)
        }
        
        // Return the reconstructed single number
        return result;
    }
};
// Main function for local testing
int main() {
    cout << "=== Day 43: Single Number (Manual Bit Manipulation) ===" << endl;
    Solution solution;
    
    // Test Case 1
    {
        vector<int> nums = {2,2,1};
        cout << "Test 1: nums = [2,2,1]" << endl;
        cout << "Output: " << solution.singleNumber(nums) << " (Expected: 1)" << endl;
        cout << "Explanation: 1 appears once, 2 appears twice" << endl;
        cout << endl;
    }
    
    // Test Case 2
    {
        vector<int> nums = {4,1,2,1,2};
        cout << "Test 2: nums = [4,1,2,1,2]" << endl;
        cout << "Output: " << solution.singleNumber(nums) << " (Expected: 4)" << endl;
        cout << "Explanation: 4 appears once, others twice" << endl;
        cout << endl;
    }
    
    // Test Case 3 (Edge Case - Single Element)
    {
        vector<int> nums = {1};
        cout << "Test 3: nums = [1]" << endl;
        cout << "Output: " << solution.singleNumber(nums) << " (Expected: 1)" << endl;
        cout << "Explanation: Only one element in array" << endl;
        cout << endl;
    }
    
    // Test Case 4 (Large Number)
    {
        vector<int> nums = {1000,1000,999};
        cout << "Test 4: nums = [1000,1000,999]" << endl;
        cout << "Output: " << solution.singleNumber(nums) << " (Expected: 999)" << endl;
        cout << "Explanation: Works with larger numbers" << endl;
        cout << endl;
    }
    
    // Test Case 5 (Negative Numbers)
    {
        vector<int> nums = {-1,-1,0};
        cout << "Test 5: nums = [-1,-1,0]" << endl;
        cout << "Output: " << solution.singleNumber(nums) << " (Expected: 0)" << endl;
        cout << "Explanation: Handles negative numbers correctly" << endl;
        cout << endl;
    }
    
    return 0;
}

/*
 * Dry Run:
 * Input: nums = [4,1,2,1,2]
 * 
 * Binary Representations:
 * 4 = 100
 * 1 = 001
 * 2 = 010
 * 1 = 001
 * 2 = 010
 * 
 * Process each bit:
 * 
 * Bit 0 (rightmost):
 * Check: 4&1=0, 1&1=1, 2&1=0, 1&1=1, 2&1=0
 * Count = 2 (even)
 * count % 2 = 0 → Don't set bit 0 in result
 * 
 * Bit 1:
 * Check: 4&2=0, 1&2=0, 2&2=2, 1&2=0, 2&2=2
 * Count = 2 (even)
 * count % 2 = 0 → Don't set bit 1 in result
 * 
 * Bit 2:
 * Check: 4&4=4, 1&4=0, 2&4=0, 1&4=0, 2&4=0
 * Count = 1 (odd)
 * count % 2 = 1 → Set bit 2 in result
 * result |= (1 << 2) → result = 100 (binary) = 4
 * 
 * Bits 3-31:
 * All counts = 0 (even) → All remain 0
 * 
 * Final result = 100 (binary) = 4 ✓
 * 
 * -------------------------------------------------------------------
 * 
 * Why Manual Implementation vs XOR Operator:
 * 
 * XOR Operator Approach (1 line):
 * ```cpp
 * int result = 0;
 * for(int num : nums) result ^= num;
 * return result;
 * ```
 * 
 * Manual Approach (This solution):
 * - Shows HOW XOR actually works internally
 * - Better understanding of bit manipulation
 * - Same time complexity: O(n)
 * - Same space complexity: O(1)
 * - More educational, less "shortcut"
 * 
 * -------------------------------------------------------------------
 * 
 * Bit Operations Explained:
 * 
 * 1. Left Shift (1 << bit):
 *    Creates a number with only one bit set
 *    1 << 0 = 0001 (decimal 1)
 *    1 << 1 = 0010 (decimal 2)
 *    1 << 2 = 0100 (decimal 4)
 *    1 << 3 = 1000 (decimal 8)
 * 
 * 2. Bitwise AND (num & mask):
 *    Checks if a bit is set
 *    5 & 1 = 101 & 001 = 001 (non-zero, bit 0 is set)
 *    5 & 2 = 101 & 010 = 000 (zero, bit 1 is not set)
 * 
 * 3. Bitwise OR (result |= mask):
 *    Sets a bit to 1
 *    000 |= 100 = 100 (sets bit 2)
 *    100 |= 010 = 110 (sets bit 1)
 * 
 * -------------------------------------------------------------------
 * 
 * Key Points:
 * 
 * 1. Why count % 2?
 *    - Pairs contribute even count
 *    - Single element makes it odd
 *    - Odd % 2 = 1, Even % 2 = 0
 * 
 * 2. Why 32 bits?
 *    - Standard integer size in C++
 *    - Covers all possible bit positions
 *    - Works for negative numbers too (two's complement)
 * 
 * 3. Negative numbers?
 *    - Two's complement representation
 *    - Same bit manipulation works
 *    - Sign bit (bit 31) handled automatically
 * 
 * 4. Time complexity:
 *    - Outer loop: 32 iterations (constant)
 *    - Inner loop: n iterations
 *    - Total: 32 × n = O(n)
 * 
 * 5. Space complexity:
 *    - Only using: result, count, bit
 *    - O(1) constant space
 * 
 * 6. Interview perspective:
 *    - Shows deep understanding of bit manipulation
 *    - Not just using built-in operators
 *    - Can explain how XOR works internally
 *    - Demonstrates problem-solving from first principles
 * 
 * 7. Alternative approach (XOR):
 *    - More concise: result ^= num
 *    - Same complexity
 *    - Less educational
 *    - Industry standard would use XOR
 * 
 * 8. When to use manual vs XOR:
 *    - Learning: Manual (this approach)
 *    - Production: XOR (built-in)
 *    - Interview: Know both, use XOR but explain manual
 */
