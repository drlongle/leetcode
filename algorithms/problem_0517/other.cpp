class Solution {
  public:
    int findMinMoves(vector<int> &arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        int n = arr.size();

        if (sum % n != 0)
            return -1;

        int target = sum / n;

        // to_right will always store how many dress we need in the left or
        // how many extra clothes we have so we can pass those clothes to the
        // right
        int i = 0, ans = 0, extra_dress = 0;
        for (auto it : arr) {
            extra_dress += it - target;
            ans = max({ans, abs(extra_dress), (it - target)});
        }
        return ans;
    }
};
