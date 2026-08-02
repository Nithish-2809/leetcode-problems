class Solution {
public:
    void solve(int n, vector<string>& ans, string &s, int last) {
        if(s.size() == n) {
            ans.push_back(s);
            return;
        }

        if(last == -1 || last == 1) {

            s.push_back('1');
            solve(n, ans, s, 1);
            s.pop_back();

    
            s.push_back('0');
            solve(n, ans, s, 0);
            s.pop_back();
        }
        else { 
            s.push_back('1');
            solve(n, ans, s, 1);
            s.pop_back();
        }
    }

    vector<string> validStrings(int n) {
        vector<string> ans;
        string s = "";
        solve(n, ans, s, -1);
        return ans;
    }
};