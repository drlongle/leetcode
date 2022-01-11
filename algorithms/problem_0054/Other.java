class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> result = new ArrayList<>();
        if (matrix.length == 0)
            return result;
        
        int[] c = {0, -1};
        int m = matrix.length - 1, n = matrix[0].length;
        int size = (m + 1) * n, dir = 0;
        while (result.size() < size) {
            for (int move = 0; move < n; move++) {
                move(c, dir);
                result.add(matrix[c[0]][c[1]]);
            }
            n--;
            dir = (dir + 1) % 4;
            for (int move = 0; move < m; move++) {
                move(c, dir);
                result.add(matrix[c[0]][c[1]]);
            }
            m--;
            dir = (dir + 1) % 4;
        }
        return result;
    }
    public void move(int[] c, int dir) {
        switch (dir) {
            case 0: c[1]++; break; // right
            case 1: c[0]++; break; // down
            case 2: c[1]--; break; // left
            case 3: c[0]--; break; // up
        }
    }
}
