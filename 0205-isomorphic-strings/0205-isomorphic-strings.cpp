class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()) return false;
        int n = s.length();

        unordered_map<char,char>stMap;

        for(int i=0;i<n;i++) {
            if(stMap.find(s[i])!=stMap.end() && stMap[s[i]]!=t[i]) {
                return false;
            }
            else {
                stMap[s[i]] = t[i];
            }
        }

        unordered_map<char,char>tsMap;

        for(int i=0;i<n;i++) {
            if(tsMap.find(t[i])!=stMap.end() && tsMap[t[i]]!=s[i]) {
                return false;
            }
            else {
                tsMap[t[i]] = s[i];
            }
        }

        for(auto it : stMap) {
            char key = it.first;
            char value = it.second;

            if(tsMap.find(value)==tsMap.end()) return false;

            if(tsMap[value]!=key) return false;
        }

    return true;
    }
};