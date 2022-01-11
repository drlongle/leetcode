#include <numeric>
#include <vector>

using namespace std;

/*
The idea is that processing each permutation (order matters) is too time-consuming. Instead, we can process each combination (order does not matter) of how balls can be distributed, check if two boxes have the same number of colors, and calculate how many permutations each combination can produce.

The is similar to the other solutions, with a few optimizations:

Track how many balls are left to fill each box as cnt1 and cnt2.
Count different colors in each box as col1 and col2; compare in the end.
The initial/maximum number of permutatons in each box is (n / 2)!
When selecting m balls of particular color, we reduce the number of permutations by m!
When both cnt1 and cnt2 are zero, prm1 and prm2 are permutations in each box.
- Number of permutations = (n / 2)! / (m1! * m2! * ... * mk!).
- The total number of permutations with two boxes is prm1 * prm2.

Also see: Number of distinct permutation a string can have
https://www.geeksforgeeks.org/number-distinct-permutation-string-can/
 */

class Solution {
public:
    static constexpr int fact[7] = {1, 1, 2, 6, 24, 120, 720};
    double total = 0, match = 0;
    void dfs(vector<int>& balls, int p, int col1, int col2, int cnt1, int cnt2, double prm1, double prm2) { 
        if (cnt1 == 0 && cnt2 == 0) {
            total += prm1 * prm2;
            match += (col1 == col2) * prm1 * prm2;
        }
        else if (cnt1 >= 0 && cnt2 >= 0)
            for (int b1 = 0, b2 = balls[p]; b2 >= 0; ++b1, --b2)
                dfs(balls, p + 1, col1 + (b1 > 0), col2 + (b2 > 0),
                    cnt1 - b1, cnt2 - b2, prm1 / fact[b1], prm2 / fact[b2]);
    }
    double factorial(int n) { return n < 3 ? n : n * factorial(n - 1); }
    double getProbability(vector<int>& balls) {
        auto n = accumulate(begin(balls), end(balls), 0);
        dfs(balls, 0, 0, 0, n / 2, n / 2, factorial(n / 2), factorial(n / 2));
        return match / total;
    }
};
