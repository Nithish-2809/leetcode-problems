bool dfs(vector<vector<char>>& board,string word,int index,int row,int col,int n,int m,int len) {

    if(index==len) {
        return true;
    }

    if(row<0 || col<0 || row>=n || col>=m || board[row][col]!=word[index]) {
        return false;
    }

    char temp = board[row][col];
    board[row][col] = '*';

    bool found = dfs(board,word,index+1,row+1,col,n,m,len) ||
                 dfs(board,word,index+1,row-1,col,n,m,len) ||
                 dfs(board,word,index+1,row,col+1,n,m,len) ||
                 dfs(board,word,index+1,row,col-1,n,m,len);

    board[row][col] = temp;

    return found;
}





class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
       int n = board.size();
       int m = board[0].size();
       int k = word.length();

       for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(dfs(board,word,0,i,j,n,m,k)) {
                return true;
            }
        }
       }

       return false;
    }
};