/*
Ideas of the solution are very simple:

1. Maximum plus order in the point (i,j) is a distance to the nearest zero or border (in left, right, up down directions). mn[i * N + j] is an array of minimum distances.
2. The array should be filled (points should be checked) from a center to borders. There is no reason to check other points if the plus point in the center.
3. Line filling goes in vertical and horizontal directions. When mines appear the distance fall down to zero, otherwise it is increasing. To make the filling faster, the reverse filling called in main loop and it goes back half way.
4. Some special cases like empty mines etc treat in a special way before the main algorithm.
*/

class Solution {
    std::vector<int16_t> mn;
    int N;  
    inline void fill_i_line(int i) {
        int16_t dist = 0;
        for(int j = 0; j < N; j++) {
            int inx = i * N + j;  
            auto &x = mn[inx];   
            if( x == 0 ) {
                for(int k = 1; k < dist / 2 + 1; k++) {
                    auto &y = mn[inx - k];   
                    y = min<int16_t>(y, k);
                }
                dist = 0;
            } else
                x = min(x, ++dist);  
        }
        for(int k = 1; k < dist / 2 + 1; k++) {
            auto &y = mn[i * N + N - k];   
            y = min<int16_t>(y, k);
        }
    }
    
    inline void fill_j_line(int j) {
        int16_t dist = 0;
        for(int i = 0; i < N; i++) {
            int inx = i * N + j;  
            auto &x = mn[inx];   
            if( x == 0 ) {
                for(int k = 1; k < dist / 2 + 1; k++) {
                    auto &y = mn[inx - k * N];   
                    y = min<int16_t>(y, k);
                }
                dist = 0;
            } else
                x = min(x, ++dist);  
        }
        for(int k = 1; k < dist / 2 + 1; k++) {
            auto &y = mn[N * (N - k) + j];   
            y = min<int16_t>(y, k);
        }
    }

public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        if( N == 0 || N * N == mines.size() )
            return 0;
        if( N * N - mines.size() < 5)
            return 1;
        if( mines.size() == 0) {
            return (N + 1) / 2;  
        }
        this->N = N;
        mn.resize(N * N, 32767);
        for(const auto &x : mines) {
            mn[N * x[0] + x[1]] = 0; 
        }
        int16_t result = 0;  
        for(int l = N / 2; l >= 0; l--) {
            if( result >= l + 1 )
                break;
            fill_i_line(l);
            fill_j_line(l);
            int dl = N - l - 1;   
            if( l < dl ) {
                fill_i_line(dl);
                fill_j_line(dl);
            }
            for(int k = l; k < N - l; k++) {
                result = max({result, mn[N * l + k], mn[N * dl + k], mn[N * k + l], mn[N * k + dl]});  
                if( result >= l + 1 )
                    break;     
            }
        }
        return result;
    }
};
