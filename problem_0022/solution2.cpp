class Solution {
public:
    unordered_set<string> compute(int n) {
        if (n == 1)
            return {"()"};
        unordered_set<string> res;

        unordered_set<string> rs = compute(n-1);
        for (auto& r: rs) {
            string s1 = '(' + r + ')';
            string s2 = "()" + r;
            string s3 = r + "()";
            res.emplace(s1), res.emplace(s2), res.emplace(s3);
        }

        for (int i = 2; i <= n/2; ++i) {
            auto rs1 = compute(i);
            auto rs2 = compute(n-i);
            for (auto &r1: rs1) {
                for (auto& r2: rs2) {
                    res.emplace(r1 + r2);
                    res.emplace(r2 + r1);
                }
            }
        }
        
        return res;
    }

    vector<string> generateParenthesis(int n) {
        auto r = compute(n);
        vector<string> res(begin(r), end(r));

        return res;
    }
};