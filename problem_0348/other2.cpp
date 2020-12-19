class TicTacToe {
private:
    vector<vector<int>> rows;
    vector<vector<int>> cols;
    vector<vector<int>> diagonals;
    int boardsize;

public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        boardsize = n;
        rows.resize(2, vector<int>(n));
        cols.resize(2, vector<int>(n));
        diagonals.resize(2, vector<int>(2));
    }

    int move(int row, int col, int player) {
        if (++rows[player-1][row] == boardsize) return player;
        if (++cols[player-1][col] == boardsize) return player;
        if (row == col) {
            if (++diagonals[player-1][0] == boardsize) return player;
        }
        if (row + col == boardsize-1) {
            if (++diagonals[player-1][1] == boardsize) return player;
        }
        return 0;
    }
};
