class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int ans = INT_MAX;

        int n = words.size();

        for(int i=startIndex;i<startIndex+n;i++) {
            if(words[i%n]==target) {
               int dist = abs(i - startIndex);
                ans = min(ans, min(dist, n - dist));
            }
        }

        return ans==INT_MAX?-1 : ans;
        
    }
};