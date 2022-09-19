class Solution {
  public:
    string customSortString(string order, string s) {
        map<char, int> table;
        for (int i = 0, sz = order.size(); i < sz; ++i)
            table[order[i]] = i;
        auto lambda = [&table](char a, char b) { return table[a] < table[b]; };
        sort(begin(s), end(s), lambda);
        return s;
    }
};
