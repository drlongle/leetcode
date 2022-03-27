typedef long long int ll;
constexpr ll INF = (ll)(1e16-1e5);
class Solution {
public:
    #define speed_x_time(d, speed) (((ll)d%(ll)speed == 0)?(ll)d:((ll)d - (ll)d%(ll)speed + (ll)speed))
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        int n = dist.size();
        ll dp[n];
        ll speed_x_hoursBefore = (ll)speed * (ll)hoursBefore;
        dp[0] = dist[0];
        for(int i=1;i<n;i++) dp[i] = speed_x_time(dp[i-1], speed) + dist[i];
        if (dp[n-1] <= speed_x_hoursBefore) return 0;

        for(int i=1;i<n;i++)
        {
            ll next_prev_prev = dp[i-1];
            ll prev = INF;
            for(int j=i; j<n; j++)
            {
                ll prev_prev = next_prev_prev;  // same as dp[i-1][j-1] in 2 dimention implementation
                next_prev_prev = dp[j];             // save dp[i-1][j]            in 2 dimention implementation
                dp[j] = min(speed_x_time(dp[j-1], speed),prev_prev)+dist[j];
            }
            if(dp[n-1] <= speed_x_hoursBefore) return i;
        }
        return -1;
    }
};
