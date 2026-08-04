class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();

        int maxi = INT_MIN;
        int mini = INT_MAX;

        for(int num : nums) {
            maxi = max(maxi, num);
            mini = min(mini, num);
        }

        vector<int> hashh(maxi - mini + 1, 0);

        
        for(int num : nums) {
            hashh[num - mini]++;
        }

        vector<int> ans;

    
        for(int i = 0; i < hashh.size(); i++) {
            if(hashh[i] == 0) {
                ans.push_back(mini + i);
            }
        }

        return ans;
    }
};