class Solution {
  public:
    int minimumBoxes(int n) {
        int lo = 1;
        int hi = 2e3;
        int minlevel = INT_MAX;
        while (lo <= hi) {
            int mid = (lo + (hi - lo) / 2);
            long long val = ((1ll * mid * (mid + 1) * (1ll * 2 * mid + 1)) / 6 +
                             (1ll * mid * (mid + 1)) / 2) /
                            2;
            if (val >= n) {
                minlevel = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        minlevel--;
        n -= ((1ll * minlevel * (minlevel + 1) * (1ll * 2 * minlevel + 1)) / 6 +
              (1ll * minlevel * (minlevel + 1)) / 2) /
             2;
        int ans = (1ll * minlevel * (minlevel + 1)) / 2;
        lo = 1;
        hi = 2e3;
        int idx = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            long long val = (mid * (mid + 1)) / 2;
            if (val >= n) {
                idx = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        ans += idx;
        return ans;
    }
};
