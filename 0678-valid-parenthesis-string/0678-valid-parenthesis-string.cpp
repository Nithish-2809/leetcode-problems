bool isValidString(string s,int index,int left,int right,vector<vector<vector<int>>>&dp) {
    int n = s.length();

    if(right > left) return false;

    if(index == n) {
        return left == right;
    }

    if(dp[left][right][index]!=-1) return dp[left][right][index];

    if(s[index] == '(') {
        return dp[left][right][index] = isValidString(s,index+1,left+1,right,dp);
    }
    else if(s[index] == ')') {
        return dp[left][right][index] = isValidString(s,index+1,left,right+1,dp);
    }

    return dp[left][right][index] = isValidString(s,index+1,left+1,right,dp) ||
           isValidString(s,index+1,left,right+1,dp) ||
           isValidString(s,index+1,left,right,dp);
}





class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();
        vector<vector<vector<int>>> dp(
    n + 1,
    vector<vector<int>>(n + 1, vector<int>(n + 1, -1))
);

        return isValidString(s,0,0,0,dp);
    }
};