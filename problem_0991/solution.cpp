/*
991. Broken Calculator
Difficulty: Medium

On a broken calculator that has a number showing on its display, we can
perform two operations:

Double: Multiply the number on the display by 2, or;
Decrement: Subtract 1 from the number on the display.
Initially, the calculator is displaying the number X.

Return the minimum number of operations needed to display the number Y.

Example 1:
Input: X = 2, Y = 3
Output: 2
Explanation: Use double operation and then decrement operation {2 -> 4 -> 3}.

Example 2:
Input: X = 5, Y = 8
Output: 2
Explanation: Use decrement and then double {5 -> 4 -> 8}.

Example 3:
Input: X = 3, Y = 10
Output: 3
Explanation:  Use double, decrement and double {3 -> 6 -> 5 -> 10}.

Example 4:
Input: X = 1024, Y = 1
Output: 1023
Explanation: Use decrement operations 1023 times.
 
Note:
1 <= X <= 10^9
1 <= Y <= 10^9
*/

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

class Solution {
public:
    int brokenCalc(int x, int y) {
        if (x >= y)
            return x-y;
        int reduce = 0;
        while ((y & 1) == 0 && y > x) {
            y >>= 1;
            ++reduce;
        }
        if (reduce)
            return reduce + brokenCalc(x, y);
        if (y+1 >= 2*x)
            return 1 + brokenCalc(x, y+1); 
        int res = 1+2*x -y;
        if ((y & 1) == 0) {
            res = min(res, 1 + x-y/2);
        } else {
            res = min(res, 2 + x - (y+1)/2);
        }
        return res;
    }
};

int main(int argc, char** argv) {
    Solution sol;
    int X, Y;
    
    // Expected: 2
    X = 2, Y = 3;
    
    // Expected: 2
    //X = 5, Y = 8;
    
    // Expected: 3
    //X = 3, Y = 10;
    
    // Expected: 1023
    //X = 1024, Y = 1;
    
    // Expected: 39
    X = 1, Y = 1000000000;
    
    cout << "Result: " << sol.brokenCalc(X, Y) << endl;
    
    return 0;
}
