
void generateSubsequences(vector<int>& candidates, int index, int target,
                          vector<int>& ds, vector<vector<int>>& ans) {
    int n = candidates.size();

    if (target == 0) {
        ans.push_back(ds);
        return;
    }

    for (int i = index; i < n; i++) {
        
        if (i > index && candidates[i] == candidates[i - 1]) {
            continue;
        }

        // Since the array is sorted
        if (candidates[i] > target) {
            break;
        }

        ds.push_back(candidates[i]);

        generateSubsequences(candidates, i + 1,
                             target - candidates[i], ds, ans);

        ds.pop_back();
    }
}

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;

        sort(candidates.begin(), candidates.end());

        generateSubsequences(candidates, 0, target, ds, ans);

        return ans;
    }
};
