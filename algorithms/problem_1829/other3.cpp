class Solution {
public:
    using VI = vector<int>;
    VI getMaximumXor(VI& A, int K, int cur = 0, VI best = {}) {
        for (auto x: A)
            cur ^= x;
        do {
            best.push_back(0);
            int n = best.size();
            for (auto j{ 0 }; j < K; ++j)
                if ((cur & (1 << j)) == 0)
                    best[n - 1] |= (1 << j);
            cur ^= A.back(), A.pop_back();
        } while (A.size());

        return best;
    }
};
