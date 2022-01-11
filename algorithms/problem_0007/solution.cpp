/*
7. Reverse Integer

Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321 
*/

#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <climits>
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
#include <vector>

#include <string.h>

using namespace std;

class Solution {
public:

    int reverse(int x) {
        double result = 0; 
        bool negative = false;
        if (x < 0) {
            x = -x;
            negative = true;
        }

        while(x) {
            result = result*10 + (x%10);
            x /= 10;
        }

        if (negative) result = -result;
        if (result < numeric_limits<int>::min() ||
            result > numeric_limits<int>::max()) return 0;
        return static_cast<int>(result);
    }
};

int main()
{
    Solution sol;
    int input;

    input = 123;
    input = 1534236469;
    cout << "Reverse: " << sol.reverse(input);

    return 0;
}
