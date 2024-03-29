class Solution {
  public:
    int minimumBoxes(long long n) {
        // solve the equation: find max x that x * (x + 1) * (x + 2) / 6 <= n;
        int row = cbrt(n * 6);
        int remain = n - rowFormula(row);
        if (remain < 0)
            remain = n - rowFormula(--row);
        // solve the equation: find min x that x * (x + 1) / 2 >= n;
        int col = sqrt(remain * 2);
        if (colFormula(col) < remain)
            col++;
        return colFormula(row) + col;
    }

  private:
    inline int colFormula(long long n) { return n * (n + 1) / 2; }
    inline int rowFormula(long long n) {
        // simplify (n * (n + 1) * (2*n + 1) / 6 + n * (n + 1) / 2) / 2;
        return n * (n + 1) * (n + 2) / 6;
    }
};
