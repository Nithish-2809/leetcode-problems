vector<int> generateRow(int n) {
    int res = 1;
    vector<int>ans;
    ans.push_back(res);

    for(int i=1;i<n;i++) {
        res = res*(n-i)/i;
        ans.push_back(res);
    }

    return ans;
}

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        
        for(int i=1;i<=numRows;i++) {
            ans.push_back(generateRow(i));
        }

    return ans;
    }
};