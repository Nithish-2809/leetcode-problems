bool linearSearch(vector<int>nums,int k) {
    int n = nums.size();
    for(int i=0;i<n;i++) {
        if(nums[i]==k) return true;
    }

    return false;
}



class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        sum += nums[0];

        for(int i=1;i<n;i++) {
            if(nums[i]==nums[i-1]+1) {
                sum += nums[i];
            }
            else {
                break;
            }
        }



        while(linearSearch(nums,sum)) {
            sum++;
        }

        return sum;
    
    }
};