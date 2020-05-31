//Put all numbers of length k into a hash set. Then test if the set contains all 2^k numbers.

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int d = 0;
        unordered_set<int> hset;
        for (int i = 0; i < s.length(); i++) {
            d = (d << 1) | (s[i] - '0');
            if (i >= k - 1) {
                hset.insert(d);
                d -= (s[i - (k - 1)] - '0') << (k - 1);
            }
        }
        return hset.size() == (1 << k);
    }
};
