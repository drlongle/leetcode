class Solution {
  public:
    int minSteps(int n) { return f(n, 1, 0); }
    long long f(int n, int i, int c) {
        if (i == n)
            return 0;
        else if (i > n)
            return INT_MAX;
        long long t = (c == 0) ? INT_MAX : (1 + f(n, i + c, c));
        return min(2 + f(n, i * 2, i), t);
    }
};
