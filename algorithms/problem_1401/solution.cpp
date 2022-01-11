/*
1401. Circle and Rectangle Overlapping
Medium

Given a circle represented as (radius, x_center, y_center) and an axis-aligned rectangle represented as (x1, y1, x2, y2), where (x1, y1) are the coordinates of the bottom-left corner, and (x2, y2) are the coordinates of the top-right corner of the rectangle.

Return True if the circle and rectangle are overlapped otherwise return False.

In other words, check if there are any point (xi, yi) such that belongs to the circle and the rectangle at the same time.

Example 1:
Input: radius = 1, x_center = 0, y_center = 0, x1 = 1, y1 = -1, x2 = 3, y2 = 1
Output: true
Explanation: Circle and rectangle share the point (1,0) 

Example 2:
Input: radius = 1, x_center = 0, y_center = 0, x1 = -1, y1 = 0, x2 = 0, y2 = 1
Output: true

Example 3:
Input: radius = 1, x_center = 1, y_center = 1, x1 = -3, y1 = -3, x2 = 3, y2 = 3
Output: true

Example 4:
Input: radius = 1, x_center = 1, y_center = 1, x1 = 1, y1 = -3, x2 = 2, y2 = -1
Output: false

Constraints:
1 <= radius <= 2000
-10^4 <= x_center, y_center, x1, y1, x2, y2 <= 10^4
x1 < x2
y1 < y2
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

#define ll long long
#define ull unsigned long long

class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        if (x_center + radius < x1 || x_center - radius > x2 || y_center + radius < y1 || y_center - radius > y2)
            return false;
        if (x_center >= x1 && x_center <= x2 && y_center >= y1 && y_center <= y2)
            return true;

        double r_square = pow(radius, 2);
        for (auto x: {x1, x2}) {
            vector<double> vect;
            double d = pow(x-x_center, 2);
            vect.push_back(y_center + sqrt(r_square - d));
            vect.push_back(y_center - sqrt(r_square - d));
            for (auto y: vect)
                if (y >= y1 && y <= y2)
                    return true;
        }

        for (auto y: {y1, y2}) {
            vector<double> vect;
            double d = pow(y-y_center, 2);
            vect.push_back(x_center + sqrt(r_square - d));
            vect.push_back(x_center - sqrt(r_square - d));
            for (auto x: vect)
                if (x >= x1 && x <= x2)
                    return true;
        }

        vector<array<int, 2>> points {{x1,y1}, {x1,y2}, {x2,y1}, {x2,y2}};
        for (auto& [x, y]: points) {
            double d = pow((x-x_center), 2) + pow((y-y_center), 2);
            if (d <= r_square)
                return true;
        }
        
        return false;
    }
};

int main() {
    Solution sol;
    int r, xc, yc, x1, y1, x2, y2;

    // Output: true;
    r = 1, xc = 0, yc = 0, x1 = 1, y1 = -1, x2 = 3, y2 = 1;
    cout << boolalpha << sol.checkOverlap(r, xc, yc, x1, y1, x2, y2) << endl;

    // Output: true
    r = 1, xc = 0, yc = 0, x1 = -1, y1 = 0, x2 = 0, y2 = 1;
    cout << boolalpha << sol.checkOverlap(r, xc, yc, x1, y1, x2, y2) << endl;

    // Expected: true
    r = 1, xc = 1, yc = 1, x1 = -3, y1 = -3, x2 = 3, y2 = 3;
    cout << boolalpha << sol.checkOverlap(r, xc, yc, x1, y1, x2, y2) << endl;

    // Output: false
    r = 1, xc = 1, yc = 1, x1 = 1, y1 = -3, x2 = 2, y2 = -1;
    cout << boolalpha << sol.checkOverlap(r, xc, yc, x1, y1, x2, y2) << endl;

    // Output: true
    r = 2, xc = 8, yc = 6, x1 = 5, y1 = 1, x2 = 10, y2 = 4;
    cout << boolalpha << sol.checkOverlap(r, xc, yc, x1, y1, x2, y2) << endl;

    // Output: true
    r = 18, xc = 11, yc = 19, x1 = 7, y1 = 12, x2 = 10, y2 = 20;
    cout << boolalpha << sol.checkOverlap(r, xc, yc, x1, y1, x2, y2) << endl;
        
    return 0;
}
