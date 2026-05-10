bool isSafe(int row,int col,vector<string>&board,int n) {
    int dupCol = col;
    int dupRow = row;

    while(col>=0 && row>=0) {
        if(board[row][col]=='Q') return false;
        row--;
        col--;
    }

    col = dupCol;
    row = dupRow;

   while(col >= 0) {
        if(board[row][col] == 'Q') return false;
        col--;
    }
    
    col = dupCol;
    row = dupRow;

    while(row<n && col>=0) {
        if(board[row][col]=='Q') return false;
        row++;
        col--;
    }


    return true;
}





void solve(vector<string>&board,vector<vector<string>>&ans,int n,int col) {
    if(col==n) {
        ans.push_back(board);
        return;
    }

    for(int i=0;i<n;i++) {
        if(isSafe(i,col,board,n)) {
            board[i][col] = 'Q';
            solve(board,ans,n,col+1);
            board[i][col] = '.';
        }
    }
}




class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;

        vector<string> board(n, string(n, '.'));

        solve(board,ans,n,0);


        return ans;

    }
};