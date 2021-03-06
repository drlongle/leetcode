class Solution {
public:
    int numOfArrays(int arrSize, int maxVal, int maxCost) {
        using ll=long long;
        // dp[arrSizeSoFar][maxValSoFar][costSoFar]
        vector<vector<vector<ll>>> dp(arrSize+1,vector<vector<ll>>(maxVal+1, vector<ll>(maxCost+1,0)));
        for(int v=1;v<=maxVal;v++) dp[1][v][1]=1;    // for each array of size 1 just 1 way of making it

        // emulate building a sequence: add a new num to the existing sequence and check the cost
        for(int s=2;s<=arrSize;s++) {                  // for each size  
            for(int mv=1;mv<=maxVal;mv++) {               // for each maxVal so far
                for(int c=1;c<=maxCost && c<=s;c++) {  // for each cost so far; optimization: cost <= arrSizeSoFar
                    for(int v=1;v<=maxVal;v++) {    // try each new num in range [1...maxVal]
                        // if new num updates the maxValSoFar, increase the cost and save the num of ways for the new maxVal
                        if(v<=mv) dp[s][mv][c]+=dp[s-1][mv][c],   dp[s][mv][c]%=1000000007;
                        else      dp[s][v][c] +=dp[s-1][mv][c-1], dp[s][v][c]%=1000000007;
                    }
                }
            }
        }
        
        ll res=0;
		// build up the total result: any maxVal in [1..maxVal] and fixed arrSize and maxCost
        for(int v=1;v<=maxVal;v++)
            res+= dp[arrSize][v][maxCost], res%=1000000007;
        
        return res;        
    }
};
