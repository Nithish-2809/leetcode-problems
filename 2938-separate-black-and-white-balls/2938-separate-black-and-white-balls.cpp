class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0;
        long long ones = 0;

        for(char c : s) {
            if(c == '1') {
                ones++;
            } else {
                ans += ones;
            }
        }

        return ans;
    }
};