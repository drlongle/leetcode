class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        int h = picture.size(), w = h ? picture[0].size():0;
        vector<int>col(w, 0);
        unordered_map<string, int> kv;
        for (int i = 0; i < h; ++i) {
            int k = 0;
            for (int j = 0; j < w; ++j) {
                if (picture[i][j] == 'B') {
                    ++col[j]; ++k;
                }
            }
            if (k == N) {
                ++kv[string(picture[i].begin(), picture[i].end())];
            }
        }
        int rst = 0;
        for (auto &p:kv) {
            if (p.second != N) continue;
            for (int i = 0; i < w; ++i) {
                rst += (p.first[i] == 'B' && col[i] == N ? N:0);
            }
        }
        return rst;
    }
};
