class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n;
        for(auto x:trips) n = max(n,x[2]);
        vector<int>count(n+1,0);
        for(auto x:trips)
        {
            count[x[1]] += x[0];
            count[x[2]] -= x[0];
        }
        for(int i=1 ; i<=n ; i++) count[i] += count[i-1];
        for(int i=0 ; i<n ; i++)
            if(count[i]>capacity) return false;
        return true;
    }
};

