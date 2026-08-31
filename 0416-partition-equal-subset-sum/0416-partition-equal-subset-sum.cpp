bool isSubsetSumEqualsK(int index,const vector<int>&nums,int k,vector<vector<int>>&dp) {
    int n = nums.size();
    if(index>=n) return false;
    if(k==0) return true;
    if(dp[index][k]!=-1) return dp[index][k];
    bool pick = false;
    if(k>=nums[index]) {
        pick = isSubsetSumEqualsK(index+1,nums,k-nums[index],dp);
    }

    bool notPick = isSubsetSumEqualsK(index+1,nums,k,dp);

    return dp[index][k] = pick || notPick;
}


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
    
        for(int i=0;i<n;i++) {
            sum += nums[i];
        }

        if(sum%2!=0) return false;

        vector<vector<int>> dp(n, vector<int>(sum/2 + 1, -1));

        return isSubsetSumEqualsK(0,nums,sum/2,dp);
    }
};