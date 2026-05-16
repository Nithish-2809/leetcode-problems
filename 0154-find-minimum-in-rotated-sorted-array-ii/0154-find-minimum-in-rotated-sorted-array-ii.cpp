class Solution {
public:
    int findMin(vector<int>& arr) {
            int n = arr.size();
        int mini = INT_MAX;
        int low = 0;
        int high = n-1;
        while(low<=high) {

           int mid = (low + high)/2;
            mini = min(mini,arr[mid]);
           if(arr[low]==arr[mid] && arr[mid]== arr[high]) {
                low = low+1;
                high = high-1;
                continue;
           }

           if(arr[low]<=arr[mid]) {
                mini = min(mini,arr[low]);
                low = mid + 1;
           }
           else {
            mini = min(mini,arr[mid]);
            high = mid-1;
           }
        }
        return mini;
    }
};