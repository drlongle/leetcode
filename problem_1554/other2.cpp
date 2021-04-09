/*
THe idea is to generate all any char at index i for all the words in O(L) time, where L is length of the word.
For example, word abc would create .bc, a.c, ab. to be hashed. I use '.' to indicate wild card.
To do this efficiently rolling hash is used.
*/

class Solution {
public:
    bool differByOne(const vector<string>& dict) {
        std::unordered_map<int64_t, std::vector<int>> m;
        const size_t size{dict[0].size()};
        const int MOD = 1e9+7;
        const int PRI = 7;
        const char x = '.';
        for(int i{0}; i < dict.size(); ++i) {
            int64_t hash{0};
            for(int j{0}; j < size; ++j)
                hash = (((hash * PRI) % MOD) + dict[i][j]) % MOD;
            for(int64_t j{(int)size-1}, p{1}; j >= 0; --j) {
                int64_t nh = (((hash + MOD - (((int64_t)dict[i][j] * p) % MOD)) % MOD) + (((int64_t)x * p) % MOD)) % MOD;
                p = (p * PRI) % MOD;
                if(m.count(nh))
                    for(const auto &k: m[nh]) if(valid(dict[i], dict[k])) return true;

                m[nh].emplace_back(i);
            }
        }
        return false;
    }

    bool valid(const string& a, const string& b) {
        int count{0};
        for(int i{0}; i < a.size(); ++i) if(a[i] != b[i]) ++count;
        return count == 1;
    }
};
