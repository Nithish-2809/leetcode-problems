class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.length();
        long long l = 0;

        // Calculate final length
        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                if (l > 0) l--;
            }
            else if (s[i] == '#') {
                l *= 2;
            }
            else if (s[i] == '%') {
                continue;          
            }
            else {
                l++;
            }
        }

        
        if (k >= l) return '.';

        // Traverse backwards
        for (int i = n - 1; i >= 0; i--) {

            if (s[i] >= 'a' && s[i] <= 'z') {
                if (k == l - 1)
                    return s[i];
                l--;
            }
            else if (s[i] == '*') {
                l++;
            }
            else if (s[i] == '#') {
                long long half = l / 2;
                if (k >= half)
                    k -= half;
                l = half;
            }
            else if (s[i] == '%') {
                k = l - 1 - k;
            }
        }

        return '.';
    }
};