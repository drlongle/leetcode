class Solution {
  public:
    int getIndex(ArrayReader &R) {
        int l{};
        for (int r{R.length()}; l + 1 < r;) {
            int m = (l + r) / 2;
            (R.compareSub(l, m - 1, m + (r - l & 1), r - 1) < 1 ? l : r) = m;
        }
        return l;
    }
};
