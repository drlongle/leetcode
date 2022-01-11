bool canDivideIntoSubsequences(vector<int>& A, int K) {
    int cur = 1, groups = 1, n = A.size();
    for (int i = 1; i < n; ++i) {
        cur = A[i - 1] <  A[i] ? 1 : cur + 1;
        groups = max(groups, cur);
    }
    return n >= K * groups;
}

