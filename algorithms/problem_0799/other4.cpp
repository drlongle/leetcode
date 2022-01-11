class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {

        double t[101][101] = {0};
        t[0][0] = poured;
        for( int i = 0 ; i <= query_row; i++ ) {
            for( int j = 0 ; j <= i ; j++ ) {
                double flow = max( t[i][j] - 1, 0.0 );
                t[i][j] -= flow;
                flow /= 2.0;
                t[i+1][j] += flow;
                t[i+1][j+1] += flow;
            }
        }
        return t[query_row][query_glass];
    }
};
