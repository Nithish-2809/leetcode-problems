int calculatePlayer1Score(vector<int>&nums,int left,int right) {
    if(left>right) return 0;
    if(left==right) return nums[left];

    int score = 0;

    int pickStart = nums[left]+min(calculatePlayer1Score(nums,left+2,right),
                                calculatePlayer1Score(nums,left+1,right-1));

    int pickEnd = nums[right]+min(calculatePlayer1Score(nums,left,right-2),
                                calculatePlayer1Score(nums,left+1,right-1));

    return max(pickStart,pickEnd);
}


class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int totalScore = 0;
        for(int i=0;i<n;i++) {
            totalScore += nums[i];
        }

        int player1Score = calculatePlayer1Score(nums,0,n-1);
        int player2Score = totalScore-player1Score;

        return player1Score>=player2Score;
    }
};