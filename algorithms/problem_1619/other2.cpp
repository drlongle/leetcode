class Solution {
public:
    using VI = vector<int>;
    double trimMean(VI& A) {
        int N = A.size(),
                K = N / 20;
        sort(A.begin(), A.end());
        return accumulate(A.begin() + K, A.end() - K, 0) / double(N - 2 * K);
    }
};
