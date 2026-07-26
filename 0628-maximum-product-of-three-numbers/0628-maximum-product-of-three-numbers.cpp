class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();

        int product1 = 1;
        product1 *= nums[n-1];
        product1 *= nums[n-2];
        product1 *= nums[n-3];
        
        int product2 = 1;
        product2 *= nums[0];
        product2 *= nums[1];
        product2 *= nums[n-1];

        return max(product1,product2);
    }
};