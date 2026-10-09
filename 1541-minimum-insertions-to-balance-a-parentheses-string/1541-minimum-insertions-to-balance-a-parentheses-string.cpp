class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        int cnt = 0;
        int insertions = 0;

        for(int i=0;i<n;i++) {
            if(s[i]=='(') {
                cnt++;
            }
            else {
                if(cnt>0) {
                    cnt--;
                }
                else {
                    insertions++;
                }

                if(s[i+1]==')') {
                    i++;
                }
                else {
                    insertions++;
                }
            }
        }

    return (insertions+2*cnt);
    }
};