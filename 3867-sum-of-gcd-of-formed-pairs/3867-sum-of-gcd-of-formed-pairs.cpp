class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefixGcd(n,0);
        int maxi = INT_MIN;

        for(int i=0;i<n;i++) {
            maxi = max(maxi,nums[i]);
            prefixGcd[i] = __gcd(nums[i],maxi);
        }

        sort(prefixGcd.begin(),prefixGcd.end());

        long long sum = 0;

        int i = 0;
        int j = n-1;

        while(i<j) {
            sum += __gcd(prefixGcd[i],prefixGcd[j]);
            i++;
            j--;
        }

    return sum;
    }
};