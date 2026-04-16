class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        if(s.length()!=t.length()) return false;

        int n = s.length();

        unordered_map<char,char>stMap;
        unordered_map<char,char>tsMap;

        for(int i=0;i<n;i++) {
            if(stMap.find(s[i])!=stMap.end()) {
                if(stMap[s[i]] != t[i]) return false;
            }
            else stMap[s[i]] = t[i];
            
            if(tsMap.find(t[i])!=tsMap.end()) {
                if(tsMap[t[i]]!= s[i]) return false;
            }
             else tsMap[t[i]] = s[i];
        }


        return true;
    }
};