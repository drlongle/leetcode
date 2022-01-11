class Solution {
public:
    int m, n;

    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        m = board.size();

        n = board[0].size();

        while (crush(board)) drop(board);

        return board;
    }

    void drop(vector<vector<int>>& board) {
        for (int j = 0; j < n; ++j) {
            int k = m-1;
            for (int i = m-1; i >= 0; --i) {
                if (board[i][j] != 0) {
                    swap(board[i][j], board[k--][j]);
                }
            }
        }
    }

    void print(vector<vector<int>>& board) {
        printf("----- board -----\n");
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                printf("%3d ", board[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    bool crush(vector<vector<int>>& board) {
        bool crushed = false;
        // check every rows/cols for consecutive numbers and mark them as 0

        for (int i = 0; i < m; ++i) {
            int prev = 0;
            for (int j = 0; j <= n; ++j) {
                if (j == n or abs(board[i][j]) != abs(board[i][prev])) {
                    if (j - prev >= 3) {
                        while (prev < j) {
                            board[i][prev] = -abs(board[i][prev]);
                            ++prev;
                        }
                    }
                    prev = j;
                }
            }
        }

        for (int j = 0; j < n; ++j) {
            int prev = 0;
            for (int i = 0; i <= m; ++i) {
                if (i == m or abs(board[i][j]) != abs(board[prev][j])) {
                    if (i - prev >= 3) {
                        while (prev < i) {
                            board[prev][j] = -abs(board[prev][j]);
                            ++prev;
                        }
                    }
                    prev = i;
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] < 0) {
                    board[i][j] = 0;
                    crushed = true;
                }
            }
        }

        //print(board);

        return crushed;
    }
};
