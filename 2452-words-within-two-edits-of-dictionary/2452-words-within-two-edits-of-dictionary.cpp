bool isAlmostMatch(string query,string word) {
    int n = query.size();
    int m = word.size();

    if(n!=m) return false;

    int edits = 0;

    for(int i=0;i<m;i++) {
        if(query[i]!=word[i]) {
            edits++;
            if(edits>2) return false;
        }
    }

    return true;
}





class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int n = queries.size();
        int m = dictionary.size();
        vector<string>ans;


        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(queries[i]==dictionary[j]) {
                    ans.push_back(queries[i]);
                    break;
                }
                else if(isAlmostMatch(queries[i],dictionary[j])) {
                    ans.push_back(queries[i]);
                    break;
                }
            }
        }

    return ans;
    }
};