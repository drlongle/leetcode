class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> res(length, 0);

        for (auto&& v : updates) {
            res[v.front()]  += v.back();
            if (v[1] + 1 < length)
                res[v[1]+1] -= v.back();
        }

        for (size_t idx = 1; idx < length; ++idx) {
            res[idx] += res[idx - 1];
        }

        return res;
    }
};