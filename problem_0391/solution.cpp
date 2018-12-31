/*
391. Perfect Rectangle
Difficulty: Hard

Given N axis-aligned rectangles where N > 0, determine if they all together
form an exact cover of a rectangular region.

Each rectangle is represented as a bottom-left point and a top-right point. For
example, a unit square is represented as [1,1,2,2]. (coordinate of bottom-left
point is (1, 1) and top-right point is (2, 2)).

Example 1:
rectangles = [
  [1,1,3,3],
  [3,1,4,2],
  [3,2,4,4],
  [1,3,2,4],
  [2,3,3,4]
]
Return true. All 5 rectangles together form an exact cover of a rectangular
region.

Example 2:
rectangles = [
  [1,1,2,3],
  [1,3,2,4],
  [3,1,4,2],
  [3,2,4,4]
]
Return false. Because there is a gap between the two rectangular regions.

Example 3:
rectangles = [
  [1,1,3,3],
  [3,1,4,2],
  [1,3,2,4],
  [3,2,4,4]
]
Return false. Because there is a gap in the top center.

Example 4:
rectangles = [
  [1,1,3,3],
  [3,1,4,2],
  [1,3,2,4],
  [2,2,4,4]
]
Return false. Because two of the rectangles overlap with each other.

*/

#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <set>
#include <unordered_set>
#include <vector>

using namespace std;

/*
The right answer must satisfy two conditions:
1. the large rectangle area should be equal to the sum of small rectangles
2. count of all the points should be even, and that of all the four corner
points should be one

Proof to condition 1 is straightforward so I will focus on condition 2. First by
observation we know it holds true for a perfect rectangle (consider how many
small rectangles can overlap at a particular point: the number has to be even
except for the four corner points of the prefect rectangle). The real question
is whether it can also be true for some non-perfect rectangle.

Let's begin with the question: what will a non-perfect rectangle look like? Of
course it can look rather complicated but here is a simple way to define it: any
non-perfect rectangle can be obtained by a sequence of adding or removing
rectangular parts from its perfect counterpart (the order for adding or removing
does not matter here). If condition 1 is held true, the non-perfect rectangle
must be built by both adding and removing small rectangles such that the total
area of added rectangles compensates for those of removed.

Without loss of generality, let's focus on the first rectangle (denoted as FR)
that is being removed (i.e., we have perfect rectangle before removing it). FR
has four corner points. Before removing it, each corner points will appear even
times (here I assume FR does not contain any corner points of the perfect
rectangle. See my comment below for more details). After it's gone, all the four
corner points will appear odd times. To make condition 2 valid again, for each
of these four points, we have to either add or remove a rectangle such that each
of them will once again appear even times. The key here is that the total number
of rectangles added or removed is at least two, since the added or removed
rectangles cannot overlap with FR, therefore each added or removed rectangle can
contain at most two of the four corner points of FR.

So we end up with at least two extra rectangles (either added or removed), with
a total of eight corner points. Four of those points coincide with the four
corner points of FR. What about the other four points? For each of these points,
if it belongs to a rectangle that is being removed, then before removing, it
must appear even times and after removing, it will appear odd times. If it
belongs to a rectangle that is being added, no matter it coincides with any
point in the perfect rectangle or not, its number of appearance will always be
odd (appear once if does not coincide with any point, odd if it does since the
original number of appearance before adding is even). In either case (adding or
removing rectangle), there is no way to keep the number of appearance of all
points even, therefore condition 2 cannot be true for non-perfect rectangles.
*/

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        set<pair<int,int>> points;
        vector<pair<int,int>> corners;
        long long area = 0;
        int low = numeric_limits<int>::max();
        int left = numeric_limits<int>::max();
        int high = numeric_limits<int>::min();
        int right = numeric_limits<int>::min();
        for (const auto& rect: rectangles) {
            area += (rect[2] - rect[0]) * (rect[3] - rect[1]);
            low = min(low, rect[0]);
            left = min(left, rect[1]);
            high = max(high, rect[2]);
            right = max(right, rect[3]);
            
            corners.resize(0);
            corners.emplace_back(rect[0], rect[1]);
            corners.emplace_back(rect[0], rect[3]);
            corners.emplace_back(rect[2], rect[1]);
            corners.emplace_back(rect[2], rect[3]);
            for (const auto& c: corners) {
                if (points.count(c))
                    points.erase(c);
                else
                    points.emplace(c);
            }   
        }
        if (!points.count(make_pair(low, left))
                || !points.count(make_pair(low, right))
                || !points.count(make_pair(high, left))
                || !points.count(make_pair(high, right)) || points.size() != 4)
            return false;
        return area == (high - low) * (right - left);
    }
};

int main(int argc, char** argv) {
    Solution sol;
    vector<vector<int>> rectangles;

    // Expected: true
    rectangles = {{1,1,3,3}, {3,1,4,2}, {3,2,4,4}, {1,3,2,4}, {2,3,3,4} };

    // Expected: false
    rectangles = { {1,1,2,3}, {1,3,2,4}, {3,1,4,2}, {3,2,4,4} };

    // Expected: false
    //rectangles = { {1,1,3,3}, {3,1,4,2}, {1,3,2,4}, {3,2,4,4} };

    // Expected: false
    //rectangles = { {1,1,3,3}, {3,1,4,2}, {1,3,2,4}, {2,2,4,4} };

    // 31 / 46 test cases passed.
    // Expected: false
    //rectangles = {{0,0,1,1},{0,1,3,2},{1,0,2,2}};

    // 33 / 46 test cases passed.
    // Expected: true
    //rectangles = {{1,1,3,3},{3,1,4,2},{3,2,4,4},{1,3,2,4},{2,3,3,4}};

    // 35 / 46 test cases passed.
    // Expected: true
    //rectangles = {{0,0,4,1},{7,0,8,2},{6,2,8,3},{5,1,6,3},{4,0,5,1},{6,0,7,2},{4,2,5,3},{2,1,4,3},{0,1,2,2},{0,2,2,3},{4,1,5,2},{5,0,6,1}};

    // 37 / 46 test cases passed.
    // Expected: false
    //rectangles = {{0,0,2,2},{1,1,3,3},{2,0,3,1},{0,3,3,4}};
    
    // 39 / 46 test cases passed.
    // Expected: false
    //rectangles = {{0,0,3,1},{0,1,2,3},{1,0,2,1},{2,2,3,3}};

    // 39 / 46 test cases passed.
    // Expected: false
    rectangles = {{1,1,2,2},{0,1,1,2},{1,0,2,1},{0,2,3,3},{2,0,3,3}};
    
    // 40 / 46 test cases passed.
    // Expected: false
    //rectangles = {{0,0,1,1},{0,0,1,1},{0,2,1,3}};

    // 43 / 46 test cases passed.
    // Expected: false
    rectangles = {{0,0,3,1},{0,1,2,3},{2,0,3,1},{2,2,3,3}};

    cout << "Result: " << boolalpha << sol.isRectangleCover(rectangles) << endl;

    return 0;
}
