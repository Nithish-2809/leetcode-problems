int lengthOfLongestCommonSubsequence(const string &word1,const string &word2,int i,int j,vector<vector<int>>&dp) {
    int n1 = word1.length();
    int n2 = word2.length();

    if(i>=n1 || j>=n2) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    if(word1[i]==word2[j]) {
        return dp[i][j] = 1 + lengthOfLongestCommonSubsequence(word1,word2,i+1,j+1,dp);
    }

    return dp[i][j] = max(lengthOfLongestCommonSubsequence(word1,word2,i+1,j,dp),
    lengthOfLongestCommonSubsequence(word1,word2,i,j+1,dp));
}



class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.length();
        int n2 = word2.length();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));

        int lcs = lengthOfLongestCommonSubsequence(word1,word2,0,0,dp);

        return (n1+n2)-2*lcs; 
    }
};