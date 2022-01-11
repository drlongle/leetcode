// the second argument is to prevent duplicated enumeration

class Solution {
public:
    vector<vector<int>> getFactors(int n, int min=2) {
        vector<vector<int>> ret;

        for(int i=min; i*i <= n; i++) {
            if(n%i==0) {
                ret.push_back({n/i, i});
                auto c = getFactors(n/i, i);
                for(auto &v: c) {
                    v.push_back(i);
                    ret.push_back(v);
                }
            }
        }
        return ret;
    }
};
