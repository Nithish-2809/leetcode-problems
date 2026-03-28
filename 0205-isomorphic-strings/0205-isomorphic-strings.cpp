class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()) return false;
        int n =  s.length();

        unordered_map<char,char>mapst;
        unordered_map<char,char>mapts;

        for(int i=0;i<n;i++) {
            char sChar = s[i];
            char tChar = t[i];

            if(mapst.find(sChar)!=mapst.end()) {
                if(mapst[sChar]!=tChar) {
                    return false;
                }
            }
            else {
                mapst[sChar] = tChar;
            }

            if(mapts.find(tChar)!=mapts.end()) {
                if(mapts[tChar]!=sChar) {
                    return false;
                }
            }
            else {
                mapts[tChar] = sChar;
            }
        }

    return true;
    }
};