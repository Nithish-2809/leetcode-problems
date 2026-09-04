class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());

        int n1 = s.size();
        int n2 = g.size();
        int i = 0;
        int j = 0;
        int cnt = 0;
        
        while(i<s.size() && j<g.size()) {
            if(s[i]>=g[j]) {
                i++,j++;
                cnt++;
            }
            else {
                i++;
            }
        }

    return cnt;
    }
};