class Solution {
public:

    vector<int> calculatePse(vector<int>& nums) {
        int n = nums.size();
        vector<int> pse(n);
        stack<int> st; 

        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }

    vector<int> calculateNse(vector<int>& nums) {
        int n = nums.size();
        vector<int> nse(n);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }

    int largestRectangleArea(vector<int>& nums) {
        int n = nums.size();
        vector<int> pse = calculatePse(nums);
        vector<int> nse = calculateNse(nums);

        int maxArea = 0;

        for(int i = 0; i < n; i++) {
            int width = nse[i] - pse[i] - 1;
            int area = nums[i] * width;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> height(m, 0);
        int maxi = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == '1')
                    height[j] += 1;
                else
                    height[j] = 0;
            }

            maxi = max(maxi, largestRectangleArea(height));
        }

        return maxi;
    }
};