class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int maxi = 0;

        int n1 = nums1.size();
        int n2 = nums2.size();

        int left = 0;
        int right = 0;

        while(left<n1 && right<n2) {
            if(nums1[left]<=nums2[right]) {
                int dist = right-left;
                maxi = max(maxi,dist);
                right++;
            }
            else {
                left++;
            }
        }


        return maxi;
    }
};