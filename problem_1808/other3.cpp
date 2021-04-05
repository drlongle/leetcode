typedef long long ll;

class Solution {
public:
    int maxNiceDivisors(int x) {
        if (x == 1) return 1;
        ll b = x / 3, a = x - b * 3, MOD = 1e9 + 7;
        if (a == 1){
            a = 2;
            b--;
        } else if (a == 2) {
            a = 1;
        }
        return pow_mod(2, a, MOD) * pow_mod(3, b, MOD) % MOD;
    }
private:
    ll pow_mod(ll x, ll y, int MOD) {
        ll a = x % MOD, ans = 1;
        while (y) {
            if (y & 1) ans = (ans * a) % MOD;
            a = (a * a) % MOD;
            y >>= 1;
        }
        return ans;
    }
};
