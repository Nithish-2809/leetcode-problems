class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.length();

        vector<bool> taken(26, false);
        vector<int> lastIndex(26, -1);

        for (int i = 0; i < n; i++) {
            lastIndex[s[i] - 'a'] = i;
        }

        string ans = "";

        for (int i = 0; i < n; i++) {

            if (taken[s[i] - 'a']) continue;

            while (!ans.empty() &&
                   ans.back() > s[i] &&
                   lastIndex[ans.back() - 'a'] > i) {

                taken[ans.back() - 'a'] = false;
                ans.pop_back();
            }

            ans.push_back(s[i]);
            taken[s[i] - 'a'] = true;
        }

        return ans;
    }
};