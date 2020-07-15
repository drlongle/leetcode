class Solution {
public:
    using VI = vector<int>;
    static constexpr int INF = 2e9 + 7;
    int minDifference(VI& A, int min = INF) {
        sort(A.begin(), A.end());
        int N = A.size(),
            i = 0,
            j = N - 4; // -4 because N - 1 is the last element and we want to disclude 3 elements, thus N - 1 - 3 == N - 4
        while (0 <= j && j < N)
			min = std::min(min, A[j++] - A[i++]); // slide window by 3
        return min < INF ? min : 0;
    }
};
