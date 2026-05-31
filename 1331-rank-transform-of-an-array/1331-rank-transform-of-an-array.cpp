class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int>st;
        int n = arr.size();

        for(int i=0;i<n;i++) {
            st.insert(arr[i]);
        }

        unordered_map<int,int>mp;
        int rank = 1;

        for(auto it : st) {
            mp[it] = rank;
            rank++;
        }
        vector<int>ans(n);

        for(int i=0;i<n;i++) {
            ans[i] = mp[arr[i]];
        }


        return ans;
    }
};