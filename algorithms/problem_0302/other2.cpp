class Solution {
public:
    const int dx[4] = {0, 0, -1, 1};
    const int dy[4] = {-1, 1, 0, 0};

    bool isValid(int x, int y, int row, int col) {
        return (x >= 0 && x < row && y >= 0 && y < col);
    }

    void dfs(vector<vector<char>> &image, int x, int y, int row, int col, int &minX, int &minY, int &maxX, int &maxY) {
        minX = min(minX, x);
        maxX = max(maxX, x);
        minY = min(minY, y);
        maxY = max(maxY, y);
        image[x][y] = '0';
        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if (isValid(newX, newY, row, col) && image[newX][newY] == '1') {
                dfs(image, newX, newY, row, col, minX, minY, maxX, maxY);
            }
        }

    }
    int minArea(vector<vector<char>>& image, int x, int y) {
        int row = image.size();
        int col = image[0].size();
        int minX = row, minY = col, maxX = -1, maxY = -1;
        dfs(image, x, y, row, col, minX, minY, maxX, maxY);
        return (maxX - minX + 1) * (maxY - minY + 1);
    }
};
