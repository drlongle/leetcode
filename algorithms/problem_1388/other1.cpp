#define ll long long

class Solution 
{
public:
    
    ll dp[502][502];
    ll len;

    // i is the index at slices[i] and cnt is the number of pizza we
    // have eaten so far.
    ll solve(vector<int>& slices, ll i, ll cnt)
    {
        if(i>=len || cnt==(len/3)) return 0;
        if(dp[i][cnt] == -1)
        {
            dp[i][cnt] = max(slices[i] + solve(slices, i+2, cnt+1), solve(slices, i+1, cnt));
        }
        return dp[i][cnt];
    }
    
    int maxSizeSlices(vector<int>& slices) 
    {
        len = slices.size();
        memset(dp, -1, sizeof(dp));
        // not include 1st element.
        ll x = solve(slices, 1, 0);
        memset(dp, -1, sizeof(dp));
        // include 1st element, so exclude last element by making it 0.
        slices[len-1] = 0;
        ll y = solve(slices, 0, 0);
        return max(x,y);
    }
};
