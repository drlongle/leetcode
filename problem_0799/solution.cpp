/*
799. Champagne Tower
Medium

We stack glasses in a pyramid, where the first row has 1 glass, the second row has 2 glasses, and so on until
the 100th row.  Each glass holds one cup (250ml) of champagne.

Then, some champagne is poured in the first glass at the top.  When the topmost glass is full, any excess liquid
poured will fall equally to the glass immediately to the left and right of it.  When those glasses become full,
any excess champagne will fall equally to the left and right of those glasses, and so on. (A glass at the bottom
row has its excess champagne fall on the floor.)

For example, after one cup of champagne is poured, the top most glass is full. After two cups of champagne are
poured, the two glasses on the second row are half full.  After three cups of champagne are poured, those two
cups become full - there are 3 full glasses total now.  After four cups of champagne are poured, the third row
has the middle glass half full, and the two outside glasses are a quarter full, as pictured below.

Now after pouring some non-negative integer cups of champagne, return how full the jth glass in the ith row is
(both i and j are 0-indexed.)

Example 1:
Input: poured = 1, query_row = 1, query_glass = 1
Output: 0.00000
Explanation: We poured 1 cup of champange to the top glass of the tower (which is indexed as (0, 0)).
There will be no excess liquid so all the glasses under the top glass will remain empty.

Example 2:
Input: poured = 2, query_row = 1, query_glass = 1
Output: 0.50000
Explanation: We poured 2 cups of champange to the top glass of the tower (which is indexed as (0, 0)).
There is one cup of excess liquid. The glass indexed as (1, 0) and the glass indexed as (1, 1) will share
the excess liquid equally, and each will get half cup of champange.

Example 3:
Input: poured = 100000009, query_row = 33, query_glass = 17
Output: 1.00000

Constraints:
0 <= poured <= 109
0 <= query_glass <= query_row < 100
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <future>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    static constexpr int max_rows = 100;
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> glass(max_rows+1, vector<double>(max_rows+1, 0.0));

        glass[0][0] = poured;
        for (int level = 0; level <= query_row; ++level) {
            for (int j = 0; j <= level; ++j) {
                double excess = glass[level][j] - 1.0;
                if (excess >= 0) {
                    glass[level][j] = 1.0;
                    glass[level+1][j] += excess / 2;
                    glass[level+1][j+1] += excess / 2;
                }
            }
        }

        return glass[query_row][query_glass];
    }
};

int main() {
    Solution sol;
    int poured, query_row, query_glass;

    // Output: 0.00000
    poured = 1, query_row = 1, query_glass = 1;
    cout << sol.champagneTower(poured, query_row, query_glass) << endl;

    // Output: 0.50000
    poured = 2, query_row = 1, query_glass = 1;
    cout << sol.champagneTower(poured, query_row, query_glass) << endl;

    // Output: 1.00000
    poured = 100000009, query_row = 33, query_glass = 17;
    cout << sol.champagneTower(poured, query_row, query_glass) << endl;

    // 0.18750
    poured = 25, query_row = 6, query_glass = 1;
    cout << sol.champagneTower(poured, query_row, query_glass) << endl;

    // 0.00000
    poured = 1000000000, query_row = 99, query_glass = 99;
    cout << sol.champagneTower(poured, query_row, query_glass) << endl;

    return 0;
}
