class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        unordered_map<int,vector<int>>mp;
        int n = nums.size();
        for(int i=0;i<n;i++) {
            if(nums[i]==x) {
                mp[nums[i]].push_back(i);
            }
        }

        vector<int>ans;

        for(int i=0;i<queries.size();i++) {
            if(mp[x].size()<queries[i]) {
                ans.push_back(-1);
            }
            else {
                ans.push_back(mp[x][queries[i]-1]);
            }
        }

    return ans;
    }
};