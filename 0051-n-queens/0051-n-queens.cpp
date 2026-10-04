class Solution {
public:

    bool isPossibleArrangement(int row,int col,int n,vector<string>& board) {

        // check column
        for(int i=0;i<row;i++) {
            if(board[i][col]=='Q') {
                return false;
            }
        }

        // upper left diagonal
        int r = row;
        int c = col;

        while(r>=0 && c>=0) {
            if(board[r][c]=='Q') {
                return false;
            }

            r--;
            c--;
        }

        // upper right diagonal
        r = row;
        c = col;

        while(r>=0 && c<n) {
            if(board[r][c]=='Q') {
                return false;
            }

            r--;
            c++;
        }

        return true;
    }

    void arrangeQueens(int n,
                       vector<string>& board,
                       vector<vector<string>>& ans,
                       int row) {

        if(row==n) {
            ans.push_back(board);
            return;
        }

        for(int col=0;col<n;col++) {

            if(isPossibleArrangement(row,col,n,board)) {

                board[row][col] = 'Q';

                arrangeQueens(n,board,ans,row+1);

                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;

        vector<string> board(n,string(n,'.'));

        arrangeQueens(n,board,ans,0);

        return ans;
    }
};