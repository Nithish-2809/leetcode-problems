void getCombinations(vector<int>&nums,int target,vector<vector<int>>&ans,vector<int>&ds,int index,int n) {
    if(index==n) {
        if(target==0) {
            ans.push_back(ds);
        }
        return;
    }

    if(nums[index]<=target) {
        ds.push_back(nums[index]);
        getCombinations(nums,target-nums[index],ans,ds,index,n);
        ds.pop_back();
    }
    getCombinations(nums,target,ans,ds,index+1,n);
}



class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;

        int n = candidates.size();

        getCombinations(candidates,target,ans,ds,0,n);
        return ans;
    }
};