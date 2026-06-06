class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int current = 0, maxAltitude = 0;

        for (int x : gain) {
            current += x;
            maxAltitude = max(maxAltitude, current);
        }

        return maxAltitude;
    }
};
