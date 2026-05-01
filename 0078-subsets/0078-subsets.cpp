void printSubsequences(int ind,vector<int>res,vector<vector<int>>&ans,vector<int>&nums) {
    int n = nums.size();

    if(ind>=n) {
        ans.push_back(res);
        return;
    }

    res.push_back(nums[ind]);
    printSubsequences(ind+1,res,ans,nums);

    res.pop_back();
    printSubsequences(ind+1,res,ans,nums);
}




class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        vector<int>res;

        printSubsequences(0,res,ans,nums);


        return ans;
    }
};