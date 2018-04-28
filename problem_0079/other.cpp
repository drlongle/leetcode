class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int R, C;
        if (!(R = board.size()) || !(C = board[0].size()))  return false;
        int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int r = 0; r < R; r++)
            for (int c = 0; c < C; c++)
                if (search(r, c, 0, word, board, dir, R, C))
                    return true;
        return false;
    }
    
    bool search(int r, int c, int i, string &word, vector<vector<char>>& bd, int dir[4][2], int R, int C) {
        if (i == word.size())   return true;
        if (r < 0 || r >= R || c < 0 || c >= C) return false;
        if (bd[r][c] != word[i])    return false;
        bd[r][c] = '\0'; // mark visited
        for (int k = 0; k < 4; k++) {
            if (search(r + dir[k][0], c + dir[k][1], i + 1, word, bd, dir, R, C)) {
                bd[r][c] = word[i];
                return true;
            }
        }
        bd[r][c] = word[i];
        return false;
    }
};
