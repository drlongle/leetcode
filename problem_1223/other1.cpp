class Solution {
public:
    long long M = 1e9 + 7;
    int m[5001][6][16];
    int dieSimulator(int n, vector<int>& rollMax) {
        memset(m, -1, sizeof(m));
        return f(n, 0, 0, rollMax);
    }
    
    long long f(int n, int roll, int k, vector<int>& rollMax) {
        if(n == 0) 
            return rollMax[roll] < k ? 0 : 1;
        if(rollMax[roll] < k)
            return 0;
        if(m[n][roll][k] >= 0) return m[n][roll][k];
        long long res = 0;
        for(int i = 0; i < 6; ++i)
            res += f(n - 1, i, roll == i ? k + 1 : 1, rollMax);
        res %= M;
        m[n][roll][k] = res;
        return res;
    }
};
