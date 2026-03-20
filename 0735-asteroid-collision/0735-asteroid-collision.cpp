class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        vector<int> st;

        for (int i = 0; i < nums.size(); i++) {
            bool destroyed = false;

            while (!st.empty() && st.back() > 0 && nums[i] < 0) {
                if (st.back() < abs(nums[i])) {
                    st.pop_back(); 
                }
                else if (st.back() == abs(nums[i])) {
                    st.pop_back(); 
                    destroyed = true;
                    break;
                }
                else {
                    destroyed = true; 
                    break;
                }
            }

            if (!destroyed) {
                st.push_back(nums[i]);
            }
        }

        return st;
    }
};