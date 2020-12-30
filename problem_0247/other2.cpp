class Solution {
public:
    vector<string> recurse (int l, int r, vector<string> & options){
        if (l > r) return {""};
        if (l == r) return {"0", "1", "8"};
        vector<string> ans;
        auto curr = recurse(l+1,r-1, options);
        for (auto & el : curr){
            for (auto & option: options){
                if (l==0 and option.at(0)=='0') continue;
                ans.push_back(option.substr(0,1)+el+option.substr(1,1));
            }
        }
        return ans;
    }

    vector<string> findStrobogrammatic(int n) {
        int l=0;
        int r=n-1;
        vector<string> options={"00", "11", "69", "96", "88"};
        return recurse (l, r, options);
    }
};
