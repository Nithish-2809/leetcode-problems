string reverseWord(string s) {
    int n = s.length();

    for(int i=0;i<n/2;i++) {
        char temp = s[i];
        s[i] = s[n-i-1];
        s[n-i-1] = temp;
    }

    return s;
}



class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int i = 0;
        int j = 0;
        string ans = "";

        while(j<n) {
            while(j<n && s[j]!=' ') j++;

            string rev  = reverseWord(s.substr(i,j-i));
            ans += rev;
            if(j < n) ans += " ";
            j++;
            i = j;
        }

        return ans;
    }
};