/*
Explanation
If k is on the left part of the string, we do nothing.
If K is right in the middle, we return flip directly.
If k is on the right part of the string, find its symmetric position k = l + 1 - k.
Also we toggle flip ^= 1
 */

class Solution {
public:
    char findKthBit(int n, int k) {
        int flip = 0, l = (1 << n) - 1;
        while (k > 1) {
            if (k == l / 2 + 1)
                return '0' + (flip ^ 1);
            if (k > l / 2) {
                k = l + 1 - k;
                flip ^= 1;
            l /= 2;
        }
        return '0' + flip;
    }
};