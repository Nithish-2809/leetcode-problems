bool checkIfCanReachZero(vector<int>&nums,int index,vector<int>&visited) {
    int n = nums.size();
    if(index<0 || index>=n) return false;
    if(nums[index]==0) return true;
    if(visited[index]) return false;

    visited[index] = 1;

    bool jumpForward = checkIfCanReachZero(nums,index+nums[index],visited);
    bool jumpBackward = checkIfCanReachZero(nums,index-nums[index],visited);

    return jumpForward || jumpBackward;
}






class Solution {
public:
    bool canReach(vector<int>& nums, int start) {
        int n = nums.size();
        vector<int>visited(n,0);
        return checkIfCanReachZero(nums,start,visited);
    }
};