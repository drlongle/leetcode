class Solution {
  public:
    int minimumBoxes(int n) {
        int sum = 0;
        int levelI;
        int i;
        for (i = 1; i <= n; i++) {
            levelI = i * (i + 1) / 2;
            sum += levelI;
            if (sum >= n)
                break;
        }
        while (sum - i >= n) {
            levelI--;
            sum -= i;
            i--;
        }
        return levelI;
    }
};
