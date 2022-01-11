/*
The problem is very simliar to https://leetcode.com/problems/subarray-sum-equals-k/.
Instead of compute pre-sum, we compute exculsive or.
 */

class Solution {
public:
    int longestAwesome(string s) {
        if(s.size()<=1){
            return s.size();
        }
        vector<int> a;
        for(int i = 0;i<10;i++){
            a.push_back(1<<i);
        }
        vector<int> m(1024,s.size());
        int hash = 0;
        int ret = 0;
        for(int i = 0;i<s.size();i++) {
            int next_hash = hash ^ (1<<(s[i]-'0'));
            if(next_hash == 0) {
                ret = i + 1;
                hash = next_hash;
                continue;
            }
            for(auto x : a) {
                int y = x ^ next_hash;
                if(y == 0) {
                    ret = i + 1;
                    break;
                }
                ret = max(ret,i-m[y]);

            }
            hash = next_hash;
            m[hash] = min(m[hash],i);
        }
        return ret;
    }
};
