class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string,vector<string>>tempMap;

        for(int i=0;i<n;i++) {
            string s = strs[i];

            sort(s.begin(),s.end());

            tempMap[s].push_back(strs[i]);
        }

        vector<vector<string>>ans;

        for(auto it : tempMap) {
            ans.push_back(it.second);
        }

    return ans;
    }
};