class Solution {
public:
    int FindLeastStartingIndex(string &S, string &T, int r){
        int t = T.size()-1;
        while(r>=0){
            if(S[r] == T[t]) --t;
            if(t == -1) return r;
            --r;
        }
        return -1;
    }

    string minWindow(string &S, string &T) {
        int l=0, r=0, t=0, ns = S.size(), nt = T.size();
        int minWindowLen = INT_MAX, resultStartIndex = -1;

        while(r < ns){
            if(S[r] == T[t] && t++ == nt - 1){
                l = FindLeastStartingIndex(S, T, r);

                if(r-l+1 < minWindowLen){
                    minWindowLen = r-l+1;
                    resultStartIndex = l;
                }
                t = 0;
                r = l;
            }
            ++r;
        }

        return resultStartIndex == -1? "": S.substr(resultStartIndex, minWindowLen);
    }
};
