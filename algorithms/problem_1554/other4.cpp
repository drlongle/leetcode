class Solution {
public:
    bool differByOne(vector<string>& dict) {
        unordered_map<long long,vector<int>> m; //hash, vector of index
        const int n = dict[0].size();
        const long long mod = 1e9+7;
        vector<long long> vpow = {1};
        for(int i=0;i<n;i++){
            vpow.push_back(vpow.back() * 31 % mod);
        }

        for(int k=0;k<dict.size();k++){
            const auto& s= dict[k];
            long long hash = 0;
            for(int i=0;i<n;i++) hash += vpow[i] * (s[i]-'a'+1);
            for(int i=0;i<n;i++){
                const auto x = (hash + mod - vpow[i] * (s[i]-'a' + 1)) % mod;
                auto& v = m[x];
                for(int index:v){
                    if(verify(s, dict[index])) return true;
                }
                v.push_back(k);
            }
        }
        return false;
    }

    bool verify(const string& a, const string& b){
        int cnt = 0;
        for(int i=0;i<a.size();i++){
            if(a[i] != b[i]) cnt++;
            if(cnt>1) return false;
        }
        return true;
    }
};
