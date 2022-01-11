/*
Intuition
  Think in backward way,
  for each number a in A,
  if a % 2 == 1, we do operation 0 backward, turning 1 to 0.
  If all a % 2 == 0, we do operation 1 backward.

Some observation here:
  For each bit "1" in the bianry format of a, we need at least one operation 0.
  All operation 1 can be shared.

Explanation
For each number a,
we count the number of bits "1",
as well as the length of a in binary format.

The number of operation 0 equals to the total number of bits "1".
The number of operation 1 equals to maximum bit length - 1.
 */

class Solution {
public:
    int minOperations(vector<int>& A) {
        int res = 0, maxLen = 1;
        for (int a : A) {
            int bits = 0;
            while (a > 0) {
                res += a & 1;
                bits++;
                a >>= 1;
            }
            maxLen = max(maxLen, bits);
        }
        return res + maxLen - 1;
    }
};