class Solution {
public:
  int countPrimeSetBits(int L, int R) {
    int ans = 0;
    // magic number is 2<<2 + 2<<3 + 2<<5 + 2<<7 + ... + 2<<31
    unsigned magic = 2693408941;
    for (int n = L; n <= R; ++n)
      if (magic & (1 << __builtin_popcountll(n))) ++ans;
    return ans;
  }
};
