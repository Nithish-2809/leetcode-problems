int maximumAliceScore(vector<int>&nums,int aliceTurn,int index,vector<vector<int>>&dp) {
    int n = nums.size();
    if(index>=n) return 0;

    if(dp[index][aliceTurn]!=-1) return dp[index][aliceTurn];
    
    if(aliceTurn) {
        int pick1 = nums[index]+maximumAliceScore(nums,0,index+1,dp);
        int pick2 = INT_MIN;
        if(index+1<n) {
            pick2 = nums[index]+nums[index+1]+maximumAliceScore(nums,0,index+2,dp);
        }
        int pick3 = INT_MIN;
        if(index+2<n) {
            pick3 = nums[index]+nums[index+1]+nums[index+2]+maximumAliceScore(nums,0,index+3,dp);
        }

        return dp[index][aliceTurn] = max(pick1,max(pick2,pick3));
    }
    else {
        int pick1 = maximumAliceScore(nums,1,index+1,dp);
        int pick2 = INT_MAX;
        if(index+1<n) {
            pick2 = maximumAliceScore(nums,1,index+2,dp);
        }
        int pick3 = INT_MAX;
        if(index+2<n) {
            pick3 = maximumAliceScore(nums,1,index+3,dp);
        }

        return dp[index][aliceTurn] = min(pick1,min(pick2,pick3));
    }

    return -1;

}


class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        int totalScore = 0;
        vector<vector<int>>dp(n,vector<int>(2,-1));
        

        for(int i=0;i<n;i++) {
            totalScore += stoneValue[i];
        }

        int aliceScore = maximumAliceScore(stoneValue,1,0,dp);
        int bobScore = totalScore-aliceScore;

        if(aliceScore>bobScore) return "Alice";
        else if(bobScore>aliceScore) return "Bob";
        return "Tie";
    }
};