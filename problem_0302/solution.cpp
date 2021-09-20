/*
302. Smallest Rectangle Enclosing Black Pixels
Hard

You are given an image that is represented by a binary matrix with 0 as a white pixel and 1 as a black pixel.

The black pixels are connected (i.e., there is only one black region). Pixels are connected horizontally and vertically.

Given two integers x and y that represent the location of one of the black pixels, return the area of
the smallest (axis-aligned) rectangle that encloses all black pixels.

Example 1:
Input: image = [["0","0","1","0"],["0","1","1","0"],["0","1","0","0"]], x = 0, y = 2
Output: 6

Example 2:
Input: image = [["1"]], x = 0, y = 0
Output: 1

Constraints:
m == image.length
n == image[i].length
1 <= m, n <= 100
image[i][j] is either '0' or '1'.
1 <= x < m
1 <= y < n
image[x][y] == '1'.
The black pixels in the image only form one component.
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <climits>
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

#include "common/ListNode.h"
#include "common/Node.h"
#include "common/TreeNode.h"

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        queue<pair<int,int>> q;
        q.emplace(x, y);
        image[x][y] = '.';
        int mx = x, Mx = x, my = y, My = y, m = image.size(), n = image[0].size();
        vector<vector<int>> offsets{{1,0}, {-1,0}, {0,1}, {0,-1}};
        while (q.size()) {
            auto [i,j] = q.front();
            q.pop();
            for (auto& offset: offsets) {
                int ni = i + offset[0], nj = j + offset[1];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && image[ni][nj] == '1') {
                    image[ni][nj] = '.';
                    mx = min(mx, ni);
                    Mx = max(Mx, ni);
                    my = min(my, nj);
                    My = max(My, nj);
                    q.emplace(ni, nj);
                }
            }
        }

        return (Mx - mx + 1) * (My - my + 1);
    }
};

int main() {
    Solution sol;

    return 0;
}
