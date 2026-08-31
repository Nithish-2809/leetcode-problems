class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt = 0;

        for(auto it : patterns) {
            if(word.find(it)!=-1) {
                cnt++;
            }
        }

    return cnt;
    }
};