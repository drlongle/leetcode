class Solution {
    public int numWays(int n, int k) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return k;
        }
        int last = k * k;
        int secondLast = k;
        for (int i = 3; i <= n; i++) {
            int tmp = (last + secondLast) * (k - 1);
            secondLast = last;
            last = tmp;
        }
        return last;
    }
}
