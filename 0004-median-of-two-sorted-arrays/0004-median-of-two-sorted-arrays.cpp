class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        if(n>m) {
            return findMedianSortedArrays(nums2,nums1);
        }

        int low = 0;
        int high = n;

        while(low<=high) {
            int mid1 = low+(high-low)/2;
            int mid2 = (m+n+1)/2-mid1;

            int x1 = (mid1==0) ? INT_MIN : nums1[mid1-1];
            int x2 = (mid2==0) ? INT_MIN : nums2[mid2-1];
            int x3 = (mid1==n) ? INT_MAX : nums1[mid1];
            int x4 = (mid2==m) ? INT_MAX : nums2[mid2];

            if(x1<=x4 && x2<=x3) {
                if((m+n)%2==1) return max(x1,x2);

                return (max(x1,x2)+min(x3,x4))/2.0;
            }

            else if(x1>x4) {
                high = mid1-1;
            }
            else {
                low = mid1+1;
            }
        }

    return -1;
    }
};