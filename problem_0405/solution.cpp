/*
405. Convert a Number to Hexadecimal
Difficulty: Easy

Given an integer, write an algorithm to convert it to hexadecimal. For negative
integer, two’s complement method is used.

Note:

1. All letters in hexadecimal (a-f) must be in lowercase.
2. The hexadecimal string must not contain extra leading 0s. If the number is
zero, it is represented by a single zero character '0'; otherwise, the first
character in the hexadecimal string will not be the zero character.
3. The given number is guaranteed to fit within the range of a 32-bit signed integer.
4. You must not use any method provided by the library which converts/formats
the number to hex directly.

Example 1:
Input:
26
Output:
"1a"

Example 2:
Input:
-1
Output:
"ffffffff"

*/

#include <algorithm>
#include <bitset>
#include <cassert>
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

class Solution {
public:
    string toHex(int num) {
        unsigned int n = num;
        ostringstream os;
        while (n) {
            int d = n & 0xF;
            if (d < 10) {
                os << d;
            } else {
                os << static_cast<char>('a' + d - 10);
            }
            n >>= 4;
        }
        string s = os.str();
        reverse(begin(s), end(s));
        if (s.empty())
            s = "0";
        return s;
    }
};

int main(int argc, char** argv) {
    Solution sol;
    int num;
    
    num = 26;
    
    num = -1;
    
    cout << "Result: " << sol.toHex(num) << endl;

    return 0;
}
