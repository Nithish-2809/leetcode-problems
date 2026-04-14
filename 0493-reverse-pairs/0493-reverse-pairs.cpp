int cnt = 0;
void merge(vector<int>&nums,int low,int mid,int high) {
    int right = mid+1;

    for(int i=low;i<=mid;i++) {
        while(right<=high && nums[i]>2LL*nums[right]) {
            right++;
        }
        cnt += (right-(mid+1));
    }

    int left = low;
    right = mid+1;
    vector<int>temp;

    while(left<=mid && right<=high) {
        if(nums[left]<=nums[right]) {
            temp.push_back(nums[left]);
            left++;
        }
        else {
            temp.push_back(nums[right]);
            right++;
        }
    }

    while(left<=mid) {
        temp.push_back(nums[left++]);
    }
    while(right<=high) {
        temp.push_back(nums[right++]);
    }

    for(int i=low;i<=high;i++) {
        nums[i] = temp[i-low];
    }
}


void mergeSort(vector<int>&nums,int low,int high) {
    if(low>=high) return;
    int mid = (low+high)/2;
    mergeSort(nums,low,mid);
    mergeSort(nums,mid+1,high);
    merge(nums,low,mid,high);
}
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        cnt = 0;
        mergeSort(nums,0,n-1);
        return cnt;
    }
};