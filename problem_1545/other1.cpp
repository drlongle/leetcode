/*
The length of the string len is 2^n - 1.

If k - 1 == len / 2, then this is the middle of the string, return 1 unless n == 1.

If k - 1 < len / 2, this is at the left part of Sn, which is the same as findKthBit(n - 1, k).

If k - 1 > len / 2, this is the i = k - (len / 2 + 1) - 1-th bit in the right part,
which is the invert of findKthBit(n - 1, len / 2 - i).
*/

class Solution {
public:
    char findKthBit(int n, int k) {
        if (n == 1) return '0';
        int len = pow(2, n) - 1;
        if (k - 1 == len / 2) return '1';
        if (k - 1 < len / 2) return findKthBit(n - 1, k);
        int i = k - (len / 2 + 1) - 1;
        return findKthBit(n - 1, len / 2 - i) == '0' ? '1' : '0';
    }
};
