int countDecodings(string s,int index,vector<int>&dp) {
    int n = s.length();
    if(index==n) return 1;
    if(s[index]=='0') return 0;

    if(dp[index]!=-1) return dp[index];

    int take1 = countDecodings(s,index+1,dp);
    int take2 = 0;
    if(index+1<n) {
        if(s[index]=='1' || (s[index]=='2' && s[index+1]<='6')) {
            take2 = countDecodings(s,index+2,dp);
        }
    }

    return dp[index] = take1+take2;
}




class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int>dp(n,-1);
        return countDecodings(s,0,dp);
    }
};