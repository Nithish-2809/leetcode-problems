class Solution {
public:
    int maxProduct(int n) {
        vector<int>res;
        while(n!=0) {
            int ld = n%10;
            res.push_back(ld);
            n = n/10;
        }

        int maxi = INT_MIN;

        int k = res.size();

        for(int i=0;i<k;i++) {
            for(int j=i+1;j<k;j++) {
                maxi = max(maxi,res[i]*res[j]);
            }
        }

    return maxi;
    }
};