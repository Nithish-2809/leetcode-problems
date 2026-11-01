class Solution {
public:

    bool wordExists(vector<vector<char>>& board, int row, int col,
                    string &word, int index, vector<vector<int>>& visited) {

        int n = board.size();
        int m = board[0].size();

        if(index == word.size()) return true;

        if(row < 0 || col < 0 || row >= n || col >= m)
            return false;

        if(visited[row][col] || board[row][col] != word[index])
            return false;

        visited[row][col] = 1;

        bool up = wordExists(board, row-1, col, word, index+1, visited);
        bool down = wordExists(board, row+1, col, word, index+1, visited);
        bool left = wordExists(board, row, col-1, word, index+1, visited);
        bool right = wordExists(board, row, col+1, word, index+1, visited);

        visited[row][col] = 0;

        return up || down || left || right;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(board[i][j] == word[0]) {
                    if(wordExists(board, i, j, word, 0, visited))
                        return true;
                }
            }
        }

        return false;
    }
};