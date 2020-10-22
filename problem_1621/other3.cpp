/*
 * Pascal triangle

 We can just count the number of combinations of picking 2 * k points (2 points per segment)
 out of n + k - 1 points. The solution below uses the Pascal triangle approach to count combinations.
 */
int dp_pascal[2001][2001] = {};
class Solution {
public:
    long comb(int n, int m) {
        return n == 0 || m == 0 ? 1 :
               dp_pascal[n][m] ? dp_pascal[n][m] :
                       dp_pascal[n][m] = (comb(n - 1, m) + comb(n, m - 1)) % 1000000007;
    }

    int numberOfSets(int n, int k) {
        return comb(n - k - 1, k * 2);
    }
};