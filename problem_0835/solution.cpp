/*
835. Image Overlap
Medium

Share
You are given two images img1 and img2 both of size n x n, represented as binary, square matrices of the same size.
(A binary matrix has only 0s and 1s as values.)

We translate one image however we choose (sliding it left, right, up, or down any number of units), and place it on top of the other image.
After, the overlap of this translation is the number of positions that have a 1 in both images.

(Note also that a translation does not include any kind of rotation.)

What is the largest possible overlap?

Example 1:
Input: img1 = [[1,1,0],[0,1,0],[0,1,0]], img2 = [[0,0,0],[0,1,1],[0,0,1]]
Output: 3
Explanation: We slide img1 to right by 1 unit and down by 1 unit.
The number of positions that have a 1 in both images is 3. (Shown in red)

Example 2:
Input: img1 = [[1]], img2 = [[1]]
Output: 1

Example 3:
Input: img1 = [[0]], img2 = [[0]]
Output: 0
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
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int res = 0, n = img1.size();

        for (int ox = -n+1; ox < n; ++ox)
            for (int oy = -n+1; oy < n; ++oy) {
                int cnt1 = 0, cnt2 = 0;
                for (int i = 0; i < n; ++i)
                    for (int j = 0; j < n; ++j) {
                        int ix = i - ox, jy = j - oy;
                        if (ix >= 0 && ix < n && jy >= 0 && jy < n)
                            cnt1 += img1[ix][jy] & img2[i][j];
                        ix = i + ox, jy = j + oy;
                        if (ix >= 0 && ix < n && jy >= 0 && jy < n)
                            cnt2 += img1[ix][jy] & img2[i][j];
                    }
                res = max({res, cnt1, cnt2});
            }

        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> img1, img2;

    // Output: 3
    img1 = {{1,1,0},{0,1,0},{0,1,0}}, img2 = {{0,0,0},{0,1,1},{0,0,1}};
    cout << sol.largestOverlap(img1, img2) << endl;

    // Output: 1
    img1 = {{1}}, img2 = {{1}};
    cout << sol.largestOverlap(img1, img2) << endl;

    // Output: 0
    img1 = {{0}}, img2 = {{0}};
    cout << sol.largestOverlap(img1, img2) << endl;

    return 0;
}
