int countMinimumOperations(int i,int j,string s,string t,vector<vector<int>>&dp) {
    if(i<0) return j+1;
    if(j<0) return i+1;

    if(dp[i][j]!=-1) return dp[i][j];

    if(s[i]==t[j]) return dp[i][j] = countMinimumOperations(i-1,j-1,s,t,dp);
    
    return dp[i][j] = 1 +  min(countMinimumOperations(i,j-1,s,t,dp),
                                min(countMinimumOperations(i-1,j-1,s,t,dp),
                                    countMinimumOperations(i-1,j,s,t,dp)));
}



class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));

        return countMinimumOperations(n-1,m-1,word1,word2,dp);
    }
};