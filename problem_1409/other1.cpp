class Solution {
public:
    using VI = vector<int>;
    VI processQueries(VI& queries, int N, VI ans = {}) {
        VI A(N); iota(A.begin(), A.end(), 1);
        for (auto j: queries) {
            auto i = distance(A.begin(), find(A.begin(), A.end(), j));
            for (ans.push_back(i); i > 0; --i)
                swap(A[i - 1], A[i]); // "bubble up" A[i] to the front of A
        }
        return ans;
    }
};
