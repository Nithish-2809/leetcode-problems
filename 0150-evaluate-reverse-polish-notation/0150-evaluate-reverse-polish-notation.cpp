class Solution {
public:
    int evalRPN(vector<string>& nums) {
        stack<int> st;

        for(int i = 0; i < nums.size(); i++) {

            if(nums[i] == "+") {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                st.push(b + a);
            }
            else if(nums[i] == "-") {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                st.push(b - a);
            }
            else if(nums[i] == "*") {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                st.push(b * a);
            }
            else if(nums[i] == "/") {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                st.push(b / a);
            }
            else {
                st.push(stoi(nums[i]));
            }
        }

        return st.top();
    }
};