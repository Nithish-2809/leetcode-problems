class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int min_diff = INT_MAX;
        int ans = 0;

        for(int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;

            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                int diff = sum - target;

                
                if(abs(diff) < min_diff) {
                    min_diff = abs(diff);
                    ans = sum;
                }

                if(diff == 0) {
                    return sum;   
                }
                else if(diff < 0) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }
        return ans;
    }
};