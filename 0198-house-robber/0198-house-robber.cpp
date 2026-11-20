int maxAmountRobbed(const vector<int>&nums,int index,vector<int>&dp) {
    int n = nums.size();
    if(index>=n) return 0;

    if(dp[index]!=-1) return dp[index];

    //pick this amount
    int pick = nums[index] + maxAmountRobbed(nums,index+2,dp);

    //dont pick this amount
    int notPick = maxAmountRobbed(nums,index+1,dp);

    return dp[index] = max(pick,notPick);
}




class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();

        vector<int>dp(n,-1);
        
        return max(maxAmountRobbed(nums,0,dp),maxAmountRobbed(nums,1,dp));
    }
};