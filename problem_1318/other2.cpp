class Solution {
public:
    int minFlips(int a, int b, int c) {
        return bitset<30>(~(a|b) &  c).count() + // number of bits to flip to 1
         bitset<30>( a     & ~c).count() + // number of bits to flip to 0 in a
         bitset<30>( b     & ~c).count();  // number of bits to flip to 0 in b
    }
};
