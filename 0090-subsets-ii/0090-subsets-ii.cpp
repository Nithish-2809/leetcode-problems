void solve(const vector<int>&nums,int index,vector<int>&res,set<vector<int>>&ans) {
    int n = nums.size();

    if(index==n) {
        ans.insert(res);
        return;
    }

    res.push_back(nums[index]);
    solve(nums,index+1,res,ans);
    res.pop_back();
    solve(nums,index+1,res,ans);
}





class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>ans;
        vector<int>res;
        sort(nums.begin(), nums.end());

        solve(nums,0,res,ans);

        vector<vector<int>>sol;

        for(auto it : ans) {
            sol.push_back(it);
        }

    return sol;
    }
};