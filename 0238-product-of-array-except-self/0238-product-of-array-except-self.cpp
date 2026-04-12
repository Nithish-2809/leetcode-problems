class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();
        
        vector<int>leftP(n,0);
        vector<int>rightP(n,0);

        int product = 1;

        for(int i=0;i<n;i++) {
            product *= nums[i];

            leftP[i] = product;
        }

        product = 1;

        for(int i=n-1;i>=0;i--) {
            product *= nums[i];

            rightP[i] = product;
        }

        vector<int>ans(n,0);

        for(int i=0;i<n;i++) {
            if(i==0) {
                ans[i] = rightP[i+1];
            }
            else if(i==n-1) {
                ans[i] = leftP[i-1];
            }
            else {
                ans[i] = leftP[i-1]*rightP[i+1];
            }
        }

        

    return ans;
    }
};