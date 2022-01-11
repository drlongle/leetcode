class Solution {
public:
    const int mod = 1e9 + 7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<long long> dp(n, 1);
        map<int, int> m;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(arr[i] % arr[j] == 0 && m.find(arr[i] / arr[j]) != m.end()) {
                    int pos = arr[i] / arr[j];
                    dp[i] += dp[j] * dp[m[pos]];
                }
            }
            m[arr[i]] = i;
            ans = (ans + dp[i]) % mod;
        }

        return ans;
    }
};
