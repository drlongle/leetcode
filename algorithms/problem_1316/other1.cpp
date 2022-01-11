
// For each split point, we are going left and right increasing the size. When the left and right string matches - we add it to the hash set.

class Solution1 {
public:
    int distinctEchoSubstrings(string tx) {
        unordered_set<string> s;
        for (auto split = 1; split < tx.size() - 1; ++split) {
            for (auto sz = 1; split - sz >= 0 && split + sz - 1 < tx.size(); ++sz) {
                if (tx.compare(split - sz, sz, tx, split, sz) == 0)
                    s.insert(tx.substr(split, sz));
            }
        }
        return s.size();
    }
};

class Solution2 {
public:
    int distinctEchoSubstrings(string tx) {
        unordered_set<string> s;
        for (auto split = 1; split < tx.size() - 1; ++split) {
            long long sh_l = 0, sh_r = 0, base = 1;
            for (auto sz = 1; split - sz >= 0 && split + sz - 1 < tx.size(); ++sz) {
                sh_r = ((sh_r * 26) + tx[split + sz - 1]) % 1000000007;
                sh_l = (sh_l + tx[split - sz] * base) % 1000000007;
                base = (base * 26) % 1000000007;
                if (sh_r == sh_l) s.insert(tx.substr(split, sz));
            }
        }
        return s.size();
    }
};

// Optimized solution
class Solution3 {
public:
    int distinctEchoSubstrings(string tx) {
        unordered_set<int> s;
        for (auto split = 1; split < tx.size() - 1; ++split) {
            long long sh_l = 0, sh_r = 0, base = 1;
            for (auto sz = 1; split - sz >= 0 && split + sz - 1 < tx.size(); ++sz) {
                sh_r = ((sh_r * 26) + tx[split + sz - 1]) % 1000000007;
                sh_l = (sh_l + tx[split - sz] * base) % 1000000007;
                base = (base * 26) % 1000000007;
                if (sh_r == sh_l) s.insert(sh_l);
            }
        }
        return s.size();
    }
};
