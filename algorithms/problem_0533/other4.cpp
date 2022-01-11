class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        const int m = picture.size(), n = picture[0].size();

        vector<int> indexes; // max size N
        // scan rows and mark black:
        for (int i = 0; i < m; ++i) {
            indexes.clear();
            for (int j = 0; j < n; ++j) {
                if (picture[i][j] == 'W') {
                    continue;
                }
                indexes.push_back(j);
            }

            if (indexes.size() == N) {
                for (int j : indexes) {
                    picture[i][j] = 'X';
                }
            }
        }

        int ans = 0;
        // scan cols and count:
        for (int j = 0; j < n; ++j) {
            indexes.clear();
            for (int i = 0; i < m; ++i) {
                if (picture[i][j] == 'W') {
                    continue;
                }
                indexes.push_back(i);
            }

            for (int i : indexes) {
                if (picture[i][j] != 'X') {
                    indexes.clear();
                    break;
                }
            }

            if (indexes.size() == N && rowsEqual(picture, indexes)) {
                ans += N;
            }
        }

        return ans;
    }

private:
    bool rowsEqual(const vector<vector<char>>& picture, const vector<int> & indexes) {
        for (int i = 1; i < indexes.size(); ++i) {
            for (int j = 0; j < picture[0].size(); ++j) {
                if (picture[indexes[i]][j] != picture[indexes[0]][j]) {
                    return false;
                }
            }
        }
        return true;
    }
};
