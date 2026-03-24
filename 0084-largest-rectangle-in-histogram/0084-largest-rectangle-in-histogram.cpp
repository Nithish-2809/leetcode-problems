vector<int> calculatePse(vector<int> nums) {
    int n = nums.size();
    vector<int> pse(n);
    stack<int> st; 

    for(int i = 0; i < n; i++) {
        while(!st.empty() && nums[st.top()] >= nums[i]) {
            st.pop();
        }
        if(st.empty()) pse[i] = -1;
        else pse[i] = st.top();

        st.push(i);
    }

    return pse;
}


vector<int> calculateNse(vector<int>nums) {
    int n = nums.size();
    stack<int>st;
    vector<int>nge(n);

    for(int i=n-1;i>=0;i--) {
        while(!st.empty() && nums[st.top()]>= nums[i]) {
            st.pop();
        }

        if(st.empty()) nge[i] = n;
        else nge[i] = st.top();

        st.push(i);
    }

    return nge;
}


class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        int n = nums.size();
        vector<int>pse(n);
        vector<int>nse(n);

        pse = calculatePse(nums);
        nse = calculateNse(nums);

        int maxArea = INT_MIN;

        for(int i=0;i<n;i++) {
            maxArea = max(maxArea,nums[i]*(nse[i]-pse[i]-1));
        }

        return maxArea;
    }
};