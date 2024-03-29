class Solution {
  public:
    using ull = unsigned long long;

    string smallestGoodBase(string _n) {
        ull n = stoll(_n);
        ull maxLen = log2(n) + 1;
        for (ull len = maxLen; len > 2; len--) {
            ull curr = isPossible(len, n);
            if (curr != 0)
                return to_string(curr);
        }
        return to_string(n - 1);
    }

    ull isPossible(ull len, ull n) {
        ull k = pow(n, 1.0 / (len - 1));
        ull temp = 1;
        for (ull i = 1; i < len; i++) {
            temp *= k;
            temp += 1;
            if (temp > n)
                return 0;
        }
        if (temp == n)
            return k;
        return 0;
    }
};
