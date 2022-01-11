/*
Intuition

Any number n greater than 1 already have two divisors: 1 and n. So, for a number to have exact 4 divisors, there should be only one pair of divisors d and n / d.

Catch: if d == n / d, the number has 3 divisors, not four.
 */
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        auto sum = 0;
        for (auto n : nums) {
            auto last_d = 0;
            for (auto d = 2; d * d <= n; ++d) {
                if (n % d == 0) {
                    if (last_d == 0)
                        last_d = d;
                    else {
                        last_d = 0;
                        break;
                    }
                }
            }
            if (last_d > 0 && last_d != n / last_d) {
                sum += 1 + n + last_d + n / last_d;
            }
        }
        return sum;
    }

};
