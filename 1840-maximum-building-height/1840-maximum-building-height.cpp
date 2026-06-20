class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {

        // Building 1 always has height 0
        restrictions.push_back({1, 0});

        // If building n has no restriction, give it a very large limit
        bool found = false;
        for (auto &r : restrictions) {
            if (r[0] == n) {
                found = true;
                break;
            }
        }

        if (!found)
            restrictions.push_back({n, n - 1});

        // Sort according to building number
        sort(restrictions.begin(), restrictions.end());

        int m = restrictions.size();

        // Left -> Right pass
        for (int i = 1; i < m; i++) {
            int dist = restrictions[i][0] - restrictions[i - 1][0];
            restrictions[i][1] = min(restrictions[i][1],
                                     restrictions[i - 1][1] + dist);
        }

        // Right -> Left pass
        for (int i = m - 2; i >= 0; i--) {
            int dist = restrictions[i + 1][0] - restrictions[i][0];
            restrictions[i][1] = min(restrictions[i][1],
                                     restrictions[i + 1][1] + dist);
        }

        int ans = 0;

        // Find maximum possible peak between every two restricted buildings
        for (int i = 1; i < m; i++) {

            int x1 = restrictions[i - 1][0];
            int h1 = restrictions[i - 1][1];

            int x2 = restrictions[i][0];
            int h2 = restrictions[i][1];

            int dist = x2 - x1;

            // Maximum peak possible in this interval
            int peak = (h1 + h2 + dist) / 2;

            ans = max(ans, peak);
        }

        return ans;
    }
};