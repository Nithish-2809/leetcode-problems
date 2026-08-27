class Solution {
public:
    string ans = "";
    bool found = false;

    void solve(vector<int>& freq, string& curr,
               string& target, bool greater, int n) {

        if (found) return;

        if (curr.size() == n) {
            if (greater) {
                ans = curr;
                found = true;
            }
            return;
        }

        int pos = curr.size();

        for (int ch = 0; ch < 26; ch++) {

            if (freq[ch] == 0) continue;

            if (!greater && ch < target[pos] - 'a')
                continue;

            freq[ch]--;
            curr.push_back(char('a' + ch));

            solve(
                freq,
                curr,
                target,
                greater || (ch > target[pos] - 'a'),
                n
            );

            curr.pop_back();
            freq[ch]++;

            if (found) return;
        }
    }

    string lexGreaterPermutation(string s, string target) {

        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        string curr = "";

        solve(freq, curr, target, false, s.size());

        return ans;
    }
};