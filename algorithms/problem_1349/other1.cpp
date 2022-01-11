/*
Explanation
Because the constraint is small (n, m <= 8), and each student only sees the current row and the row before it, it is a good idea to consider memorization searching or DP with bitmap.

In my code, the array f[mask][row] means the maximum number of students that can be placed in the grid
before row (included) when the pattern of students sitting in this row is mask. Then for each (mask, row) pair,
enumerate all valid nmask (valid mask of next row) and update corresponding f[nmask][row+1].

The time complexity is O(n * 2^m * 2^m * m).
*/

class Solution {
    int f[1 << 8][8];  // the student distribution, row
    int n, m;
    vector<vector<char>> seats;
    
    // this bit is on
    bool on(int bit, int mask) {
        return (1 << bit) & mask;
    }
    
    bool checkRowValid(int row, int mask) {
        for (int i = 0; i < m; i++) {
            // if a student is put on a broken chair
            if (on(i, mask) && seats[row][i] == '#') return false;
            // if there is a student on the left of this student
            if (i > 0 && on(i - 1, mask) && on(i, mask)) return false;
            // if there is a student on the right of this student
            if (i < m - 1 && on(i + 1, mask) && on(i, mask)) return false;
        }
        return true;
    }
    
    bool checkTwoRowCollision(int mask, int nmask) {
        for (int i = 0; i < m; i++) {
            // if there is a student on the upper left
            if (i > 0 && on(i, nmask) && on(i - 1, mask)) return false;
            // if there is a student on the upper right
            if (i < m - 1 && on(i, nmask) && on(i + 1, mask)) return false;
        }
        return true;
    }
    
public:
    int maxStudents(vector<vector<char>>& seats) {
        n = seats.size();
        m = seats[0].size();
        memset(f, 0, sizeof(f));
        this->seats = seats;
        int ans = 0;
        
        // initialization
        for (int mask = 0; mask < (1 << m); mask++) {
            if (checkRowValid(0, mask)) {
                f[mask][0] = __builtin_popcount(mask);
                ans = max(ans, f[mask][0]);
            }
        }
        
        for (int row = 0; row < n - 1; row++) {
            for (int mask = 0; mask < (1 << m); mask++) {
                // the current row of students has to be valid
                if (!checkRowValid(row, mask)) continue;
                
                // generate each next row and check correctness
                for (int nmask = 0; nmask < (1 << m); nmask++) {
                    // first it has to be valid
                    if (!checkRowValid(row + 1, nmask))
                        continue;
                    // then it has to not collide with former row
                    if (!checkTwoRowCollision(mask, nmask))
                        continue;

                    f[nmask][row + 1] = max(f[nmask][row + 1], f[mask][row] + __builtin_popcount(nmask));
                    ans = max(ans, f[nmask][row + 1]);
                }
            }
        }
        
        return ans;
    }
};
