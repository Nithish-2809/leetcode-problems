class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;

        for(int i=0;i<=n;i++) {
            if(ans.empty() || ans.back()[1]<intervals[i][0]) ans.push_back(intervals[i]);
            else if(ans.back()[1]>=intervals[i][0]) {
                ans.back()[1] = max(ans.back()[1],intervals[i][1]);
            }
        }

    return ans;
    }
};