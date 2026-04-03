#include <iostream>
#include <unordered_map>
using namespace std;

/*
    Check if two strings are isomorphic.

    Idea:
    - Maintain mapping in both directions:
        s -> t
        t -> s
    - If mapping breaks at any point → return false
*/

bool isIsomorphic(string s, string t) {
    if(s.length() != t.length()) return false;

    unordered_map<char, char> mapST; // s -> t
    unordered_map<char, char> mapTS; // t -> s

    for(int i = 0; i < s.length(); i++) {
        char c1 = s[i];
        char c2 = t[i];

        // Check s -> t
        if(mapST.count(c1)) {
            if(mapST[c1] != c2) return false;
        } else {
            mapST[c1] = c2;
        }

        // Check t -> s
        if(mapTS.count(c2)) {
            if(mapTS[c2] != c1) return false;
        } else {
            mapTS[c2] = c1;
        }
    }

    return true;
}

int main() {
    string s = "egg";
    string t = "add";

    if(isIsomorphic(s, t)) {
        cout << "Isomorphic" << endl;
    } else {
        cout << "Not Isomorphic" << endl;
    }

    return 0;
}
