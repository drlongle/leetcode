class Solution {
public:
    int numSplits(string s) {
        unordered_map<char, int> total;
        for (auto c: s) total[c]++;
        int total_size = (int)total.size(), res = 0;
        unordered_set<char> p;
        for (auto c: s) {
            p.insert(c);
            total[c]--;
            total_size -= !total[c];
            res += (total_size == p.size());
        }
        return res;
    }
};
