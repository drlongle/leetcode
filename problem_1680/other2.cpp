class Solution {
public:
    static const int MOD = 1e9 + 7;

    int concatenatedBinary(int n) {
        int count = 0;
        int result = 0;
        int val = 1;
        for(int i = n;i>=1;i--){
            int x = i;
            while(x){
                result = ((result) + ((x & 1)*val)) % MOD ;
                x >>= 1;
                val = (val * 2) % MOD;
            }
        }
        return result;
    }
};
