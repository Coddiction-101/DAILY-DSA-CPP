#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0;

        while (j < typed.size()) {

            if (i < name.size() && name[i] == typed[j]) {
                i++; 
                j++;
            }

     
            else if (j > 0 && typed[j] == typed[j - 1]) {
                j++;
            }

            else {
                return false;
            }
        }

        return i == name.size();
    }
};

int main() {
    Solution obj;

    // Sample test cases
    cout << obj.isLongPressedName("alex", "aaleex") << endl;  
    cout << obj.isLongPressedName("saeed", "ssaaedd") << endl; 
    cout << obj.isLongPressedName("leelee", "lleeelee") << endl; 

    return 0;
}
