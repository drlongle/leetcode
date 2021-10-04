class Solution {
public:
    unordered_map<string, string> cache;

    string encode(string s) {
        return dp(s);
    }

    string dp(string cur) {
        if (cur.size() <= 1) return cur;
        if (cache.count(cur)) return cache[cur];
        int minLen = cur.size();
        string minStr = cur;
        for (int i = 0; i < (cur.size()/2); ++i) {
            int maxRepeatCnt = getMaxRepeatCnt(cur, i);
            string repeatWord = cur.substr(0, i + 1);
            for (int r = 1; r <= maxRepeatCnt; ++r) {
                int nextIdx = repeatWord.size() * r;
                string ret = (r >= 2 ? to_string(r) + "[" : "") + dp(repeatWord) + (r >= 2 ? "]" : "");
                if (cur.size() - nextIdx >= 1)
                    ret += dp(cur.substr(nextIdx, cur.size() - nextIdx));
                if (ret.size() < minLen) {
                    minLen = ret.size();
                    minStr = ret;
                }
            }
        }
        return cache[cur] = minStr;
    }

    int getMaxRepeatCnt(string& s, int ti) {
        int rcnt = 1;
        int nextIdx = ti + 1;
        string target = s.substr(0, ti + 1);
        while (true) {
            if (nextIdx + target.size() > s.size())
                break;
            string tmp = s.substr(nextIdx, target.size());
            if (tmp != target)
                break;
            rcnt++;
            nextIdx += target.size();
        }
        return rcnt;
    }
};
