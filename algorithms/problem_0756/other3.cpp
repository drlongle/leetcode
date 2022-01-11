class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        vector<vector<int>> trans(64, vector<int>());
        auto num = [&](char& c) {
            return int(c) - int('A') + 1;
        };
        for (auto &triple : allowed) trans[num(triple[0]) * 8 + num(triple[1])].push_back(num(triple[2]));
        auto convert = [&](string& s) {
            int ans = 0;
            for (auto &c : s) ans = 8 * ans + num(c);
            return ans;
        };
        function<bool(int, int, int)> dfs = [&](int curr, int next, int offset) {
            if (0 < curr && curr <= 7 && !next) return true;
            while (curr > 7) {
                for (auto n : trans[curr % 64]) {
                    if (dfs(curr / 8, next + (n << (3 * offset)), offset + 1)) return true;
                }
                return false;
            }
            return dfs(next, 0, 0);
        };
        return dfs(convert(bottom), 0, 0);
    }
};
