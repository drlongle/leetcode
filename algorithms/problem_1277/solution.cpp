/*
1277. Count Square Submatrices with All Ones
Medium

Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

Example 1:
Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.

Example 2:
Input: matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation: 
There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.

Constraints:

1 <= arr.length <= 300
1 <= arr[0].length <= 300
0 <= arr[i][j] <= 1
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
    int countSquares(vector<vector<int>>& matrix) {
        map<pair<int, int>, set<int>> rects;
        vector<vector<int>> offsets{{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
        int m = matrix.size();
        int n = matrix[0].size();
        int res = 0;

        vector<vector<int>> cache(m, vector<int>(n, 0));
        for (int i = m-1; i >= 0; --i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0)
                    continue;
                cache[i][j] = 1 + ((i < m-1) ? cache[i+1][j] : 0);
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0)
                    continue;
                int size = 1;
                ++res;
                while (true) {
                    int count = 0;
                    ++size;
                    for (auto& offset: offsets) {
                        vector<int> other{i + (size-1)*offset[0], j + (size-1)*offset[1]};
                        if (other[0] >= 0 && other[0] < m && other[1] >= 0 && other[1] < n) {
                            vector<int> point{min(i, other[0]), min(j, other[1])};
                            bool valid = true;
                            for (int s = 0; valid && s < size; ++s) {
                                if (cache[point[0]][point[1] + s] < size)
                                    valid = false;
                            }
                            if (valid) {
                                ++count;
                                rects[{point[0], point[1]}].emplace(size);
                            }
                        }
                    }
                    if (count == 0)
                        break;
                }
            }
        }

        for (auto& point: rects) {
            for (auto& s: point.second) {
                cout << point.first.first << ", " << point.first.second << ", " << s << endl;
            }
            res += point.second.size();
        }

        return res;
    }
};

int main() {
    Solution sol;
    return 0;
}
