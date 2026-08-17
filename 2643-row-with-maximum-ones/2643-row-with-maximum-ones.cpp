class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int maxOnesRowIndex = -1;
        int maxOnes = INT_MIN;

        for(int i=0;i<n;i++) {
            int cnt = 0;
            for(int j=0;j<m;j++) {
                if(mat[i][j]==1) cnt++;
            }
            if(cnt>maxOnes) {
                maxOnes = cnt;
                maxOnesRowIndex = i;
            }
        }

    return {maxOnesRowIndex,maxOnes};
    }
};