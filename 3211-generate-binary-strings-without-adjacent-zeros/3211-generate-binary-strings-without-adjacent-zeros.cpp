void getAllValidSubstrings(int index,int n,string res,vector<string>&ans,bool canPlaceZero) {
    if(index>=n) {
        ans.push_back(res);
        return;
    }

    if(canPlaceZero) {
        getAllValidSubstrings(index+1,n,res+'0',ans,false);
        getAllValidSubstrings(index+1,n,res+'1',ans,true);
    }
    else {
        getAllValidSubstrings(index+1,n,res+'1',ans,true);
    }
}


class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string>ans;
        
        getAllValidSubstrings(0,n,"",ans,true);

    return ans;
    }
};