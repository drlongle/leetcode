class Solution {
  public:
    int numEquivDominoPairs(vector<vector<int>> &dominoes) {
        map<vector<int>, vector<int>> table;
        for (int i = 0, sz = dominoes.size(); i < sz; ++i) {
            auto &d = dominoes[i];
            if (d[1] > d[0])
                swap(d[0], d[1]);
            table[d].push_back(i);
        }
        int res = 0;
        for (auto &[k, v] : table) {
            int sz = v.size();

            res += sz * (sz - 1) / 2;
        }

        return res;
    }
};
