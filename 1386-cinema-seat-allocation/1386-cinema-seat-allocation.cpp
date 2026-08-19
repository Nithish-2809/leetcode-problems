class Solution {
public:

    int calculateMaxGroupsInRow(vector<int> nums) {

        bool left =
            nums[1] == 0 &&
            nums[2] == 0 &&
            nums[3] == 0 &&
            nums[4] == 0;

        bool middle =
            nums[3] == 0 &&
            nums[4] == 0 &&
            nums[5] == 0 &&
            nums[6] == 0;

        bool right =
            nums[5] == 0 &&
            nums[6] == 0 &&
            nums[7] == 0 &&
            nums[8] == 0;

        if(left && right) {
            return 2;
        }

        if(left || middle || right) {
            return 1;
        }

        return 0;
    }

    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        unordered_map<int, vector<int>> theatre;

        for(auto it : reservedSeats) {
            int row = it[0];
            int seat = it[1];

            theatre[row].push_back(seat);
        }

        int maxGroups = 2 * n;

        for(auto it : theatre) {

            int row = it.first;
            vector<int> seats = it.second;

            vector<int> nums(10, 0);

            for(int seat : seats) {
                nums[seat - 1] = 1;
            }

            int groups = calculateMaxGroupsInRow(nums);

            // This row was initially counted as 2
            // so remove the extra amount
            maxGroups -= (2 - groups);
        }

        return maxGroups;
    }
};