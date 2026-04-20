class Solution {
public:
    bool canPlaceFlowers(vector<int>& nums, int n) {
        
        int k = nums.size();
        int flowers = 0;

        if(k==1) {
            if(nums[0]==0 && n<=1) return true;
            else if(nums[0]==1 && n<1) return true;
            else return false;
        }

        if(nums[0]==0 && nums[1]==0) {
            flowers++;
            nums[0] = 1;
        }
        for(int i=1;i<k-1;i++) {
            if(nums[i]==0 && nums[i-1]==0 && nums[i+1]==0) {
                flowers++;
                nums[i] = 1;
            }
        }

        if(nums[k-1]==0 && nums[k-2]==0) {
            flowers++;
            nums[k-1] = 1;
        }


        return n<=flowers;
    }
};