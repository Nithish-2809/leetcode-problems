class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int>copy;

        for(int i=0;i<n;i++) {
            copy.push_back(arr[i]);
        }
        sort(arr.begin(),arr.end());

        unordered_map<int,int>rankMap;

        int rank = 1;
        for(int i=0;i<n;i++) {
            if(rankMap.size()==0) {
                rankMap[arr[i]] = rank;
            }
            else if(arr[i-1]==arr[i]) {
                rankMap[arr[i]] = rank;
            }
            else {
                rank++;
                rankMap[arr[i]] = rank;
            }
        }

        vector<int>rankArray;

        for(auto it : copy) {
            rankArray.push_back(rankMap[it]);
        }

        return rankArray;
    }
};