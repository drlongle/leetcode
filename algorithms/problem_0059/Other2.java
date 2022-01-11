class Solution {
    public int[][] generateMatrix(int n) {
        int[][] result = new int[n][n];
        int[] c = {n / 2, (n - 1) / 2};
        int print = n * n, dir = (n & 1) == 0 ? 0 : 2;
        result[c[0]][c[1]] = print--;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < (i < n - 1 ? 2 : 3); j++) {
                for (int step = 0; step < i; step++) {
                    move(c, dir);
                    result[c[0]][c[1]] = print--;
                }
                dir = (dir + 1) % 4; // turn
            }
        }
        return result;
    }
    public void move(int[] c, int dir) {
        switch (dir) {
            case 0: c[1]++; break; // right
            case 1: c[0]--; break; // up
            case 2: c[1]--; break; // left
            case 3: c[0]++; break; // down
        }
    }
}
