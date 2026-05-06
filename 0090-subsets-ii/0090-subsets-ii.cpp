void generateSubsequences(vector<int>nums,int n,vector<vector<int>>&ans,vector<int>ds,int index) {

    ans.push_back(ds);

    for(int i=index;i<n;i++) {
        if(i>index && nums[i]==nums[i-1]) continue;
        ds.push_back(nums[i]);
        generateSubsequences(nums,n,ans,ds,i+1);
        ds.pop_back();
    }
}



class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        int n = nums.size();
        vector<int>ds;
        sort(nums.begin(),nums.end());
        generateSubsequences(nums,n,ans,ds,0);


        return ans;
    }
};