class Solution {
public:
    int numKLenSubstrNoRepeats(string S, int K) {
        int cnt[256]{0};
        int begin = 0, end = 0;
        int res = 0;
        int noDistinct = 0;

        while (end < S.size()) {
            if (end - begin + 1 < K) {
                if (cnt[S[end++]]++ == 0) {
                    ++noDistinct;
                }
            }
            else { // always maintain a sliding window of size K. If noDistinct == K in window, ++res
                if (cnt[S[end]]++ == 0) ++noDistinct;
                if (noDistinct == K) ++res;
                if (--cnt[S[begin++]] == 0) --noDistinct;
                ++end;
            }
        }

        return res;
    }
};
