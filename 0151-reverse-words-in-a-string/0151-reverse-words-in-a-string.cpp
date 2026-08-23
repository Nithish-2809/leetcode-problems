class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string res = "";
        stack<string>words;

        int i=0;
        

        while(i<n) {
            if(s[i] ==' ') {
                i++;
                continue;
            }

           string word = "";
           while(i<n && s[i]!=' ') {
            word += s[i];
            i++;
           }

           words.push(word);
        }

        while(!words.empty()) {
            res += words.top();
            words.pop();
            if(!words.empty()) {
                res += ' ';
            }
        }
    
    return res;
    }
};