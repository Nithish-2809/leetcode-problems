vector<int> calculatePreviousSmallerElements(vector<int>& nums) {
    int n = nums.size();
    stack<int> st;
    vector<int> ans(n);

    for(int i=0;i<n;i++) {
        while(!st.empty() && nums[st.top()] >= nums[i])
            st.pop();

        ans[i] = st.empty() ? -1 : st.top();

        st.push(i);
    }

    return ans;
}

vector<int> calculateNextSmallerElements(vector<int>& nums) {
    int n = nums.size();
    stack<int> st;
    vector<int> ans(n);

    for(int i=n-1;i>=0;i--) {
        while(!st.empty() && nums[st.top()] >= nums[i])
            st.pop();

        ans[i] = st.empty() ? n : st.top();

        st.push(i);
    }

    return ans;
}



class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>pse;
        vector<int>nse;

        pse = calculatePreviousSmallerElements(heights);
        nse = calculateNextSmallerElements(heights);

        int maxArea = 0;

        for(int i=0;i<n;i++) {
            int width = nse[i]-pse[i]-1;
            int area = heights[i]*width;
            maxArea = max(maxArea,area);
        }

    return maxArea;
    }
};