class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int n = s.length();

        for(int i=0;i<n;i++) {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[') {
                st.push(s[i]);
            }
            else {
                if(st.empty()) return false;

                char c = s[i];
                char t = st.top();

                if((c==')' && t=='(') ||
                    (c=='}' && t=='{') ||
                    (c==']' && t=='[')
                ) {
                    st.pop();
                }
                else return false;
            }
        }
    return st.empty();
    }
};