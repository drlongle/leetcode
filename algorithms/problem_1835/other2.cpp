/*
We can observe that (a1 & bi) XOR (a2 & bi) XOR ... XOR (an & bi) is the same as (a1 XOR a2 XOR ... XOR an) & bi.

So, we calculate XOR sum of the first array xa. Then, the final result is
(xa & b1) XOR (xa & b2) XOR ... XOR (xa & bm), resulting in a linear solution.
*/

class Solution {
public:
    int getXORSum(vector<int>& a, vector<int>& b) {
        int res = 0, xa = accumulate(begin(a), end(a), 0, bit_xor());
        for (auto n : b)
            res = res ^ (xa & n);
        return res;
    }
};
