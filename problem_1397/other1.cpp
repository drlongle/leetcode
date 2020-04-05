/*
Related problem: KMP Table: 1392. Longest Happy Prefix
 */

class Solution {
public:
    int findGoodStrings(int n, string s1, string s2, string evil) {
        vector<int> memo(1 << 17, -1); // Need total 17 bits, can check getKey() function
        return dfs(0, 0, true, true,
			n, s1, s2, evil, computeLPS(evil), memo);
    }
    int dfs(int i, int evilMatched, bool leftBound, bool rightBound,
			int n, string& s1, string& s2, string& evil, const vector<int>& lps, vector<int>& memo) {
        if (evilMatched == evil.size()) return 0; // contain `evil` as a substring -> not good string
        if (i == n) return 1; // it's a good string
        int key = getKey(i, evilMatched, leftBound, rightBound);
        if (memo[key] != -1) return memo[key];
        char from = leftBound ? s1[i] : 'a';
        char to = rightBound ? s2[i] : 'z';
        int res = 0;
        for (char c = from; c <= to; c++) {
            int j = evilMatched; // j means the next match between current string (end at char `c`) and `evil` string
            while (j > 0 && evil[j] != c) j = lps[j - 1];
            if (c == evil[j]) j++;
            res += dfs(i + 1, j, leftBound && (c == from), rightBound && (c == to),
                    n, s1, s2, evil, lps, memo);
            res %= 1000000007;
        }
        return memo[key] = res;
    }
    int getKey(int n, int m, bool b1, bool b2) {
        // Need 9 bits store n (2^9=512), 6 bits store m (2^6=64), 1 bit store b1, 1 bit store b2
        return (n << 8) | (m << 2) | (b1 << 1) | b2;
    }
    vector<int> computeLPS(const string& str) { // Longest Prefix also Suffix
        int n = str.size();
        vector<int> lps = vector<int>(n);
        for (int i = 1, j = 0; i < n; i++) {
            while (j > 0 && str[i] != str[j]) j = lps[j - 1];
            if (str[i] == str[j]) lps[i] = ++j;
        }
        return lps;
    }
};
