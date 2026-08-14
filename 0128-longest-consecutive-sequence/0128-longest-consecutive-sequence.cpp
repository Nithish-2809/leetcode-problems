class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>st;
        int maxLen = 0;
        for(auto it : nums) {
            st.insert(it);
        }

        for(auto it : st) {
            if(st.find(it-1)!=st.end()) continue;
            else {
                int start = it;
                int len = 1;
                while(st.find(start+1)!=st.end()) {
                    start++;
                    len++;
                }

            maxLen = max(maxLen,len);
            }
        }

    return maxLen;
    }
};