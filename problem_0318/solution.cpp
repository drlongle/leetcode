class Solution {
public:
    bool check(string& a, string& b) {
        int i = 0, j = 0, m = a.size(), n = b.size();
        while (i < m && j < n) {
            if (a[i] == b[j])
                return false;
            if (a[i] < b[j])
                ++i;
            else
                ++j;
        }
        return true;
    }

    int maxProduct(vector<string>& words) {
        for (auto& word: words) {
            sort(begin(word), end(word));
        }

        size_t res = 0, n = words.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                if (check(words[i], words[j])) {
                    res = max(res, words[i].size() * words[j].size());
                }
            }
        }

        return res;
    }
};