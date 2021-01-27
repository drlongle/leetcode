class Solution {
public:
    int concatenatedBinary(int n) {
        const int MOD = 1000000007;
        int length = 0;   // bit length of addends
        long result = 0;  // long accumulator
        for (int i = 1; i <= n; i++) {
            // when meets power of 2, increase the bit length
            if (ceil(log2(i)) == floor(log2(i))) {
                length++;
            }
            result = ((result * (int)pow(2, length)) + i) % MOD;
        }
        return result;
    }
};