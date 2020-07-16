class Solution {
public:
    double myPow(double x, long long n) {
        if (x == 0) {
            if (n >= 0)
                return 1;
            return NAN;
        }
        if (n < 0)
            return 1.0 / myPow(x, -n);
        if (n == 0)
            return 1.0;
        if (n == 1)
            return x;
        double y = myPow(x, n / 2);
        int mod = n % 2;
        return y * y * myPow(x, mod);
    }
};
