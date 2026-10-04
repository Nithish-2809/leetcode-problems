bool isPossible(vector<int>nums,int k) {
    int n = nums.size();
    int h = 0;

    for(int i=0;i<n;i++) {
        if(nums[i]>=k) h++;
    }

    return h>=k;
}


class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int low = 0;
        int high = n;

        int ans;

        while(low<=high) {
            int mid = low+(high-low)/2;

            if(isPossible(citations,mid)) {
                ans = mid;
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }

    return ans;
    }
};