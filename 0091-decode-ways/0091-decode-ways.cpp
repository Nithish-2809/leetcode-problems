int solve(string s,int n,int index,vector<int>&dp) {
    if(index==n) return 1;

    if(s[index]=='0') return 0;

    if(dp[index]!=-1) return dp[index];

    int result = solve(s,n,index+1,dp);

    if(index+1<n) {
        if((s[index]=='1') || (s[index]=='2' && s[index+1]<='6')) {
            result += solve(s,n,index+2,dp);
        }
    }

    return dp[index] = result;
}

class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int>dp(n,-1);

        return solve(s,n,0,dp);
    }
};