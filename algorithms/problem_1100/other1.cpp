class Solution {
public:
    int numKLenSubstrNoRepeats(string S, int K) {
        vector<int> idxs(26, -1);
        int ans = 0, start = 0, i = 0;
        while(i<S.size()) {
            if (idxs[S[i]-'a']>=start) {
                ans += max(i-start-K+1, 0);
                start = max(idxs[S[i]-'a']+1, i-K+1);
            }
            idxs[S[i]-'a'] = i;
            i++;
        }
        ans += max(i-start-K+1, 0);
        return ans;
    }
};
