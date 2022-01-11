class Solution {
public:
    string splitLoopedString(vector<string>& strs) {
        string s, ret;
        for(auto str:strs) {
            string a=string(str.rbegin(), str.rend());
            s+=(a>str?a:str);
        }
        int b=0, i, j, n=strs.size(), m;
        for(b=i=0; i<n; i++, b+=m) {
            auto o=strs[i], r=string(o.rbegin(), o.rend());
            m=o.size();
            string mid=s.substr(b+m)+s.substr(0, b), u=o+mid+o, v=r+mid+r;
            for(j=0; j<m; j++) {
                ret=max(ret, u.substr(j, s.size()));
                ret=max(ret, v.substr(j, s.size()));
            }
        }
        return ret;
    }
};
