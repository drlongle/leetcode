
class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    using VVT = vector<vector<tuple<int, int>>>;
    using Set = unordered_set<string>;
    using Queue = queue<tuple<int, int>>;
    bool hasValidPath(VVI& A) {
        VVT dir{
                {},                  // 0 sentinel
                {{ 0, -1}, { 0, 1}}, // 1 left / right
                {{-1,  0}, { 1, 0}}, // 2 upper / lower
                {{ 0, -1}, { 1, 0}}, // 3 left / lower
                {{ 0,  1}, { 1, 0}}, // 4 right / lower
                {{ 0, -1}, {-1, 0}}, // 5 left / upper
                {{ 0,  1}, {-1, 0}}, // 6 right / upper
        };
        auto key = [](auto i, auto j) {
            stringstream ss; ss << i << "," << j;
            return ss.str();
        };
        int M = A.size(),
            N = A[0].size();
        Set seen{{"0,0"}};
        Queue queue; queue.push({0, 0});
        while (!queue.empty()) {
            auto [cur_i, cur_j] = queue.front(); queue.pop();
            if (cur_i == M - 1 && cur_j == N - 1) // target 🎯
                return true;
            auto cand = dir[A[cur_i][cur_j]]; // next candidates
            for (auto [u, v]: cand) {
                auto i = u + cur_i, // next i
                     j = v + cur_j; // next j
                if (i < 0 || i >= M || j < 0 || j >= N || seen.find(key(i, j)) != seen.end())
                    continue;
                auto ok = false;
                auto next = dir[A[i][j]];
                for (auto [p, q]: next)
                    if (p + i == cur_i && q + j == cur_j)
                        ok = true; // next has incoming route from current 👍
                if (ok)
                    seen.insert(key(i, j)),
                    queue.push({i, j});
            }
        }
        return false;
    }
};
