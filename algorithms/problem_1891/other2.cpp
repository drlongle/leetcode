class Solution {
  public:
    int maxLength(vector<int> &ribbons, int k) {
        long long sum = 0;
        for (int &x : ribbons)
            sum += x;
        if (1LL * k > sum)
            return 0;
        auto valid = [&](int l) {
            int cnt = 0;
            for (int &x : ribbons)
                cnt += x / l;
            return cnt >= k;
        };
        int lo = 1, hi = min(sum, (long long)1e5);
        while (lo < hi) { // YYYYYNNNN  => upperbound
            int mid = lo + (hi - lo + 1) / 2;
            if (valid(mid))
                lo = mid;
            else
                hi = mid - 1;
        }
        return lo;
    }
};
