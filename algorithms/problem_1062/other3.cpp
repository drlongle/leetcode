class Solution {
public:
    int longestRepeatingSubstring(string S) {
        int n = S.length();

        int maxrep = 0;
        for(int shift = 1; shift < n; ++shift){
            int rep = 0;
            for(int i=shift, j=0; i < n; ++i, ++j){
                if(S[i] == S[j]){
                    if(++rep > maxrep){
                        maxrep = rep;
                    }
                }
                else {
                    rep = 0;
                }
            }
        }

        return maxrep;
    }
};
