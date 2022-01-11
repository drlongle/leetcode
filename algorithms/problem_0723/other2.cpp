class Solution {
public:
    vector<vector<int>> board;
    int m, n;
    bool drop(vector<vector<int>> &mark) {
        bool flag = false;
        // zero all marked cells
        for (int i = 0; i<m; i++)
            for (int j = 0; j<n; j++)
                if (mark[i][j])
                    board[i][j] = 0;

        // drop cells with zero value
        for (int i = m-1; i>=1; i--) {
            for (int j = 0, k = 0; j<n; j++) {
                if (board[i][j] != 0)
                    continue;

                for (k = i; k >= 0 && !board[k][j]; k--);
                if (k < 0) continue;

                swap(board[i][j], board[k][j]);
                flag = true;
            }
        }

        // return true if there was atleast 1 drop
        return flag;
    }

    int dirs[2][2] = {{0, 1}, {1, 0}};
    bool dfs(int i, int j, int cur, vector<vector<int>> &seen, vector<vector<int>> &mark, int isV) {
        seen[i][j] |= (1 << isV) ;
        bool toMark = false;

        int r = i + dirs[isV][0], c = j + dirs[isV][1];
        if (r >= 0 && r < m && c >= 0 && c < n &&
            !((seen[r][c]>>isV) & 1) && board[r][c] == board[i][j])
            toMark |= dfs(r, c, cur+1, seen, mark, isV);

        mark[i][j] |= (cur >= 3 || toMark);
        return cur >= 3 || toMark;
    }

    vector<vector<int>> candyCrush(vector<vector<int>>& b) {
        board = b;
        m = board.size(), n = board[0].size();

        while (1) {
            vector<vector<int>> mark(m, vector<int>(n, 0));
            vector<vector<int>> seen(m, vector<int>(n, 0));

            for (int i = 0; i<m; i++)
                for (int j = 0; j<n; j++)
                    if (board[i][j] != 0) {
                        // mark vertical
                        dfs(i, j, 1, seen, mark, 1);
                        // mark horizontal
                        dfs(i, j, 1, seen, mark, 0);
                    }

            // gravity drop
            if (!drop(mark))
                break;
        }

        return board;
    }

};
