class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int, int> table;
        int n = s.size(), res = 0;
        for (int head = 0, tail = 0; head < n; ++head) {
            char ch = s[head];
            auto it = table.find(ch);
            if (it != table.end())
                tail = max(tail, it->second + 1);
            res = max(res, head - tail + 1);
            table[ch] = head;
        }

        return res;
    }
};
