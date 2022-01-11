class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        // {cnt, colors}
        map<int64_t, int64_t> m;
        for (int i : inventory) ++m[i];

        int64_t ans = 0;
        while (orders > 0) {
            int64_t R = m.rbegin()->first;
            int64_t colors = m.rbegin()->second;
            m.erase(R);

            int64_t L = !m.empty() ? m.rbegin()->first : 0;
            // max_sell_balls: (L, R] * colors
            int64_t max_sell_balls = (R - L) * colors;
            if (orders >= max_sell_balls) {
                orders -= max_sell_balls;
                ans = (ans + (L + 1 + R) * max_sell_balls / 2) % 1000000007;
                if (L > 0) m[L] += colors;
            } else {
                int64_t rows = orders / colors;
                int64_t sell_balls = rows * colors;
                ans = (ans + (R - rows + 1 + R) * sell_balls / 2) % 1000000007;
                int64_t left = orders % colors;
                ans = (ans + left * (R - rows)) % 1000000007;
                orders = 0;
            }
        }
        return ans;
    }
};
