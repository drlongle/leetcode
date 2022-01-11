class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(arr,0,n-1,dp);
    }
    
    int solve(vector<int>&arr, int low, int high,vector<vector<int>> &dp){
        // if we have a single leaf node, then smallest possible sum
        // of non-leaf node is zero.
        if(low == high) return 0;
        
        // dp[i][j] --> smallest possible sum of value of each non-leaf node of
        // subarray from i to j both inclusive
        if(dp[low][high] != -1) return dp[low][high];
        
        // priority_queue is being used to find two max values in range [i...j]
        priority_queue<int> pq(arr.begin()+low, arr.begin()+high+1);
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        
        // maxProduct hold product of two maximum values in given range
        int maxProduct = a*b;
        
        int minSum = INT_MAX;
        for(int i=low; i<high; i++){
            minSum = min(minSum, solve(arr,low,i,dp) + solve(arr,i+1,high,dp));
        }
        return dp[low][high] = minSum + maxProduct;
    }
};
