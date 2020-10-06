using lli = long long int;

class Solution {
public:
    int numTriplets(vector<int>& n, vector<int>& p)
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);

        unordered_map<lli, lli> m, u;

        for(int i = 0; i<n.size(); i++)
            for(int j = i+1; j<n.size(); j++)
                m[(lli)n[i] * (lli)n[j]]++;

        for(int i = 0; i<p.size(); i++)
            for(int j = i+1; j<p.size(); j++)
                u[(lli)p[i] * (lli)p[j]]++;


        int ans = 0;
        for(auto e : n)ans += u[(lli)e * (lli)e];
        for(auto e : p)ans += m[(lli)e * (lli)e];

        return ans;
    }
};
