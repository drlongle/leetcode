/*
count the current number of consecutive "1".
For each new element,
there will be more count substring,
with all characters 1's
*/

class Solution {
public:
    int numSub(string s) {
        int res = 0, count = 0, mod = 1e9 + 7;
        for (char c: s) {
            count = c == '1' ? count + 1 : 0;
            res = (res + count) % mod;
        }
        return res;
    }
};