/*
dp[i][j] is the minimum distance travelled to travel the i road with j skips
Avoid Dealing with floating point numbers for simpler calculations
*/

class Solution {
public:
#define ll long long
    int minSkips(vector<int>& dist, ll speed, ll hoursBefore) {
        int n=dist.size();
        ll dp[n+2][n+2];
        for(int i=0;i<n+2;i++){
            for(int j=0;j<n+2;j++){
                dp[i][j]=1e18;
            }
        }
        //making 1-indexed array
        reverse(dist.begin(),dist.end());
        dist.push_back(-1);
        reverse(dist.begin(),dist.end());
        
        //base case
        for(int i=0;i<=n;i++){ 
            dp[0][i] = 0 ;
        }
        
        for(int i=1;i<=n;i++){ // road 
            for(int j=0;j<i;j++){ // skip 
                dp[i][j]=(dp[i-1][j]+speed-1)/speed*speed + dist[i];
                
                if(j-1>=0){
                    dp[i][j]=min(dp[i][j],dp[i-1][j-1]+dist[i]);
                }
            } 
        }
        
        int ans=1e9;
        for(int i=0;i<n;i++){
            if(dp[n][i]<=speed*hoursBefore){
                ans=i;
                break;
            }
        }
        if(ans==(int)1e9){
            return -1;
        }return ans;
        
    }
};
