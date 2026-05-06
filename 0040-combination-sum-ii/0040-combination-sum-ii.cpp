void generateSubsequences(vector<int>nums,int target,int index,vector<int>&ds,vector<vector<int>>&ans,int n) {
    if(target==0) {
        ans.push_back(ds);
        return;
    }

    for(int i=index;i<n;i++) {
        if(i>index && nums[i]==nums[i-1]) continue;

        if(nums[i]>target) break;

        ds.push_back(nums[i]);
        generateSubsequences(nums,target-nums[i],i+1,ds,ans,n);
        ds.pop_back();
    }
}

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        int n = candidates.size();
        vector<int>ds;

        sort(candidates.begin(),candidates.end());

        generateSubsequences(candidates,target,0,ds,ans,n);

        return ans;
    }
};