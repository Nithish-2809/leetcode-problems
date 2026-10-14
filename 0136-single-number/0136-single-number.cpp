class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorResult = 0;
        for(auto it : nums) {
            xorResult ^= it;
        }

    return xorResult;
    }
};