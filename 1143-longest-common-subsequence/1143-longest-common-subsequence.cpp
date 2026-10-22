int calculateLongestSubsequenceLength(const string &text1,const string &text2,int i,int j,vector<vector<int>>&dp) {

    int n1 = text1.length();
    int n2 = text2.length();

    if(i>=n1 || j>=n2) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    if(text1[i]==text2[j]) {
        return dp[i][j] = 1+calculateLongestSubsequenceLength(text1,text2,i+1,j+1,dp);
    }

    return dp[i][j] = max(calculateLongestSubsequenceLength(text1,text2,i+1,j,dp),
                calculateLongestSubsequenceLength(text1,text2,i,j+1,dp));
}


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

        int n1 = text1.length();
        int n2 = text2.length();

        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        
        return calculateLongestSubsequenceLength(text1,text2,0,0,dp);
    }
};