vector<int> generateRow(int n) {
    vector<int>row;

    long long res = 1;

    row.push_back(res);

    for(int i=2;i<=n;i++) {
        res = res*(n-i+1)/(i-1);
        row.push_back(res);
    }

    return row;
}




class Solution {
public:
    vector<vector<int>> generate(int n) {

        vector<vector<int>>ans;
        
        for(int i=1;i<=n;i++) {
            ans.push_back(generateRow(i));
        }

        return ans;
    }
};