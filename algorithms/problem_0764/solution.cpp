/*
764. Largest Plus Sign
Medium

In a 2D grid from (0, 0) to (N-1, N-1), every cell contains a 1, except those cells in the given list mines which are 0. What is the largest axis-aligned plus sign of 1s contained in the grid? Return the order of the plus sign. If there is none, return 0.

An "axis-aligned plus sign of 1s of order k" has some center grid[x][y] = 1 along with 4 arms of length k-1 going up, down, left, and right, and made of 1s. This is demonstrated in the diagrams below. Note that there could be 0s or 1s beyond the arms of the plus sign, only the relevant area of the plus sign is checked for 1s.

Examples of Axis-Aligned Plus Signs of Order k:

Order 1:
000
010
000

Order 2:
00000
00100
01110
00100
00000

Order 3:
0000000
0001000
0001000
0111110
0001000
0001000
0000000

Example 1:
Input: N = 5, mines = [[4, 2]]
Output: 2
Explanation:
11111
11111
11111
11111
11011
In the above grid, the largest plus sign can only be order 2.  One of them is marked in bold.

Example 2:
Input: N = 2, mines = []
Output: 1
Explanation:
There is no plus sign of order 2, but there is of order 1.

Example 3:
Input: N = 1, mines = [[0, 0]]
Output: 0
Explanation:
There is no plus sign, so return 0.

Note:
N will be an integer in the range [1, 500].
mines will have length at most 5000.
mines[i] will be length 2 and consist of integers in the range [0, N-1].
(Additionally, programs submitted in C, C++, or C# will be judged with a slightly smaller time limit.)
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <future>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        vector<vector<int>> height(N, vector<int>(N));        
        vector<vector<int>> width(N, vector<int>(N));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                width[i][j] = N - j;
                height[i][j] = N - i;
            }
        }
        
        int res = 0;
        for (auto& mine: mines) {
            int x = mine[0], y = mine[1];
            for (int i = 0; i < N; ++i) {
                if (y >= i)
                    width[x][i] = min(width[x][i], abs(y-i));
                if (x >= i)
                    height[i][y] = min(height[i][y], abs(x-i));
            }
        }

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (height[i][j] == 0)
                    continue;
                int len = 1;
                while (true) {
                    int x = i - len, y = j - len;
                    if (x < 0 || y < 0 || height[x][j] <= 2*len || width[i][y] <= 2*len) {
                        break;
                    }
                    ++len;
                }
                res = max(res, len);
            }
        }
        
        return res;
    }
};

int main() {
    Solution sol;
    int N;
    vector<vector<int>> mines;

    // Output: 2
    N = 5, mines = {{4, 2}};
    cout << sol.orderOfLargestPlusSign(N, mines) << endl;
    
    // Output: 1
    N = 2, mines = {};
    cout << sol.orderOfLargestPlusSign(N, mines) << endl;
    
    // Output: 0
    N = 1, mines = {{0, 0}};
    cout << sol.orderOfLargestPlusSign(N, mines) << endl;

    // Output: 1
    N = 5;
    mines = {{0,1},{0,2},{1,0},{1,2},{1,4},{2,0},{2,2},{3,0},{3,1},{4,0},{4,1},{4,3},{4,4}};
    cout << sol.orderOfLargestPlusSign(N, mines) << endl;

    // Output: 2
    N = 3, mines = {{0,0}};
    cout << sol.orderOfLargestPlusSign(N, mines) << endl;
    
    return 0;
}
