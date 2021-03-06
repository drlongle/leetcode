class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        const int n = s.size();
        for(int i=0;i<n;i++) vroot.push_back(i);
        for(auto& v:pairs) connect(v[0], v[1]);
        map<int, vector<int>> unions;
        for(int i=0;i<n;i++) unions[root(i)].push_back(i);
        for(const auto& [root, uni] : unions){
            string t;
            for(auto index:uni) t += s[index];
            sort(t.begin(), t.end());
            for(int i=0; i<t.size();i++) s[uni[i]] = t[i]; 
        }
        return s;
    }
    
    int root(int i){
        if(vroot[i] != i) vroot[i] = root(vroot[i]);
        return vroot[i];
    }
    
    void connect(int i, int j){
        int ri = root(i), rj = root(j);
        if(ri != rj) vroot[ri] = rj;
    }
    
    vector<int> vroot;
};
