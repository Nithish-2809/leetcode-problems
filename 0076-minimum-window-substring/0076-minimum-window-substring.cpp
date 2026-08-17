int getIndex(char c) {
    if(c >= 'a' && c <= 'z') {
        return c - 'a';          // 0 - 25
    }

    return c - 'A' + 26;         // 26 - 51
}

bool checkIfContains(const vector<int>& s, const vector<int>& t) {
    for(int i = 0; i < 52; i++) {
        if(s[i] < t[i]) {
            return false;
        }
    }

    return true;
}

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();

        vector<int> thashh(52, 0);
        vector<int> hashh(52, 0);

        for(char c : t) {
            thashh[getIndex(c)]++;
        }

        int l = 0;
        int r = 0;

        int start = -1;
        int minLen = INT_MAX;

        while(r < n) {

            // Add s[r] to current window
            hashh[getIndex(s[r])]++;

            // Try shrinking the window
            while(checkIfContains(hashh, thashh)) {

                int len = r - l + 1;

                if(len < minLen) {
                    minLen = len;
                    start = l;
                }

                // Remove s[l]
                hashh[getIndex(s[l])]--;

                l++;
            }

            r++;
        }

        if(start == -1) {
            return "";
        }

        return s.substr(start, minLen);
    }
};