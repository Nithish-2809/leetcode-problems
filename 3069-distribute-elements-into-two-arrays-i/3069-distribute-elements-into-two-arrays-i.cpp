class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>nums1;
        vector<int>nums2;

        nums1.push_back(nums[0]);
        nums2.push_back(nums[1]);

        for(int i=2;i<n;i++) {
            int a = nums1[nums1.size()-1];
            int b = nums2[nums2.size()-1];
            if(a>b) nums1.push_back(nums[i]);
            else nums2.push_back(nums[i]);
        }

        vector<int>ans;

        for(auto it : nums1) {
            ans.push_back(it);
        }
        for(auto it : nums2) {
            ans.push_back(it);
        }

    return ans;
    }
};