typedef long long int ll;
constexpr int MAX = 1010;
constexpr ll INF = (ll)(1e16);

ll dp[MAX][MAX];
class Solution {
public:
    ll ll_ceil(ll d, ll speed){
        if(d%speed == 0)
            return d;
        return d - d%speed + speed;
    }
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        dp[0][0] = dist[0];
        int n = dist.size();
        for(int i=1;i<n;i++){
            ll d = dist[i];
            // without skip
            dp[i][0] = ll_ceil(dp[i-1][0], speed) + d;
            // skip ?
            for(int j=1;j<=i;j++){
                // not skip here
                ll prev = ll_ceil(dp[i-1][j], speed) + d;
                if(j == i)
                    prev = INF; // no previous information
                // skip now
                ll curr = dp[i-1][j-1] + d;
                if(prev < curr){
                    dp[i][j] = prev;
                }else{
                    dp[i][j] = curr;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(dp[n-1][i] <= (ll)speed * (ll)hoursBefore)
                return i;
        }
        return -1;
    }
};
