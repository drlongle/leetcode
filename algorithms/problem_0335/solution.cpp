/*
335. Self Crossing  
Total Accepted: 4913 Total Submissions: 26116 Difficulty: Hard

You are given an array x of n positive numbers. You start at point (0,0) and moves x[0] metres to the north, then x[1] metres to the west, x[2] metres to the south, x[3] metres to the east and so on. In other words, after each move your direction changes counter-clockwise.

Write a one-pass algorithm with O(1) extra space to determine, if your path crosses itself, or not.

Example 1:

Given x = [2, 1, 1, 2],
Return true (self crossing)

Example 2:
Given x = [1, 2, 3, 4],
Return false (not self crossing)

Example 3:
Given x = [1, 1, 1, 1],
Return true (self crossing)

*/

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <functional>
#include <iostream>
#include <sstream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;



class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        for (size_t i = 3; i < x.size(); ++i) {
            if ((x[i] >= x[i-2] && x[i-1] <= x[i-3]) ||
                (i >= 4 && x[i] + x[i-4] >= x[i-2] && x[i-1] == x[i-3]) ||
                (i >= 5 && x[i] + x[i-4] >= x[i-2] && x[i-2] > max(x[i-4], x[i])
	             && x[i-1] + x[i-5] >= x[i-3] && x[i-3] > max(x[i-5], x[i-1]))
	    )
                return true;
        }

        return false;
    }
};

int main()
{
    Solution sol;
    vector<int> x;
    vector<pair<vector<int>, bool>> params { { {2, 1, 1, 2}, true} , 
	{ {1, 2, 3, 4}, false }, { {1, 1, 1, 1}, true },
	{ {1,1,2,1,1}, true }, { {1,1,2,2,1,1}, true },
        { {2,2,3,3,2,2}, true}, { {3,3,3,2,1,1}, false },
        { {1,1,2,2,3,3,4,4,10,4,4,3,3,2,2,1,1}, false }
    };

    //Expected: true
    x = {2, 1, 1, 2};

    //Expected: false
    x = {1, 2, 3, 4};

    //Expected: true
    x = {1, 1, 1, 1};

    // 19 / 29 test cases passed
    // Expected: true
    x = {3,3,4,2,2};

    // 22 / 29 test cases passed
    // Expected: false
    x = {3,3,3,2,1,1};

    // 24 / 29 test cases passed
    // Expected: true
    // x = {1,1,2,1,1};

    // 25 / 29 test cases passed
    // Expected: true
    //x = {1,1,2,2,1,1};

    // 25 / 29 test cases passed
    // Expected: false
    x = {1,1,2,2,3,3,4,4,10,4,4,3,3,2,2,1,1};

    // 28 / 29 test cases passed
    // Expected: true
    //x = {2,2,3,3,2,2};

    cout << boolalpha << "Result: " << sol.isSelfCrossing(x) << endl;

    for (auto& param: params)
	if (sol.isSelfCrossing(param.first) != param.second) {
	    copy(begin(param.first), end(param.first), ostream_iterator<int>(cout, ", "));
	    cout << endl;
        }
    return 0;
}

