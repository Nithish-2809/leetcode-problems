bool isValidString(const string &s,int index,int open,int close,vector<vector<vector<int>>>&dp) {
    int n = s.length();

    if(close>open) return false;

    if(index==n) {
        return (open==close);
    }

    if(dp[open][close][index]!=-1) return dp[open][close][index];

    if(s[index]=='(') {
        return dp[open][close][index] = isValidString(s,index+1,open+1,close,dp);
    }
    else if(s[index]==')') {
        return dp[open][close][index] = isValidString(s,index+1,open,close+1,dp);
    }

    return dp[open][close][index] = isValidString(s,index+1,open+1,close,dp) ||
            isValidString(s,index+1,open,close+1,dp) ||
                isValidString(s,index+1,open,close,dp);
}


class Solution {
public:
    bool checkValidString(string s) {

        int n = s.length();

        vector<vector<vector<int>>>dp(n,
            vector<vector<int>>(n,vector<int>(n,-1)));
        
        return isValidString(s,0,0,0,dp);
    }
};