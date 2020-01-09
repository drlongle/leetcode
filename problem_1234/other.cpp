class Solution {
public:
    int balancedString(string s) {
        int a=s.size()/4;
        unordered_map<char, int> f;
        for(auto c:s) f[c]++;
        unordered_map<char, int> g;
        int t=0;
        for(auto it:f) {
            if (it.second<=a) continue;
            g[it.first]=it.second-a;
            t+=g[it.first];
        }
        int b, e, n=s.size(), l=0, ret=INT_MAX;
        f.clear();
        for(b=e=0; e<n; e++) {
            if (g.count(s[e])==0) continue;
            if (f[s[e]]<g[s[e]]) l++;
            f[s[e]]++;
            while(g.count(s[b])==0 || f[s[b]]>g[s[b]]) {
                if (g.count(s[b])) f[s[b]]--;
                b++;
            }
            if (l==t) ret=min(ret, e-b+1);
        }
        return ret==INT_MAX?0:ret;
    }
};
