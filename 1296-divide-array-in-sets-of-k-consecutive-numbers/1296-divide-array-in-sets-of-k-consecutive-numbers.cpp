class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        
        int n = nums.size();

        sort(nums.begin(),nums.end());

        unordered_map<int,int>mp;

        for(int i=0;i<n;i++) {
            mp[nums[i]]++;
        }

        for(int i=0;i<n;i++) {

            if(mp[nums[i]]==0) continue;

            mp[nums[i]]--;

            int curr = nums[i];

            for(int j=1;j<k;j++) {
                if(mp.find(curr+1)==mp.end()) return false;
                mp[curr+1]--;
                curr++;
            }
        }


    return true;
    }
};