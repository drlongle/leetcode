class Solution {
public:
    using VI = vector<int>;
    using Map = unordered_map<int, long long>;
    bool containsNearbyAlmostDuplicate(VI& A, int K, int T, Map m = {}) {
        int N = A.size();
        if (N < 2)
            return false;
        auto bucket = [=](auto x) { return T ? x / T : x / (T + 1); };  // ⭐️ +1 to avoid division by 0 when T == 0
        auto ok = [&](auto i, auto j) { return m.find(j) != m.end() && abs(m[j] - A[i]) <= T; };
        for (auto i{ 0 }; i < N; ++i) {
            // 1. check each j-th bucket for case 1 || case 2 || case 3
            auto j = bucket(A[i]);
            if (ok(i, j - 1) || ok(i, j) || ok(i, j + 1))  // (adjacent bucket to-the-left || same bucket || adjacent bucket to-the-right )
                return true;
            // 2. slide window
            m[j] = A[i];                      // ✅ add current value A[i] onto the window by mapping A[i] to the j-th bucket
            if (0 <= i - K) {
                auto end = bucket(A[i - K]);  // remove end value A[i - K] from window by removing mapping A[i - K] to end-th bucket which "fell off the end" of window of size K
                m.erase(end);
            }
        }
        return false;
    }
};
