class Solution {
public:
    bool solve(int prevJump, int currStone, vector<int>& stones,
               unordered_map<int, int>& mp, int n,
               vector<vector<int>>& dp) {

        if (currStone == n - 1)
            return true;

        if (dp[currStone][prevJump] != -1)
            return dp[currStone][prevJump];

        int currPos = stones[currStone];

        // k - 1
        if (prevJump - 1 > 0 && mp.count(currPos + prevJump - 1)) {
            if (solve(prevJump - 1, mp[currPos + prevJump - 1],
                      stones, mp, n, dp))
                return dp[currStone][prevJump] = true;
        }

        // k
        if (prevJump > 0 && mp.count(currPos + prevJump)) {
            if (solve(prevJump, mp[currPos + prevJump],
                      stones, mp, n, dp))
                return dp[currStone][prevJump] = true;
        }

        // k + 1
        if (mp.count(currPos + prevJump + 1)) {
            if (solve(prevJump + 1, mp[currPos + prevJump + 1],
                      stones, mp, n, dp))
                return dp[currStone][prevJump] = true;
        }

        return dp[currStone][prevJump] = false;
    }

    bool canCross(vector<int>& stones) {
        int n = stones.size();

        if (stones[1] != 1)
            return false;

        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
            mp[stones[i]] = i;

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return solve(0, 0, stones, mp, n, dp);
    }
};