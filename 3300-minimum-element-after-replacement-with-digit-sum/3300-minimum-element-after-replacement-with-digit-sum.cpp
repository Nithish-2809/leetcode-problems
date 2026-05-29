int digitSum(int n) {
    int sum = 0;
    while(n>0) {
        int ld = n%10;
        sum += ld;
        n /= 10;
    }

    return sum;
}




class Solution {
public:
    int minElement(vector<int>& nums) {
       int n = nums.size();
       int mini = INT_MAX;

       for(int i=0;i<n;i++) {
        int sum = digitSum(nums[i]);
        nums[i] = sum;
        mini = min(mini,nums[i]);
       } 

       return mini;
    }
};