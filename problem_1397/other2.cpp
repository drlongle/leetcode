/*
Since there are lower bound and upper bound, the common way is f(l, m) = f(0, m) - f(0, l-1). we can compute the number of strings which are smaller than s and no 'evil' string.

trans[i][j] is the maximum matched characters after add (j + 'a') at the position (i + 1) in the 'evil' string.

dp[i][j][k] is the prefix [0, i) of generated string has matched [0, j] of 'evil' string. k = 0 if generated string is greater than s and k = 1 otherwise..

base case: dp[0][0][1] = 1, in this case, the only one is empty string.
answer is the sum of number of strings matched all the prefixes of 'evil' string except itself.
*/

const int P = 1e9 + 7;
class Solution {
public:
    long long dp[501][51][2];
    int trans[51][26]; //array declaration should be in the class
    long long calc(int n, string s, string evil) {
        int e_s = evil.size();
        for (int i = 0; i < e_s; i++) {
            string f = evil.substr(0, i);
            for (int j = 0; j < 26; j++) {
                string g = f + (char)(j + 'a');
                //int flag = 1;
                for (int k = 0; k <= i; k++) {
                    if (g.substr(k) == evil.substr(0, i + 1 - k)) {
                        trans[i][j] = i + 1 - k;
                        //flag = 0;
                        break;
                    }
                }
            }
        }
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < e_s; j++) {
                dp[i][j][0] = dp[i][j][1] = 0;
            }
        }
        dp[0][0][1] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < e_s; j++) {
                for (int k = 0; k < 26; k++) {
                    for (int l: {0, 1}) {
                        int tl;
                        if (k < s[i - 1] - 'a')  tl = 1;
                        else if (k > s[i - 1] - 'a')  tl = 0;
                        else  tl = l;
                        (dp[i][trans[j][k]][l] += dp[i - 1][j][tl]) %= P;
                    }
                }
            }
        }      
        long long ans = 0;
        for (int i = 0; i < e_s; i++) {
            (ans += dp[n][i][1]) %= P;
        }
        return ans;        
    }
    long long findGoodStrings(int n, string s1, string s2, string evil) {
        long long ans = calc(n, s2, evil);
        int ok = 1;
        for (int i = 0; i < s1.size() and ok; i++) {
            ok = s1[i] == 'a';
        }
        if (!ok) {
            for (int j = (int)s1.size() - 1; j >= 0; j--) {
                if (s1[j] > 'a') {
                    s1[j]--;
                    break;
                }
                s1[j] = 'z';
            }
            ((ans += P) -= calc(n, s1, evil)) %= P;
        }
        return ans;
    }
};
