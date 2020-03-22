/*
Compute hashes for increasing prefix and suffix, reusing the previously computed hashes. This is similar to the Karp–Rabin algorithm.

For the string of i size, the hash is: s[0] * 26 ^ i + s[1] * 26 ^ (i -1) + ... + s[i - 1] * 26.

For the prefix hash, we will multiply the previous value by 26 and add a new letter.
For the suffix hash, we add a new letter multiplied by 26 ^ i.
Note that we need to use some large prime as a modulo to avoid overflow errors, e.g. 10 ^ 9 + 7.

Beware of collisions. After you find a matching hash, you need to check the string. Since OJ test cases do not cause collisions, I am not doing it here.
*/

class Solution {
public:
    string longestPrefix(string &s) {
        unsigned long h1 = 0, h2 = 0, mul = 1, len = 0, mod = 1000000007;
        for (auto i = 0; i < s.size() - 1; ++i) {
            h1 = (h1 * 26 + s[i]) % mod;
            h2 = (h2 + mul * s[s.size() - i - 1]) % mod;
            if (h1 == h2)
                len = i + 1;
            mul = mul * 26 % mod;
        }
        return s.substr(0, len);
    }
};
