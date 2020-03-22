
class Solution {
public:
    static vector<int> comp;
    int compute(int i) {
        return i < 2 ? 0 :
            1 + (i % 2 ? compute(i * 3 + 1) : compute(i / 2));
    }
    int getKth(int lo, int hi, int k) {
        if (comp.empty()) {
            for (auto i = 0; i <= 1000; ++i)
                comp.push_back(compute(i));
        }
        vector<int> sorted(hi - lo + 1);
        iota(begin(sorted), end(sorted), lo);
        nth_element(begin(sorted), begin(sorted) + k - 1, end(sorted), [](int i, int j) {
                return comp[i] == comp[j] ? i < j : comp[i] < comp[j]; });
        return sorted[k - 1];
    }
};

vector<int> Solution::comp;
