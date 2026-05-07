bool isPalindrome(string s,int start,int end) {
    while(start<=end) {
        if(s[start]==s[end]) {
            start++;
            end--;
        }
        else {
            return false;
        }
    }

    return true;
}





void partitionStrings(string s,int n,vector<vector<string>>&ans,vector<string>&ds,int index) {
    if(index==n) {
        ans.push_back(ds);
        return;
    }

    for(int i=index;i<n;i++) {
        if(isPalindrome(s,index,i)) {
            ds.push_back(s.substr(index,i-index+1));
            partitionStrings(s,n,ans,ds,i+1);
            ds.pop_back();
        }
    }
}


class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        int n = s.length();
        vector<string>ds;
        partitionStrings(s,n,ans,ds,0);

        return ans;
    }
};