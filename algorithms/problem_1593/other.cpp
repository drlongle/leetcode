class Solution {
public:
    int gMax = 0;
    int findMax(string s, int curIndex, unordered_set<string> &m, int curMax, string curStr) {
        if (curIndex == s.size()) {
            if (gMax < curMax)
                gMax = curMax;
            return curMax;
        } else {
            int maxA = 0, maxB = 0;
            curStr += s[curIndex];
            if (!m.count(curStr)) {
                m.insert(curStr);
                maxA = findMax(s, curIndex + 1, m, curMax + 1, "");
                m.erase(curStr);
            }
            if (curMax + (s.size() - curIndex) > gMax)
                maxB = findMax(s, curIndex + 1, m, curMax, curStr);
            return max(maxA, maxB);
        }
    }
    int maxUniqueSplit(string s) {
        unordered_set<string> m;
        int res = findMax(s, 0, m, 0, "");
        return res;
    }
};
