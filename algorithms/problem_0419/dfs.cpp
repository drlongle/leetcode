// DFS flood fill

class Solution {
public:
    int m, n; 
    vector<vector<bool>> flag;
    int go[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void dfs(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] == '.' || flag[i][j]) return;
        flag[i][j] = true;
        for (int d = 0; d < 4; ++d) dfs(board, i+go[d][0], j+go[d][1]);
    }

    int countBattleships(vector<vector<char>>& board) {
        if (board.empty()) return 0;
        m = board.size(), n = board[0].size();
        flag.resize(m, vector<bool>(n, false));
        int result = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (board[i][j] == 'X' && !flag[i][j]) {
                    ++result;
                    dfs(board, i, j);
                }
        return result;
    }
};

