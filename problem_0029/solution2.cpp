class Solution {
public:
    long long compute(long long dividend, long long divisor) {
        if (dividend < divisor )
            return 0;
        long long d = 2 * divisor;
        if (dividend < d)
            return 1;
        long long res = compute(dividend, d);
        long long rest = dividend - d * res;
        return res * 2 + compute(rest, divisor);
    }

    int divide(long long divid, long long divis) {
        long long dividend = divid, divisor = divis;
        bool sign = (dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0);
        dividend = abs(dividend);
        divisor = abs(divisor);
        long long res = compute(dividend, divisor);
        res = sign ? - res : res;
        res = min((long long) INT_MAX, res);
        res = max((long long) INT_MIN, res);
        return res;
    }
};