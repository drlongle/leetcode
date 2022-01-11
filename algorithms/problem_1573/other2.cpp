class Solution {
public:
    int numWays(string s) {
        int mod = 1e9 + 7;
        int num_ones = 0;
        for (char c: s) {
            if (c == '1') num_ones++;
        }
        if (num_ones == 0) {
            long n = s.size() - 1;
            long long res = (n * (n - 1) / 2) % mod;
            return res;
        }
        if (num_ones % 3 != 0) return 0;
        int one_part = num_ones / 3;
        long a = 1;
        long b = 1;
        long count = 0;
        for (char c: s) {
            if (c == '1')
                count++;
            if (count == one_part) {
                if (c == '0') a++;
            } else if (count == 2 * one_part) {
                if (c == '0') b++;
            }
        }
        return (a * b) % mod;
    }
};