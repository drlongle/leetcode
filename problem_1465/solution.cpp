/*
1465. Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts
Medium

Given a rectangular cake with height h and width w, and two arrays of integers horizontalCuts and verticalCuts where horizontalCuts[i] is the distance from the top of the rectangular cake to the ith horizontal cut and similarly, verticalCuts[j] is the distance from the left of the rectangular cake to the jth vertical cut.

Return the maximum area of a piece of cake after you cut at each horizontal and vertical position provided in the arrays horizontalCuts and verticalCuts. Since the answer can be a huge number, return this modulo 10^9 + 7.

Example 1:
Input: h = 5, w = 4, horizontalCuts = [1,2,4], verticalCuts = [1,3]
Output: 4 
Explanation: The figure above represents the given rectangular cake. Red lines are the horizontal and vertical cuts. After you cut the cake, the green piece of cake has the maximum area.

Example 2:
Input: h = 5, w = 4, horizontalCuts = [3,1], verticalCuts = [1]
Output: 6
Explanation: The figure above represents the given rectangular cake. Red lines are the horizontal and vertical cuts. After you cut the cake, the green and yellow pieces of cake have the maximum area.

Example 3:
Input: h = 5, w = 4, horizontalCuts = [3], verticalCuts = [3]
Output: 9

Constraints:
2 <= h, w <= 10^9
1 <= horizontalCuts.length < min(h, 10^5)
1 <= verticalCuts.length < min(w, 10^5)
1 <= horizontalCuts[i] < h
1 <= verticalCuts[i] < w
It is guaranteed that all elements in horizontalCuts are distinct.
It is guaranteed that all elements in verticalCuts are distinct.
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
    using ll = long long;
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int hsz = horizontalCuts.size(), vsz = verticalCuts.size();
        sort(begin(horizontalCuts), end(horizontalCuts));
        sort(begin(verticalCuts), end(verticalCuts));
        ll hi = max(horizontalCuts[0], h - horizontalCuts[hsz-1]);
        ll wi = max(verticalCuts[0], w - verticalCuts[vsz-1]);
        for (int i = 0; i < hsz-1; ++i)
            hi = max(hi, (ll) (horizontalCuts[i+1] - horizontalCuts[i]));
        for (int i = 0; i < vsz-1; ++i)
            wi = max(wi, (ll) (verticalCuts[i+1] - verticalCuts[i]));
        return hi * wi % 1000000007;
    }
};

int main() {
    Solution sol;
    int h, w;
    vector<int> horizontalCuts, verticalCuts;

    h = 5, w = 4, horizontalCuts = {1,2,4}, verticalCuts = {1,3};
    //cout << sol.maxArea(h, w, horizontalCuts, verticalCuts) << endl;

    h = 5, w = 4, horizontalCuts = {3,1}, verticalCuts = {1};
    cout << sol.maxArea(h, w, horizontalCuts, verticalCuts) << endl;
    
    return 0;
}
