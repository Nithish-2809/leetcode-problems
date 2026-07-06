bool coveredCheck(vector<vector<int>>& intervals,int i) {
    int n = intervals.size();

    for(int j=0;j<n;j++) {
        if(j!=i) {
            if(intervals[i][0]>=intervals[j][0] && intervals[i][1]<=intervals[j][1]) {
                return true;
            }
        }
    }

return false;
}




class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int ans = n;
        
        for(int i=0;i<n;i++) {
            if(coveredCheck(intervals,i)) {
                ans--;
            }
        }

    return ans;
    }
};