class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxGain = 0;
        int currentGain = 0;

        int n = gain.size();
        for(int i=0;i<n;i++) {
            currentGain = currentGain + gain[i];
            maxGain = max(maxGain,currentGain);
        }

        return maxGain;
    }
};