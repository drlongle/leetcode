class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    using Map = unordered_map<int, int>;
    VI getModifiedArray(int N, VVI& A, Map m = {}) {
        VI ans(N);
        for (auto& update: A) {
            auto [i, j, k] = tie(update[0], update[1], update[2]);
            m[i] += k, m[j + 1] -= k;  // +k for interval i..j inclusive
        }
        auto t = 0;
        for (auto i{ 0 }; i < N; ++i)
            t += m[i], ans[i] += t;
        return ans;
    }
};
