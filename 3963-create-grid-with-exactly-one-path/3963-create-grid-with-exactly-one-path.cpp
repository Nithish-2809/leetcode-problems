class Solution {
public:
    vector<string> createGrid(int n, int m) {
        vector<string> ans;

        for (int i = 0; i < n; i++) {
            string s = "";

            if (i == 0) {
                for (int j = 0; j < m; j++) {
                    s += '.';
                }
            }
            else {
                for (int j = 0; j < m - 1; j++) {
                    s += '#';
                }
                s += '.';
            }

            ans.push_back(s);
        }

        return ans;
    }
};