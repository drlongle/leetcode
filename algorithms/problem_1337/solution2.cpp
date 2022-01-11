class Solution {
public:

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        using Pair = pair<int, int>;
        auto lambda = [] (Pair& a, Pair& b) {
            return a.second < b.second || (a.second == b.second && a.first < b.first);
        };

        priority_queue<Pair, vector<Pair>, decltype(lambda)> pq(lambda);

        for (int i = 0, n = mat.size(); i < n; ++i) {
            int score = accumulate(begin(mat[i]), end(mat[i]), 0);
            pq.emplace(i, score);
            if (pq.size() > k)
                pq.pop();
        }

        vector<int> res;
        while (pq.size()) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        reverse(begin(res), end(res));

        return res;
    }
};