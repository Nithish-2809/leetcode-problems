void getAllParenthesis(int open,int close,int n,string res,vector<string>&ans) {
    if(res.length()==2*n) {
        ans.push_back(res);
        return;
    }

    if(open<n) {
        getAllParenthesis(open+1,close,n,res+'(',ans);
    }

    if(close<open) {
        getAllParenthesis(open,close+1,n,res+')',ans);
    }

}



class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;

        getAllParenthesis(0,0,n,"",ans);


    return ans;
    }
};