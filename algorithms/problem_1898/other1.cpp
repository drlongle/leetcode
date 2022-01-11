/*
For each removed position in our string, we store its index in rem. That way, we can quickly check
if that character was removed for a given k.

Then, we binary-search for the largest k when we can find a subsequence with characters rem[i] < k removed.
*/

class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& rem) {
        int l = 0, r = rem.size();
        vector<int> map(s.size(), INT_MAX);
        for (int i = 0; i < rem.size(); ++i)
            map[rem[i]] = i;
        while (l < r) {
            int m = (l + r + 1) / 2, j = 0;
            for (int i = 0; i < s.size() && j < p.size(); ++i)
                /*
                 * map[i] < m: s[i] is included in the first m removed characters
                 * map[i] >= m: s[i] is not included in the first m removed characters
                 */
                if (map[i] >= m && s[i] == p[j])
                    ++j;
            if (j == p.size())
                l = m;
            else
                r = m - 1;
        }
        return l;
    }
};
