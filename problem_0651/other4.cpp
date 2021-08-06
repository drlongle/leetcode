class Solution {
public:
    //T(n) = O(n^2), bc for each possible i, we also check all possible j < i
    //S(n) = O(n)
    int maxA(int N) {
        vector<int> dp(N+1);
        for(int i = 0; i < dp.size(); i++){
            dp[i] = i;//# of As printted out could be just the # of operations for i = 0,1,2,3,4,5,6
        }
        for(int i = 7; i < dp.size(); i++){
            for(int d = 1; d <= i; d++){
                int tmp = dp[i-d];
                int k = i - (i-d) - 1- 1;
                if(k > 0){
                    tmp += dp[i-d]*k;
                }
                dp[i] = max(dp[i], tmp);
            }
        }
        return dp[N];
    }
};
