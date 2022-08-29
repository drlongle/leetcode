class Solution {
  public:
    bool check(int x, int m, int n, int k) {
        int cnt = 0;

        for (int i = 1; i <= m; i++) {
            int j = x / i;
            cnt += min(j, n);
        }
        return cnt >= k;
    }

    int findKthNumber(int m, int n, int k) {
        int l = 0, r = m * n;
        // binary search on kth smallest element
        while (r - l > 1) {
            int mid = (l + r) >> 1;
            if (check(mid, m, n, k))
                r = mid;
            else
                l = mid;
        }
        return r;
    }
};
