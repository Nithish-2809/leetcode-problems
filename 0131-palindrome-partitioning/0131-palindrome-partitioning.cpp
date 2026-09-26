class Solution {
public:
    bool isPalindrome(const string& s, int l, int r) {
        while(l < r) {
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    void solve(const string& s, int index,
               vector<string>& res,
               vector<vector<string>>& ans) {

        int n = s.length();

        if(index == n) {
            ans.push_back(res);
            return;
        }

        for(int i = index; i < n; i++) {
            if(isPalindrome(s, index, i)) {
                res.push_back(s.substr(index, i - index + 1));
                solve(s, i + 1, res, ans);
                res.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> res;

        solve(s, 0, res, ans);

        return ans;
    }
};