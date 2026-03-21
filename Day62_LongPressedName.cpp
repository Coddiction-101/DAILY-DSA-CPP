#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    // Check if 'typed' is a long pressed version of 'name'
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0;

        // Traverse typed string
        while (j < typed.size()) {

            // Case 1: characters match → move both
            if (i < name.size() && name[i] == typed[j]) {
                i++; 
                j++;
            }

            // Case 2: long press → repeat previous char
            else if (j > 0 && typed[j] == typed[j - 1]) {
                j++;
            }

            // Case 3: invalid sequence
            else {
                return false;
            }
        }

        // All characters of 'name' must be matched
        return i == name.size();
    }
};

int main() {
    Solution obj;

    // Sample test cases
    cout << obj.isLongPressedName("alex", "aaleex") << endl;   // true
    cout << obj.isLongPressedName("saeed", "ssaaedd") << endl; // false
    cout << obj.isLongPressedName("leelee", "lleeelee") << endl; // true

    return 0;
}
