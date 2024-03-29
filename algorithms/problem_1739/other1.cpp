class Solution {
  public:
    int minimumBoxes(int n) {
        long long x = 0;
        long long y = 0;
        while ((x + 1) * (x + 2) / 2 < n) {
            x++;
            n -= x * (x + 1) / 2;
        }

        while (n > 0)
            n -= ++y;

        return x * (x + 1) / 2 + y;
    }
};
