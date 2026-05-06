void generateStrings(int open,int close,int n,string &str,vector<string>&ans) {

    if(str.length()==2*n) {
        ans.push_back(str);
        return;
    }

    if(open<n) {
        str.push_back('(');
        generateStrings(open+1,close,n,str,ans);
        str.pop_back();
    }

    if(close<open) {
        str.push_back(')');
        generateStrings(open,close+1,n,str,ans);
        str.pop_back();
    }
}


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;

        string str = "";

        generateStrings(0,0,n,str,ans);

        return ans;
    }
};