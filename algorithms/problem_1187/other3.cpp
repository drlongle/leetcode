class Solution {
public:
    const int INF = 0x3f3f3f3f;
    
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());

        int N = int(arr1.size());

        vector<int> dp(N + 1, INF);
        arr1.emplace_back(INF);
        
        dp[0] = 0;
        for (int i = 1; i <= N; i++) {
            auto it = lower_bound(arr2.begin(), arr2.end(), arr1[i]);
            for (int j = i - 1; j >= 0; j--) {
                if (arr1[j] >= arr1[i] || dp[j] < 0)
                    continue;

                int needed = i - j - 1;
                int updatable = int(it - upper_bound(arr2.begin(), arr2.end(), arr1[j]));
                if (needed <= updatable)
                    dp[i] = min(dp[i], dp[j] + needed);
            }
            
            int updatable = int(it - arr2.begin());
            if (i <= updatable)
                dp[i] = min(dp[i], i);
        }
        
        return dp[N] < INF ? dp[N] : -1;
    }
};
