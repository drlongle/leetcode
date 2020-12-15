class Solution {
public:
    using VS = vector<string>;
    using VVS = vector<VS>;
    using Map = unordered_map<string, VS>;
    using fun = function<void(VS&&)>;
    VVS wordSquares(VS& A, Map m = {}, VVS ans = {}) {
        int N = A[0].size();
        for (auto& word: A) {
            string pre;
            m[pre].emplace_back(word);
            for (auto c: word) {
                pre.push_back(c);
                m[pre].emplace_back(word);
            }
        }
        fun go = [&](VS&& path) {
            int i = path.size();
            if (i == N) {
                ans.emplace_back(path);
                return;
            }
            string pre;
            for (auto j{ 0 }, k{ i }; 0 < i && j < k; ++j)
                pre.push_back(path[j][k]);
            for (auto& word: m[pre]) {
                path.emplace_back(word);
                go(move(path));
                path.pop_back();
            }
        };
        go({});
        return ans;
    }
};
