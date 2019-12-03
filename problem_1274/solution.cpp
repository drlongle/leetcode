/*
1274. Number of Ships in a Rectangle
Hard

(This problem is an interactive problem.)

On the sea represented by a cartesian plane, each ship is located at an integer point, and each integer point may contain at most 1 ship.

You have a function Sea.hasShips(topRight, bottomLeft) which takes two points as arguments and returns true if and only if there is at least one ship in the rectangle represented by the two points, including on the boundary.

Given two points, which are the top right and bottom left corners of a rectangle, return the number of ships present in that rectangle.  It is guaranteed that there are at most 10 ships in that rectangle.

Submissions making more than 400 calls to hasShips will be judged Wrong Answer.  Also, any solutions that attempt to circumvent the judge will result in disqualification.

Input: 
ships = [[1,1],[2,2],[3,3],[5,5]], topRight = [4,4], bottomLeft = [0,0]
Output: 3
Explanation: From [0,0] to [4,4] we can count 3 ships within the range.

Constraints:
On the input ships is only given to initialize the map internally. You must solve this problem "blindfolded". In other words, you must find the answer using the given hasShips API, without knowing the ships position.
0 <= bottomLeft[0] <= topRight[0] <= 1000
0 <= bottomLeft[1] <= topRight[1] <= 1000
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

// This is Sea's API interface.

class Sea {
public:
    bool hasShips(vector<int> topRight, vector<int> bottomLeft) {
        return true;
    }
};

class Solution {
public:
    int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
        if (topRight[0] < bottomLeft[0] || topRight[1] < bottomLeft[1] || !sea.hasShips(topRight, bottomLeft))
            return 0;
        if (topRight == bottomLeft)
            return 1;
        vector<int> mid{(topRight[0] + bottomLeft[0]) / 2, (topRight[1]+ bottomLeft[1])/2};
        return countShips(sea, vector<int>{mid[0], mid[1]}, bottomLeft)
                          + countShips(sea, vector<int>{mid[0], topRight[1]}, vector<int>{bottomLeft[0], mid[1]+1})
                          + countShips(sea, vector<int>{topRight[0], mid[1]}, vector<int>{mid[0]+1, bottomLeft[1]})
                          + countShips(sea, topRight, vector<int>{mid[0]+1, mid[1]+1});
    }
};

int main() {
    Solution sol;
    return 0;
}
