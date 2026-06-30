class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        int originalColor = image[sr][sc];

        // If the color is already the same, nothing to do
        if (originalColor == color)
            return image;

        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // Down
            if (row < n - 1 && image[row + 1][col] == originalColor) {
                image[row + 1][col] = color;
                q.push({row + 1, col});
            }

            // Up
            if (row > 0 && image[row - 1][col] == originalColor) {
                image[row - 1][col] = color;
                q.push({row - 1, col});
            }

            // Right
            if (col < m - 1 && image[row][col + 1] == originalColor) {
                image[row][col + 1] = color;
                q.push({row, col + 1});
            }

            // Left
            if (col > 0 && image[row][col - 1] == originalColor) {
                image[row][col - 1] = color;
                q.push({row, col - 1});
            }
        }

        return image;
    }
};