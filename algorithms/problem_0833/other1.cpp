/*
Intuition:
Verify equality of string and change it if necessay.
The only thing we need take attention is that the string form sources and targets can be different.
Instead of record the length changement, I sort indexes and do it from right to left.
(Since indexes.length <= 100 is really small)
In this way, the different length won't bother us anymore.

Explanation:
Descending indexes[] with tracking its index.
Verify equality of subring in S source and source.
Replace S if necessay.
 */

class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        vector<pair<int, int>> sorted;
        for (int i = 0 ; i < indexes.size(); i++)
            sorted.push_back({indexes[i], i});
        sort(sorted.rbegin(), sorted.rend());
        for (auto ind : sorted) {
            int i = ind.first;
            string s = sources[ind.second], t = targets[ind.second];
            if (S.substr(i, s.length()) == s)
                S = S.substr(0, i) + t + S.substr(i + s.length());
        }
        return S;
    }
};
