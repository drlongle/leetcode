class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n_) {
        rows = std::vector<int>(n_, 0);
        cols = std::vector<int>(n_, 0);
        diag = std::vector<int>(2, 0);
        n = n_;
    }

    int move(int row, int col, int player) {
        if(player == 1) {
            if(++rows[row] == n) return 1;
            if(++cols[col] == n) return 1;
            if(row == col && ++diag[0] == n) return 1;
            if((row == n-col-1) && ++diag[1] == n) return 1;
            return 0;
        }
        if(--rows[row] == -n) return 2;
        if(--cols[col] == -n) return 2;
        if(row == col && --diag[0] == -n) return 2;
        if((row == n-col-1 || col == n-row-1) && --diag[1] == -n) return 2;
        return 0;
    }
    std::vector<int> rows;
    std::vector<int> cols;
    std::vector<int> diag;
    int n;
};
