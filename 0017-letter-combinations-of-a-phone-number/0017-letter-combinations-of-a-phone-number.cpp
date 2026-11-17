void solve(int index,const string &digits,unordered_map<char,string>&mp,vector<string>&ans,string res) {
    int n = digits.length();
    
    if(index==n) {
        ans.push_back(res);
        return;
    }

    char num = digits[index];

    for(int i=0;i<mp[num].length();i++) {
        solve(index+1,digits,mp,ans,res+mp[num][i]);
    }

}





class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string>mp;

        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        vector<string>ans;

        solve(0,digits,mp,ans,"");

    return ans;
    }
};