bool containsAbc(vector<int>hashh) {

    int n = hashh.size();
    if(n<3) return false;
    if(hashh[0]<1 || hashh[1]<1 || hashh[2]<1) return false;
    

    return true;
}







class Solution {
public:
    int numberOfSubstrings(string s) {

        int n = s.length();
        int l = 0;
        int r = 0;

        int cnt  = 0;
        vector<int>hashh(3,0);

        while(r<n) {
            hashh[s[r]-'a']++;

            while(containsAbc(hashh)) {
                cnt+= n-r;
                hashh[s[l]-'a']--;
                l++;
            }

            r++;
        }


        return cnt;
    }
};