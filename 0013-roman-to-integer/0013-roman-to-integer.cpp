class Solution {
public:
    int romanToInt(string s) {
        int n = s.length();
        unordered_map<char,int>romanMap;

        romanMap['I'] = 1;
        romanMap['V'] = 5;
        romanMap['X'] = 10;
        romanMap['L'] = 50;
        romanMap['C'] = 100;
        romanMap['D'] = 500;
        romanMap['M'] = 1000;

        int ans = 0;

        for(int i=0;i<n;i++) {
            if(i<n-1 && romanMap[s[i]]<romanMap[s[i+1]]) {
                ans -=romanMap[s[i]];
            }
            else {
                ans += romanMap[s[i]];
            }
        }

        return ans;
    }
};