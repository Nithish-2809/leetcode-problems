class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        vector<string>words;
        int i = 0;

        while(i<n) {
            
            while(i<n && s[i]==' ') i++;
            if(i>=n) break;

            string word = "";

            while(i<n && s[i]!=' ') {
                word += s[i];
                i++;
            }

            words.push_back(word);
        }

        reverse(words.begin(),words.end());

        int k = words.size();

        string ans = "";

        for(int i=0;i<k;i++) {
            ans += words[i];
            if(i!=k-1) ans += " ";
        }


        return ans;
    }
};