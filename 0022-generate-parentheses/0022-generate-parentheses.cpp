void generateBrackets(int n,vector<string>&ans,int open,int close,string s) {
    if(s.length()==2*n) {
        ans.push_back(s);
        return;
    }

    if(open<n) {
        generateBrackets(n,ans,open+1,close,s+'(');
    }

    if(close<open) {
        generateBrackets(n,ans,open,close+1,s+')');
    }
}

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;

        generateBrackets(n,ans,0,0,"");

        return ans;
    }
};