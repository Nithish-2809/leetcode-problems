class Solution {
public:
    vector<int> original;

    Solution(vector<int>& nums) {
        original = nums;
    }

    vector<int> reset() {
        return original;
    }

    vector<int> shuffle() {
        vector<int> shuffled = original;
        int n = shuffled.size();

        for(int i = n - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            swap(shuffled[i], shuffled[j]);
        }

        return shuffled;
    }
};