class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int currSum = 0;
        int evenCnt = 0;
        int oddCnt = 0;
        int res = 0;
        int mod = 1e9 + 7;

        for(auto it : arr) {
            currSum += it;

            if(currSum%2==1) {
                res = (res+1+evenCnt)%mod;
                oddCnt += 1;
            }
            else {
                res = (res+oddCnt)%mod;
                evenCnt += 1;
            }
        }

    return res;
    }
};