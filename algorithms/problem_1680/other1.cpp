class Solution {
public:
    int concatenatedBinary(int n) {
        long ans = 0;
        const int mod = 1000000007;

        for (int i = 1; i <= n; ++i) {
            int x = i, len = 0;

            while (x > 0) {
                ++len;
                x /= 2;
            }

            ans = (ans << len) % mod + i;
        }

        return ans % mod;
    }
};
