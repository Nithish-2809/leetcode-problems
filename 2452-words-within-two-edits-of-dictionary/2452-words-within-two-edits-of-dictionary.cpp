bool almostMatch(string s1, string s2) {
        int diff = 0;

        for(int i = 0; i < s1.length(); i++) {
            if(s1[i] != s2[i]) {
                diff++;
                if(diff > 2) return false;
            }
        }

        return true;
    }






class Solution {
public:
    vector<string> twoEditWords(vector<string>& nums, vector<string>& arr) {
        int n = nums.size();
        int q = arr.size();
        vector<string>ans;

        for(int i=0;i<n;i++) {
            for(int j=0;j<q;j++) {
                if(almostMatch(nums[i],arr[j])) {
                    ans.push_back(nums[i]);
                    break;
                }
            }
        }


    return ans;
    }
};