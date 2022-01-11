/*
according to the solution:

f(x) = 1/W *[f(x + 1) + f(x + 2) + ... + f(x + W)] (1)
f(x - 1) = 1/W *[f(x) + f(x + 1) + ... + f(x + W - 1)] (2)

(2) - (1), we can get :
f(x - 1) = f(x) - 1/W *[f(x + W) - f(x) (3)

but in (3) equation, the x must less than K - 1, this is very important.
*/

class Solution {
    int N;
    int K;
    int W;
    double fk;
    vector<double> cache;
public:
    double new21Game(int N, int K, int W) {
        this->N = N;
        this->K = K;
        this->W = W;
        fk = 1.0 / W * (min(N - K + 1, W));
        cache = vector<double>(K + W, -1);
        return f(0);
    }
    
    double f(int x) {
        if (x == K - 1) {
            return fk;
        }
        
        if (x >= K && x <= N) {
            return 1.0;
        }
        
        if (x > N) {
            return 0;
        }
        
        if (cache[x] != -1) {
            return cache[x];
        }
        
        double ans = f(x + 1) - 1.0 / W * (f(x + 1 + W) - f(x + 1));
        cache[x] = ans;
        return ans;
    }
};
