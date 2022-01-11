class Solution {
public:
    int countArrangement(int n) {
        if(n <= 3) {
            return n;
        }
        const int MAX = 1 << n;
        vector<int> dp(MAX, 0);
        dp[0] = 1;
        for(int i = 0; i < MAX; i++) {
            int pos = __builtin_popcount(i) + 1;
            for(int j = 0; j < n; j++) {
                int num = j + 1,curr = 1 << j;
                if(!(curr & i) && (pos % num == 0 || num % pos == 0)) {
                    dp[i | curr] += dp[i];
                }
            }
        }
        return dp[MAX - 1];
    }
};
