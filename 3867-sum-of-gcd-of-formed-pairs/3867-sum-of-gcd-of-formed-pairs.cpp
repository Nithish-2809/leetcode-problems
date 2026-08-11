class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long>maxi(n,0);

        maxi[0] = nums[0];

        for(int i=1;i<n;i++) {
            maxi[i] = max(maxi[i-1],(long long)nums[i]);
        }

        vector<long long>prefixGcd(n,0);

        for(int i=0;i<n;i++) {
            prefixGcd[i] = __gcd((long long)nums[i],maxi[i]);
        }

        sort(prefixGcd.begin(),prefixGcd.end());

        int i = 0;
        int j = n-1;
        long long sum = 0;

        while(i<j) {
            sum += __gcd(prefixGcd[i],prefixGcd[j]);
            i++;
            j--;
        }
    return sum;
    }
};