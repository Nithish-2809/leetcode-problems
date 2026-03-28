class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;

        unordered_map<char,int>freqMap;

        for(int i=0;i<s.length();i++) {
            freqMap[s[i]]++;
        }

        for(int i=0;i<t.length();i++) {
            if(freqMap.find(t[i])!=freqMap.end()) {
                freqMap[t[i]]--;
                if(freqMap[t[i]]==0) freqMap.erase(t[i]);
            }
            else {
                return false;
            }
        }

        return true;
    }
};