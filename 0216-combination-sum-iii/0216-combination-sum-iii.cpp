void solve(int k, int n, int currSum, int start,
           vector<vector<int>>& ans, vector<int>& curr) {

    if (curr.size() == k) {
        if (currSum == n)
            ans.push_back(curr);
        return;
    }

    for (int i = start; i <= 9; i++) {


        curr.push_back(i);

        solve(k, n, currSum + i, i + 1, ans, curr);

        curr.pop_back();
    }
}

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> curr;

        solve(k, n, 0, 1, ans, curr);

        return ans;
    }
};