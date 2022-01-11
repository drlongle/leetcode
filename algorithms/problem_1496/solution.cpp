/*
1496. Path Crossing
Easy

Given a string path, where path[i] = 'N', 'S', 'E' or 'W', each representing moving one unit
north, south, east, or west, respectively. You start at the origin (0, 0) on a 2D plane and walk on the path specified by path.
Return True if the path crosses itself at any point, that is, if at any time you are
on a location you've previously visited. Return False otherwise.

Example 1:
Input: path = "NES"
Output: false 
Explanation: Notice that the path doesn't cross any point more than once.

Example 2:
Input: path = "NESWW"
Output: true
Explanation: Notice that the path visits the origin twice.

Constraints:
1 <= path.length <= 10^4
path will only consist of characters in {'N', 'S', 'E', 'W}
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
    static constexpr int MULT = 100000;
    bool isPathCrossing(string path) {
        int x = 0, y = 0;
        unordered_set<int> cached;
        cache.emplace(x*MULT + y);
        for (char ch: path) {
            switch(ch) {
                case 'N':
                    ++y;
                    break;
                case 'S':
                    --y;
                    break;
                case 'E':
                    ++x;
                    break;
                case 'W':
                    --x;
                    break;
                default:
                    break;
            }
            auto [inserted, it] = cached.emplace(x*MULT + y);
            if (inserted)
                return true;
        }
        return false;
    }
};

int main() {
    Solution sol;
    return 0;
}
