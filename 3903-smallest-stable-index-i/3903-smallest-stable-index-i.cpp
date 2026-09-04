class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>maxArray(n,0);
        vector<int>minArray(n,0);

        maxArray[0] = nums[0];
        minArray[n-1] = nums[n-1];

        for(int i=1;i<n;i++) {
            maxArray[i] = max(maxArray[i-1],nums[i]);
        }

        for(int i=n-2;i>=0;i--) {
            minArray[i] = min(minArray[i+1],nums[i]);
        }

        for(int i=0;i<n;i++) {
            int score = maxArray[i]-minArray[i];

            if(score<=k) return i;
        }

    return -1;
    }
};