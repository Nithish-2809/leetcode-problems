class Solution {
public:

static bool cmp (pair<char,int>a,pair<char,int>b) {
    return a.second>b.second;
}

    string frequencySort(string s) {
        int n = s.length();
        unordered_map<char,int>freqMap;

        for(int i=0;i<n;i++) {
            freqMap[s[i]]++;
        }
        vector<pair<char,int>>arr;

        for(auto it : freqMap) {
            arr.push_back(it);
        }

        sort(arr.begin(),arr.end(),cmp);
        int k = arr.size();

        string ans = "";


        for(int i=0;i<k;i++) {
            int count = arr[i].second;
            int ch = arr[i].first;

            for(int j=0;j<count;j++) {
                ans += ch;
            }
        }
       return ans;
    }
};