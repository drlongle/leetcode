// it's similar to leetcode 400. Nth Digit

class Solution {
public:
    typedef long long ll;
    ll sum[11] = {0};
    ll d[11] = {0};
    void init() {
        int x = 1;
        sum [1] = 1;
        d[1] = 1;
        for (int i = 2; i <= 10; ++i) {
            d[i] = sum[i - 1] * 8 + (ll)pow(10.0,i-1);
            sum[i] = sum[i - 1] + d[i];
        }
    }
    int newInteger(int n) {
        init();
        ll x = 10,ans = 0;
        while (n > 9) {
            ll tmp = n;
            x = 0;
            for (int i = 1; i <= 10; ++i) {
                if (n >= pow(10,i) - sum[i]) continue;
                else {
                    x = i;
                    break;
                }
            }
            n -= pow(10.0, x - 1);
            n += sum[x - 1];
            ans += pow(10.0, x - 1);
        }
        if (n == 9) ans ++;
        return ans + n;
    }
};

