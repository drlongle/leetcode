class Solution {
  public:
    string licenseKeyFormatting(string s, int k) {
        string res = "";
        auto count = 0;
        auto not_dash = [](char c) { return c != '-'; };
        auto to_upper = [](char c) { return toupper(c); };
        for (auto const &c : s | views::reverse | views::filter(not_dash) |
                                 views::transform(to_upper)) {
            ++count;
            res.push_back(c);
            if (count % k == 0)
                res.push_back('-');
        }

        if (res.back() == '-')
            res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};
