class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        sort(strs.begin(),strs.end());

        string first = strs[0];
        string last = strs[n-1];
        int n1 = first.length();
        int n2 = last.length();

        int j = 0;
        string ans = "";

        while(j<n1 && j<n2) {
            if(first[j]==last[j]) {
                ans += first[j];
                j++;
            }
            else {
                break;
            }
        }

        return ans;

    }
};