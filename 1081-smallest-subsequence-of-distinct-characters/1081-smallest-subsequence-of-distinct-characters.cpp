class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> lastIndex(26);

        for(int i = 0; i < s.size(); i++) {
            lastIndex[s[i] - 'a'] = i;
        }

        vector<bool> taken(26, false);
        string res;

        for(int i = 0; i < s.size(); i++) {
            char ch = s[i];

            if(taken[ch - 'a']) continue;

            while(!res.empty() &&
                  res.back() > ch &&
                  lastIndex[res.back() - 'a'] > i) {

                taken[res.back() - 'a'] = false;
                res.pop_back();
            }

            res.push_back(ch);
            taken[ch - 'a'] = true;
        }

        return res;
    }
};