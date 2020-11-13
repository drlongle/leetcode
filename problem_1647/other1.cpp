class Solution {
public:
    int minDeletions(string s) {
        vector<int> cnt(26, 0);
        for(auto c:s) cnt[c-'a']++;
        sort(cnt.begin(), cnt.end(), greater<>());
        int pre = cnt[0]+1, res = 0;
        for(auto& x:cnt){
            while(x>=pre && x>0) x--, res++;
            pre = x;
        }
        return res;
    }
};
