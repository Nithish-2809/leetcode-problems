class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int> altitude(n + 1, 0);
        int maxi = 0;
        
        for (int i = 0; i < n; i++) {
            altitude[i + 1] = altitude[i] + gain[i];
            maxi = max(altitude[i + 1], maxi);
        }
        
        return maxi;
    }
};
