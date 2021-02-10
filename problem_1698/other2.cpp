// Rolling hash

class Solution {
public:
    int countDistinct(string s) {
        int n = s.size();
        int p = 53;
        int m = 1e9 + 9;
        vector<long long> p_pow(n);
        p_pow[0] = 1;
        for (int i = 1; i < n; i++)
            p_pow[i] = (p_pow[i-1] * p) % m;

        vector<long long> h(n + 1, 0);
        for (int i = 0; i < n; i++)
            h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;

        int count = 0;
        for (int l = 1; l <= n; l++) {
            unordered_set<long long> hs;
            for (int i = 0; i <= n - l; i++) {
                long long cur_h = (h[i + l] + m - h[i]) % m;
                cur_h = (cur_h * p_pow[n-i-1]) % m;
                hs.insert(cur_h);
            }
            count += hs.size();
        }

        return count;
    }
};
