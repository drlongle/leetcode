class Solution {
    int R, C;
private:
    bool crushing(vector<vector<int>>& board) {
        int crushStatus = false;

        // Scan each Row
        for(int r=0; r<R; r++) {
            for(int c=0; c+2<C; c++) {
                if(board[r][c] != 0 && \
                   abs(board[r][c]) == abs(board[r][c+1]) && \
                   abs(board[r][c+1]) == abs(board[r][c+2])) {
                    board[r][c] = -abs(board[r][c]);
                    board[r][c+1] = -abs(board[r][c+1]);
                    board[r][c+2] = -abs(board[r][c+2]);
                    crushStatus = true;
                }  // if
            }  // for-2
        } // for-1

        // Scan each Culumn
        for(int c=0; c<C; c++) {
            for(int r=0; r+2<R; r++) {
                if(board[r][c] != 0 && \
                   abs(board[r][c]) == abs(board[r+1][c]) && \
                   abs(board[r+1][c]) == abs(board[r+2][c])) {
                    board[r][c] = -abs(board[r][c]);
                    board[r+1][c] = -abs(board[r+1][c]);
                    board[r+2][c] = -abs(board[r+2][c]);
                    crushStatus = true;
                }  // if
            }
        }
        return crushStatus;
    }

    void gravity(vector<vector<int>>& board) {
        for(int r=0; r<R; r++)
            for(int c=0; c<C; c++)
                if(board[r][c] < 0) board[r][c] = 0;

        // Move all the zeros to the end of the vertical array
        for(int c=0; c<C; c++) {
            int si = R-1, ei = R-1;
            while(ei>=0) {
                if(board[ei][c] > 0) {
                    swap(board[si][c], board[ei][c]);
                    si--;
                }
                ei--;
            }
        } // for
        return;
    }

public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        R = board.size();
        C = board[0].size();

        while(crushing(board) == true) {
            gravity(board);
        }

        return board;
    }
};
