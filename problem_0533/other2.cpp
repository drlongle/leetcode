class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        int R{(int)picture.size()}, C{(int)picture[0].size()};
        std::unordered_map<string,std::vector<int>> m;
        std::vector<int> hash(R, 0);
        for(int i{0}; i < R; ++i) {
            string tmp{""};
            for(int j{0}; j < C; ++j) tmp += picture[i][j];
            m[tmp].emplace_back(i);
        }

        int id{0};
        for(const auto &[_, v]: m) {
            for(const auto &i: v) hash[i] = id;
            ++id;
        }

        std::vector<int> hcount(R, 0), vcount(C, 0);

        for(int i{0}; i < R; ++i)
            for(int j{0}; j < C; ++j)
                hcount[i] += picture[i][j] == 'B';

            for(int j{0}; j < C; ++j)
                for(int i{0}; i < R; ++i)
                    vcount[j] += picture[i][j] == 'B';


                int count{0};
                for(int j{0}; j < C; ++j) {
                    for(int i{0}; i < R; ++i) {
                        if(picture[i][j] == 'B') {
                            if(vcount[j] == hcount[i] && vcount[j] == N) {
                                for(int k{i}; k < R; ++k) {
                                    if(picture[k][j] == 'B' && hash[k] != hash[i]) goto next;
                                }

                                count += vcount[j];
                                goto next;
                            } else goto next;
                        }
                    }

                    next:
                    continue;
                }

                return count;
    }
};
