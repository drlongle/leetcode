class Solution {
public:
    vector<vector<int>> dirs{ {1, 0}, {0, 1}, {1, 1} };
    vector<int> pathsWithMaxScore(vector<string>& board) {
        auto sz = board.size();
        vector<vector<int>> score(sz + 1, vector<int>(sz + 1)), paths(sz + 1, vector<int>(sz + 1));
        board[0][0] = board[sz - 1][sz - 1] = '0';
        paths[0][0] = 1;
        for (int i = 1; i <= sz; ++i) {
            for (int j = 1; j <= sz; ++j) {
                if (board[i - 1][j - 1] == 'X') continue;
                for (auto d : dirs) {
                    auto i1 = i - d[0], j1 = j - d[1];
                    if (paths[i1][j1]) {
                        auto val = score[i1][j1] + (board[i - 1][j - 1] - '0');
                        if (score[i][j] <= val) {
                            paths[i][j] = ((score[i][j] == val ? paths[i][j] : 0) + paths[i1][j1]) % 1000000007;
                            score[i][j] = val;
                        }
                    }
                }
            }
        }
        return { score[sz][sz], paths[sz][sz] };
    }
};
