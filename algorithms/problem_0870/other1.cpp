class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        vector<int> idx(B.size());
        for (int i = 0; i < idx.size(); i++)
            idx[i] = i;
        sort(idx.begin(), idx.end(), [&] (auto &a, auto &b) { return B[a] < B[b]; });
        sort(A.begin(), A.end());
        vector<int> ret(A.size(), -1), rem;
        for (int i = 0, j = 0; j < A.size(); i++, j++) {
            for (; j < A.size() - 1 && A[j] <= B[idx[i]]; j++)
                rem.emplace_back(A[j]);
            ret[idx[i]] = A[j];
        }
        int i = 0;
        for (auto &r : rem) {
            for (; ret[i] != -1; i++);
            ret[i] = r;
        }

        return ret;
    }
};
