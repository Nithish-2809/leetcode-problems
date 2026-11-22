class Solution {
public:
    bool checkString(string s) {
        int lastA = -1;
        int lastB = -1;
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') {
                lastA = i;
            } else {
                lastB = i;
            }
            
            if (lastB != -1 && lastA > lastB) {
                return false;
            }
        }
        return true;
    }
};
