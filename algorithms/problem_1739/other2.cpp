class Solution {
  public:
    int minimumBoxes(int n) {
        int64_t lo{1}, hi{1817}, mid, det;
        while (lo < hi) {
            mid = (lo + hi) >> 1;
            det = mid * (mid + 1) * (mid + 2) / 6;
            if (det > n)
                hi = mid;
            else
                lo = mid + 1;
        }

        det = lo * (lo + 1) * (lo + 2) / 6;

        if (det == n)
            return lo * (lo + 1) / 2;

        --lo;
        n -= lo * (lo + 1) * (lo + 2) / 6;

        int r{(int)std::ceil((std::sqrt(1 + 8 * n) - 1) / 2)};

        return r + lo * (lo + 1) / 2;
    }
};
