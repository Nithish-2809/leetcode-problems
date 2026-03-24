class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        int n = nums.size();
        vector<int>st;

        for(int i=0;i<n;i++) {
            if(nums[i]>0) st.push_back(nums[i]);
            else {
                while(!st.empty() && st.back()>0 && abs(nums[i])>st.back()) {
                    st.pop_back();
                }
                if(!st.empty() && st.back()==abs(nums[i])) {
                    st.pop_back();
                }
                else if(st.empty() || st.back()<0) {
                    st.push_back(nums[i]);
                }
            }
        }

        return st;
    }
};