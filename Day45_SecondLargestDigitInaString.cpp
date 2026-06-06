class Solution {
public:
    int secondHighest(string s) {
        int largest = -1;
        int secondLargest = -1;
        
        for(char c : s) {
            if(isdigit(c)) {
                int digit = c - '0';
                
                if(digit > largest) {
                    secondLargest = largest;
                    largest = digit;
                }
                else if(digit > secondLargest && digit < largest) {
                    secondLargest = digit;
                }
            }
        }
        
        return secondLargest;
    }
};
