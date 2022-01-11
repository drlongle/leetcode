class Solution {
    public int numWays(int n, int k) {
        if (n == 0) {
            return 0;
        }
        int same = 0;
        int different = k;
        for (int i = 2; i <= n; i++) {
            int tmp = same;
            same = different;
            different = (tmp + different) * (k - 1);
        }
        return same + different;
    }
}
