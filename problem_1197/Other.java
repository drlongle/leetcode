/*
This is a famous problem.
The crux of the problem is to notice the patterns that emerge when you draw the board.
The minimum number of moves needed to reach any square

5 4 5 4 5 4 5 6
4 3 4 3 4 5 4
3 4 3 4 3 4
2 3 2 3 4
3 2 3 2
2 1 4
2 3
0

Best part is solution is symmetrical across the axes and the diagonals.

*/

class Solution {
    public int minKnightMoves(int x, int y) {
        // Symmetry for axes
        x = Math.abs(x);
        y = Math.abs(y);
        // Symmetry for diagonal
        if (x < y) {
            int temp = x;
            x = y;
            y = temp;
        }
        if (x == 1 && y == 0) {
            return 3;
        }
        if (x == 2 && y == 2) {
            return 4;
        }
        int delta = x - y;
        if (y > delta) {
            return (int) (delta - 2 * Math.floor((float) (delta - y) / 3));
        } else {
            return (int) (delta - 2 * Math.floor((delta - y) / 4));
        }
    }
}
