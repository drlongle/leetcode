/*
1739. Building Boxes
Hard

You have a cubic storeroom where the width, length, and height of the room are
all equal to n units. You are asked to place n boxes in this room where each box
is a cube of unit side length. There are however some rules to placing the
boxes:
You can place the boxes anywhere on the floor.
If box x is placed on top of the box y, then each side of the four vertical
sides of the box y must either be adjacent to another box or to a wall. Given an
integer n, return the minimum possible number of boxes touching the floor.

Example 1:
Input: n = 3
Output: 3
Explanation: The figure above is for the placement of the three boxes.
These boxes are placed in the corner of the room, where the corner is on the
left side.

Example 2:
Input: n = 4
Output: 3
Explanation: The figure above is for the placement of the four boxes.
These boxes are placed in the corner of the room, where the corner is on the
left side.

Example 3:
Input: n = 10
Output: 6
Explanation: The figure above is for the placement of the ten boxes.
These boxes are placed in the corner of the room, where the corner is on the
back side.

Constraints:
1 <= n <= 10^9
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
    int minimumBoxes(int n) {
        int sum = 0, height = 0, area = 0, res;
        while (sum < n) {
            ++height;
            int prev_area = area;
            int rest = n - sum;
            area += height;
            sum += area;
            if (sum >= n) {
                int extend = 0, fill = 0;
                do {
                    ++fill, ++extend;
                    for (int k = extend; k >= 2; --k) {
                        ++fill;
                    }
                } while (fill < rest);
                res = prev_area + extend;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;

    return 0;
}
