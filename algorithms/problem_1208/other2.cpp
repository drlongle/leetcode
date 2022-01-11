// Two pointers

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        int p = 0;
        int q = 0;
        int curCost = 0;
        int res = 0;
        while (q < n) {
            while (q < n && curCost <= maxCost) {
                curCost += abs(s[q]-t[q]);
                q++;
            }
            res = max(res, q-1-p);
            while (p < q && curCost > maxCost) {
                curCost -= abs(s[p]-t[p]);
                p++;
            }
        }
        res = max(res, q-p);
        return res;
    }
};
