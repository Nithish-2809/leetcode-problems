class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n =  nums.size();
        if(n%k!=0) return false;
        map<int,int>mp;
        for(auto it : nums) {
            mp[it]++;
        }

        while(mp.size()!=0) {
            int first = mp.begin()->first;

            for(int i=0;i<k;i++) {
                int curr = first+i;

                if(mp.find(curr)==mp.end()) return false;

                mp[curr]--;

                if(mp[curr]==0) mp.erase(curr);
            }

        }

        return true;
    }
};