vector<int> generateNge(vector<int>nums) {
    int n = nums.size();
    vector<int>ans(n,0);
    stack<int>st;

    for(int i=n-1;i>=0;i--) {
        while(!st.empty() && nums[st.top()]<=nums[i]) {
            st.pop();
        }

        if(st.empty()) ans[i] = n;
        else ans[i] = st.top();

        st.push(i);
    }

    return ans;

}





class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        int n = nums.size();
        vector<int>nge(n,0);
        vector<int>ans(n,0);


        nge = generateNge(nums);

        for(int i=0;i<n;i++) {
            ans[i] = nge[i]==n?0 : nge[i]-i;
        }

        return ans;
    }
};