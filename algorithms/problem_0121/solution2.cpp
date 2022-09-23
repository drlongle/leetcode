class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int res = 0, lo = numeric_limits<int>::max();
        for (int p : prices) {
            res = max(res, p - lo);
            lo = min(lo, p);
        }
        return res;
    }
};
