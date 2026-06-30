class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int n = nums.size();
        int resultSum = 0;
        int closest = INT_MAX;
        sort(nums.begin(),nums.end());

        for(int i=0;i<n-2;i++) {
            if(i>0 && nums[i]==nums[i-1]) continue;

            int l = i+1;
            int r = n-1;

            while(l<r) {
                int sum = 0;
                sum += nums[i] + nums[l] + nums[r];

                if(sum==target) return sum;
                else if(sum<target) {
                    l++;
                }
                else {
                    r--;
                }

                if(abs(sum-target)<closest) {
                    closest = abs(sum-target);
                    resultSum = sum;
                }
            }
        }

    return resultSum;
    }
};