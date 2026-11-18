class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n = words.size();
        string ans = "";

        for(int i=0;i<n;i++) {
            int sum = 0;
            for(auto it : words[i]) {
                sum += weights[it-'a'];
            }
            sum = sum%26;
            char c = 'z' - sum;
            ans += c;
        }

    return ans;
    }
};