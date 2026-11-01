class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ints;
        int n = intervals.size();
        int cnt = 0;

        for(int i=0;i<n;i++) {
            if(ints.empty() || ints.back()[1]<=intervals[i][0]) {
                ints.push_back(intervals[i]);
            }
            else {
                cnt++;
                ints.back()[1] = min(intervals[i][1],ints.back()[1]);
            }
        }

    return cnt;
    }
};