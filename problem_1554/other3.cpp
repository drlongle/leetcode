/*
First, we compute a hash for each string i in [0, n) as
hash[i] = a[0] * 26 ^ (m - 1) + a[1] * 26 ^ (m - 2) + ... + a[m - 2] * 26 + a[m - 1]
where n is the number of strings, and m - the number of characters in a string.

Then, we go through each character position j in [0, m), and compute a hash without that character:
h = hash[i] - a[j] * 26 ^ (m - j - 1). We track h in a hash set so we can detect if there is another
string with the same hash.

Note that in the second loop we are going right-to-left so it's easier to compute 26 ^ (m - j - 1).
*/

class Solution {
public:
    bool differByOne(vector<string>& d) {
        int mod = 1000000007, n = d.size(), m = d[0].size();
        vector<int> hash(n);
        for (auto i = 0; i < n; ++i)
            for (auto j = 0; j < m; ++j)
                hash[i] = (26l * hash[i] + (d[i][j] - 'a')) % mod;
        for (int j = m - 1, mult = 1; j >= 0; --j) {
            unordered_map<int, vector<int>> s;
            for (auto i = 0; i < n; ++i) {
                int h = (mod + hash[i] - (long)mult * (d[i][j] - 'a') % mod) % mod;
                if (s.count(h)) {
                    for (auto& k: s[h]) {
                        if (valid(d[k], d[i]))
                            return true;
                    }
                }
                s[h].push_back(i);
            }
            mult = 26l * mult % mod;
        }
        return false;
    }

    bool valid(const string& a, const string& b) {
        int count{0};
        for(int i{0}; i < a.size(); ++i) if(a[i] != b[i]) ++count;
        return count == 1;
    }
};
