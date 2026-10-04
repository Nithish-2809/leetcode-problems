class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.length();
        int depth = 0;
        string res = "";

        for(int i=0;i<n;i++) {
            if(s[i]=='(') {

                if(depth>0) {
                    res += s[i];
                }

                depth++;
            }
            else {
                depth--;

                if(depth>0) {
                    res += s[i];
                }
            }
        }

    return res;
    }
};