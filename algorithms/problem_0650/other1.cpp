class Solution {
  private:
    int f(int curr, int copied_val, int n) {
        if (curr > n)
            return INT_MAX >> 1;
        if (curr == n)
            return 1;
        int ans = min(1 + f(curr + copied_val, copied_val, n),
                      2 + f(2 * curr, curr, n));
        return ans;
    }

  public:
    int minSteps(int n) {
        if (n == 1)
            return 0;
        return f(1, 1, n);
    }
};
