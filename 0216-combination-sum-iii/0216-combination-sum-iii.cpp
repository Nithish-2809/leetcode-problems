void generateSubsequences(int k,int n,int sum,vector<vector<int>>&ans,vector<int>&ds,int index) {
    if(index<=10 && ds.size()==k) {
        if(sum==n) {
            ans.push_back(ds);
        }
        return;
    } 
    if(index>10) return;

    sum += index;
    ds.push_back(index);
    generateSubsequences(k,n,sum,ans,ds,index+1);
    sum -= index;
    ds.pop_back();
    generateSubsequences(k,n,sum,ans,ds,index+1);
}





class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>ds;
        int sum = 0;
        generateSubsequences(k,n,sum,ans,ds,1);

        return ans;
    }
};