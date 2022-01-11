class Solution {
public:
    string removeDuplicates(string s, int k) {
        return decompress(compress(s, k));
    }
private:
    // compress the string to array or pairs: {character, count}
    vector<pair<char, int>> compress(const string &s, const int k) {
        vector<pair<char, int>> prefix;
        for (const char ch : s) {
            if (prefix.empty() || prefix.back().first != ch) {
                prefix.push_back({ch, 1});
                continue;
            }

            prefix.back().second++;
            if (prefix.back().second == k) { // easy to see when to remove substring
                prefix.pop_back();
            }
        }
        return prefix;
    }

    string decompress(const vector<pair<char, int>> &prefix) {
        string res;
        for (const auto p : prefix) {
            for (int i=0; i<p.second; ++i) {
                res.push_back(p.first);
            }
        }
        return res;
    }
};
