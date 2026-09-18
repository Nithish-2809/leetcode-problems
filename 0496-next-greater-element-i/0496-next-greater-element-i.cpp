class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        stack<int> st;

        int n = nums2.size();

        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }

            mp[nums2[i]] = st.empty() ? -1 : st.top();

            st.push(nums2[i]);
        }

        vector<int> res;

        for(int num : nums1) {
            res.push_back(mp[num]);
        }

        return res;
    }
};