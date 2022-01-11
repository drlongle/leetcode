/*
Lets convert the original problem into Stars and Bars, lets assume k variables x1,x2,x3...xk.
Now we know that xi >= 1 as segment cannot be of 0 length.

Similarly we can introduce k + 1 space variable, s0,s1,s2.... sk,
now we know that space length can be 0 , so s_i >= 0.

so sum(x_i) + sum(s_i) = n - 1
now we can say d_i = x_i - 1 , so that d_i >= 0 , for the stars and bars condition
sum(d_i) + sum(s_i) = n - k - 1
we know for stars and bars it is nCr(n + r - 1, r - 1)
which get reduced to nCr((n - k - 1) + (2 * k + 1) - 1 , (2 * k + 1) - 1)
which equal to nCr(n + k - 1, 2 * k)
 */

const int mod=1e9+7,MX=2e3+10;
int mult(int a,int b){return (1ll*a*b)%mod;}
int fact[MX],inv[MX],invfact[MX];
void init_INV() {
    fact[0] = invfact[0] = fact[1] = invfact[1] = inv[1] = 1;
    for (int i = 2; i < MX; i++) {
        fact[i] = mult(fact[i - 1], i);
        inv[i] = mult(inv[mod % i], mod - mod / i);
        invfact[i] = mult(invfact[i - 1], inv[i]);
    }
}
int ncr(int n,int r){
    if(r > n) return 0;
    return (1LL * fact[n] * invfact[n-r] % mod) * 1LL *invfact[r] % mod;
}

class Solution {
public:
    int numberOfSets(int n, int k) {
        init_INV();
        return ncr(n + k - 1, 2 * k);
    }
};
