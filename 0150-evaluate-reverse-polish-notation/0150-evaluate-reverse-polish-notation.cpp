class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int>st;
        int res = 0;

        for(int i=0;i<n;i++) {
            if(tokens[i]=="+") {
                int firstEl = st.top();
                st.pop();
                int secondEl = st.top();
                st.pop();
                int el = secondEl + firstEl;
                st.push(el);
            }
            else if(tokens[i]=="-") {
                int firstEl = st.top();
                st.pop();
                int secondEl = st.top();
                st.pop();
                int el = secondEl - firstEl;
                st.push(el);
            }
            else if(tokens[i]=="*") {
                int firstEl = st.top();
                st.pop();
                int secondEl = st.top();
                st.pop();
                int el = secondEl * firstEl;
                st.push(el);
            }
            else if(tokens[i]=="/") {
                int firstEl = st.top();
                st.pop();
                int secondEl = st.top();
                st.pop();
                int el = secondEl / firstEl;
                st.push(el);
            }
            else {
                st.push(stoi(tokens[i]));
            }
        }

    return st.top();
    }
};