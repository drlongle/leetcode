/*
735. Asteroid Collision
Medium

We are given an array asteroids of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode.
If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

Example 1:
Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10.  The 5 and 10 never collide.

Example 2:
Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.

Example 3:
Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.

Example 4:
Input: asteroids = [-2,-1,1,2]
Output: [-2,-1,1,2]
Explanation: The -2 and -1 are moving left, while the 1 and 2 are moving right. Asteroids moving the same
direction never meet, so no asteroids will meet each other.

Constraints:
1 <= asteroids <= 104
-1000 <= asteroids[i] <= 1000
asteroids[i] != 0
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

    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;

        for (int n: asteroids) {
            if (res.empty() || n > 0) {
                res.emplace_back(n);
                continue;
            }
            bool deleted = false;
            while (res.size() && res.back() > 0 && !deleted) {
                int diff = res.back() - abs(n);
                if (diff <= 0)
                    res.pop_back();
                deleted = (diff >= 0);
            }
            if (!deleted)
                res.emplace_back(n);
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> asteroids;

    // Output: {5,10}
    asteroids = {5,10,-5};
    asteroids = sol.asteroidCollision(asteroids);
    copy(begin(asteroids), end(asteroids), ostream_iterator<int>(cout, ", "));
    cout << endl;

    // Output: {5,10}
    asteroids = {5,10,2,3,-5};
    asteroids = sol.asteroidCollision(asteroids);
    copy(begin(asteroids), end(asteroids), ostream_iterator<int>(cout, ", "));
    cout << endl;

    // Output: {}
    asteroids = {8,-8};
    asteroids = sol.asteroidCollision(asteroids);
    copy(begin(asteroids), end(asteroids), ostream_iterator<int>(cout, ", "));
    cout << endl;

    // Output: {10}
    asteroids = {10,2,-5};
    asteroids = sol.asteroidCollision(asteroids);
    copy(begin(asteroids), end(asteroids), ostream_iterator<int>(cout, ", "));
    cout << endl;

    // Output: {-2,-1,1,2}
    asteroids = {-2,-1,1,2};
    asteroids = sol.asteroidCollision(asteroids);
    copy(begin(asteroids), end(asteroids), ostream_iterator<int>(cout, ", "));
    cout << endl;

    // Output: [-2,-2,2]
    asteroids = {-2,1,-2,2};
    asteroids = sol.asteroidCollision(asteroids);
    copy(begin(asteroids), end(asteroids), ostream_iterator<int>(cout, ", "));
    cout << endl;

    return 0;
}
