class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> mp;

        for(auto it : knowledge) {
            mp[it[0]] = it[1];
        }

        int n = s.length();
        string word = "";
        string res = "";

        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                int j = i + 1;

                while(s[j] != ')') {
                    word += s[j];
                    j++;
                }

                if(mp.find(word) != mp.end())
                    res += mp[word];
                else
                    res += '?';

                word = "";
                i = j;   // move to closing ')'
            }
            else {
                res += s[i];
            }
        }

        return res;
    }
};