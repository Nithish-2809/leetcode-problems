class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int maxi = 0;

        for(char ch : s) {
            if(ch == '(') {
                st.push('(');
                maxi = max(maxi, (int)st.size());
            }
            else if(ch == ')') {
                st.pop();
            }
        }

        return maxi;
    }
};