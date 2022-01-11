/*
When n = 2, the only valid string starting with u is uu, valid strings starting with o are [oo, ou], and so on.
The numbers (we use a vector cnt to store them) of valid strings starting with a, e, i, o, u are respectively
[5,4,3,2,1].

When n = 3, the only valid string starting with u is uuu, valid strings starting with o are [ooo, oou, ouu],
and so on. The numbers of valid strings starting with a, e, i, o, u are respectively [15,10,6,3,1].
*/

class Solution {
public:
    int countVowelStrings(int n) {
        vector<int64_t> cnt(5, 1);
        for (int i = 1; i < n; i++)
            for (int j = 3; j >= 0; j--) cnt[j] += cnt[j + 1];
        return std::accumulate(cnt.begin(), cnt.end(), 0);
    }
};
