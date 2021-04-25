/*
Scan array B, compute a cnt array where cnt[i] is the number of bit 1s at the i-th bit of all numbers in B.
For each a in array A, let x be the result of (a AND B[0]) XOR (a AND B[1]) ...:
  If a's ith bit is 0, or cnt[i] % 2 == 0, then x's ith bit must be 0.
  Otherwise x's i-th bit must be 1.
The answer is the XOR result of all the x values.
*/

class Solution {
public:
    int getXORSum(vector<int>& A, vector<int>& B) {
        int cnt[31] = {};
        for (int b : B) {
            for (int i = 0; i < 31; ++i) {
                cnt [i] += (b >> i & 1);
            }
        }
        int ans = 0;
        for (int a : A) {
            int x = 0;
            for (int i = 0; i < 31; ++i) {
                if ((a >> i & 1) == 0 || cnt[i] % 2 == 0) continue;
                x |= 1 << i;
            }
            ans ^= x;
        }
        return ans;
    }
};
