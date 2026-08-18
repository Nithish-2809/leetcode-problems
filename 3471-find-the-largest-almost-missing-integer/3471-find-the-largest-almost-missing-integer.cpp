bool find(vector<int>&nums,int k,int l,int r) {

    for(int i=l;i<=r;i++) {
        if(nums[i]==k) return true;
    }

    return false;
}



class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        
        int maxi = -1;

        for(int i=0;i<n;i++) {
            int l = 0;
            int r = k-1;
            int cnt = 0;
            while(r<n) {
            
                 if(find(nums,nums[i],l,r)) {
                    cnt++;
                 }
                 r++;
                 l++;
            }

            if(cnt==1 && maxi<nums[i]) maxi = nums[i];
        }


    return maxi;
    }
};