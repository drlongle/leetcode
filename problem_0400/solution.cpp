/*
400. Nth Digit

Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...

Note:
n is positive and will fit within the range of a 32-bit signed integer (n < 2^31).

Example 1:

Input:
3

Output:
3
Example 2:

Input:
11

Output:
0

Explanation:
The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0,
which is part of the number 10.

*/

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <functional>
#include <iomanip>
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
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        ll start_number = 1;
        ll digits = 1;
        ll range = 9;

        if (n < 10)
            return n;

        while (true) {
            if ((ll) n < range * digits) {
                ll index = n / digits;
                ll remain = n % digits;
                ll num = start_number + index - (remain == 0 ? 1 : 0);
                string s = to_string(num);
                return (remain == 0 ? s.back() : s[remain-1]) - '0';
            } else {
                n -= range * digits;
                range = range * 10;
                start_number = start_number * 10;
                ++digits;
            }
        }

        return 0;
    }
};

int main(int argc, const char* argv[])
{
    Solution sol;
    int n;

    map<int, int> params = { {3, 3}, {10, 1}, {11, 0}, {12, 1}, {13, 1},
        {14, 1}, {15, 2}, {19, 4}, {30, 2}, {100, 5}, {1000000000, 1},
        {2147483647, 2}
    };

    for (auto& param: params) {
        assert(sol.findNthDigit(param.first) == param.second);
    }

    return 0;
}

