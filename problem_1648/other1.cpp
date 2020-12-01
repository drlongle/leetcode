/*
We should sell most expensive balls first. The trick here is to how to do it efficiently.
If our inventory is 10 and 5, we can sell 5 balls of the first color for
10 * 11 / 2 - 5 * 6 / 2 = 40 profit.

Then, we sell 2 balls for 5 (we now have two colors with the same count), 2 balls for 4, and so on.
So the profit would be 2 * (5 * (5 + 1)) / 2 = 30.

Easy enough, but the number of orders could fall short. Thus, we check how many full rounds can we
take (orders / colors), and take no more than this number of rounds of the most expensive balls.
Note that we may need to do one more - partial - round.
*/

class Solution {
public:
    int maxProfit(vector<int>& inv, int orders) {
        long res = 0, colors = 1;
        sort(begin(inv), end(inv));
        for (int i = inv.size() - 1; i >= 0 && orders > 0; --i, ++colors) {
            long cur = inv[i], prev = i > 0 ? inv[i - 1] : 0;
            long rounds = min(orders / colors, cur - prev);
            orders -= rounds * colors;
            res = (res + (cur * (cur + 1) - (cur - rounds) * (cur - rounds + 1)) / 2 * colors) % 1000000007;
            if (cur - prev > rounds) {
                res = (res + orders * (cur - rounds)) % 1000000007;
                break;
            }
        }
        return res;
    }
};
