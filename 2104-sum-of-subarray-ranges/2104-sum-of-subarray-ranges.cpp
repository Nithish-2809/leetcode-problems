vector<int> calculatePse(vector<int>nums) {
    int n = nums.size();
    vector<int>pse(n);
    stack<int>st;

    for(int i=0;i<n;i++) {

        while(!st.empty() && nums[st.top()]>=nums[i]) {
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
    vector<int>nse(n);
    stack<int>st;

    for(int i=n-1;i>=0;i--) {

        while(!st.empty() && nums[st.top()]>nums[i]) {
            st.pop();
        }

        if(st.empty()) nse[i] = n;
        else nse[i] = st.top();
        st.push(i);
    }

    return nse;
}


vector<int> calculatePge(vector<int>nums) {
    int n = nums.size();
    vector<int>pge(n);
    stack<int>st;

    for(int i=0;i<n;i++) {

        while(!st.empty() && nums[st.top()]<=nums[i]) {
            st.pop();
        }

        if(st.empty()) pge[i] = -1;
        else pge[i] = st.top();
        st.push(i);
    }

    return pge;
}



vector<int> calculateNge(vector<int>nums) {
    int n = nums.size();
    vector<int>nge(n);
    stack<int>st;

    for(int i=n-1;i>=0;i--) {

        while(!st.empty() && nums[st.top()]<nums[i]) {
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
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int>pse(n);
        vector<int>nse(n);
        vector<int>pge(n);
        vector<int>nge(n);

        pse = calculatePse(nums);
        nse = calculateNse(nums);
        pge = calculatePge(nums);
        nge = calculateNge(nums);
        long long rangeSum = 0;
        long long maxSum = 0;
        long long minSum = 0;

        for(int i=0;i<n;i++) {
            long long mini = 1LL*nums[i]*(i-pse[i])*(nse[i]-i);
            long long maxi = 1LL*nums[i]*(i-pge[i])*(nge[i]-i);

            maxSum += maxi;
            minSum += mini;
        }

        rangeSum = maxSum-minSum;

        return rangeSum;
    }
};