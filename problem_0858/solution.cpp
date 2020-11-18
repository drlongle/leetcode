/*
858. Mirror Reflection
Medium

There is a special square room with mirrors on each of the four walls. Except for the
southwest corner, there are receptors on each of the remaining corners, numbered 0, 1, and 2.

The square room has walls of length p, and a laser ray from the southwest corner first meets the
east wall at a distance q from the 0th receptor.

Return the number of the receptor that the ray meets first.  (It is guaranteed that the ray will
meet a receptor eventually.)

Example 1:
Input: p = 2, q = 1
Output: 2
Explanation: The ray meets receptor 2 the first time it gets reflected back to the left wall.

Note:
1 <= p <= 1000
0 <= q <= p
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

#include "common/TreeNode.h"

using namespace std;

/*
This problem can be transformed into finding m * p = n * q, where
m = the number of room extension + 1.
n = the number of light reflection + 1.

If the number of light reflection is odd (which means n is even), it means the corner
is on the left-hand side. The possible corner is 2.
Otherwise, the corner is on the right-hand side. The possible corners are 0 and 1.
Given the corner is on the right-hand side.
If the number of room extension is even (which means m is odd), it means the corner is 1.
Otherwise, the corner is 0.

So, we can conclude:

m is even & n is odd => return 0.
m is odd & n is odd => return 1.
m is odd & n is even => return 2.
Note: The case m is even & n is even is impossible. Because in the equation m * q = n * p,
if m and n are even, we can divide both m and n by 2. Then, m or n must be odd.
*/

class Solution {
public:
    int mirrorReflection(int p, int q) {
        int m = 1; // extension count of room
        int n = 1; // reflection count of laser ray
        while(m * p != n * q){
            n++;
            m = n * q / p;
        }
        if (m % 2 == 0 && n % 2 == 1) return 0;
        if (m % 2 == 1 && n % 2 == 1) return 1;
        if (n % 2 == 0) return 2;
        return -1;
    }
};

int main() {
    Solution sol;

    return 0;
}
