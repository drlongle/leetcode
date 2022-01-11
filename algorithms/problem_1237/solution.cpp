/*
1237. Find Positive Integer Solution for a Given Equation

Given a function  f(x, y) and a value z, return all positive integer pairs x and y where f(x,y) == z.

The function is constantly increasing, i.e.:

f(x, y) < f(x + 1, y)
f(x, y) < f(x, y + 1)
The function interface is defined like this: 

interface CustomFunction {
public:
  // Returns positive integer f(x, y) for any given positive integer x and y.
  int f(int x, int y);
};

For custom testing purposes you're given an integer function_id and a target z as input, where function_id represent one function from an secret internal list, on the examples you'll know only two functions from the list.  

You may return the solutions in any order.

Example 1:
Input: function_id = 1, z = 5
Output: [[1,4],[2,3],[3,2],[4,1]]
Explanation: function_id = 1 means that f(x, y) = x + y

Example 2:
Input: function_id = 2, z = 5
Output: [[1,5],[5,1]]
Explanation: function_id = 2 means that f(x, y) = x * y

Constraints:

1 <= function_id <= 9
1 <= z <= 100
It's guaranteed that the solutions of f(x, y) == z will be on the range 1 <= x, y <= 1000
It's also guaranteed that f(x, y) will fit in 32 bit signed integer if 1 <= x, y <= 1000
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

class  CustomFunction {
public:
  // Returns positive integer f(x, y) for any given positive integer x and y.
    int f(int x, int y) {
        return 0;
    }
};


class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& func, int z) {
        vector<vector<int>> res;
        set<int> found_y;
        for (int x = 1; x <= 1000; ++x) {
            int left = 1, right = 1000;
            while (left < right) {
                int mid = (left + right) / 2;
                int mf = func.f(x, mid);
                if (mf == z) {
                    left = mid;
                    break;
                }
                if (mf > z)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            if (left <= 1000 && func.f(x, left) == z) {
                res.emplace_back(vector<int>{x, left});
                found_y.emplace(left);
            } else if (right >= 1 && func.f(x, right) == z) {
                res.emplace_back(vector<int>{x, right});
                found_y.emplace(right);
            }
        }

        for (int y = 1; y <= 1000; ++y) {
            if (found_y.count(y))
                continue;
            int left = 1, right = 1000;
            while (left < right) {
                int mid = (left + right) / 2;
                int mf = func.f(mid, y);
                if (mf == z) {
                    res.emplace_back(vector<int>{mid, y});
                    break;
                }
                if (mf > z)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            if (left <= 1000 && func.f(left, y) == z)
                res.emplace_back(vector<int>{left, y});
            else if (right >= 1 && func.f(right, y) == z)
                res.emplace_back(vector<int>{right, y});
        }
        
        return res;
    }
};

int main() {
    return 0;
}
