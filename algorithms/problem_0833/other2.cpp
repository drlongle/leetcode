class Solution {
public:
    string findReplaceString(string S, vector<int>& idx, vector<string>& src, vector<string>& tg) {
        map<int, pair<int, string>, greater<int>> m;
        for (auto i = 0; i < idx.size(); ++i) 
            if (S.compare(idx[i], src[i].size(), src[i]) == 0) m[idx[i]] = { src[i].size(), tg[i] };
        for (auto r : m) S.replace(r.first, r.second.first, r.second.second);
        return S;
    }
};
