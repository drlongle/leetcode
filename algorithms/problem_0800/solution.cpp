/*
800. Similar RGB Color
Easy

In the following, every capital letter represents some hexadecimal digit from 0 to f.

The red-green-blue color "#AABBCC" can be written as "#ABC" in shorthand.  For example, "#15c" is shorthand for the color "#1155cc".

Now, say the similarity between two colors "#ABCDEF" and "#UVWXYZ" is -(AB - UV)^2 - (CD - WX)^2 - (EF - YZ)^2.

Given the color "#ABCDEF", return a 7 character color that is most similar to #ABCDEF, and has a shorthand
(that is, it can be represented as some "#XYZ"

Example 1:
Input: color = "#09f166"
Output: "#11ee66"
Explanation:
The similarity is -(0x09 - 0x11)^2 -(0xf1 - 0xee)^2 - (0x66 - 0x66)^2 = -64 -9 -0 = -73.
This is the highest among any shorthand color.
Note:

color is a string of length 7.
color is a valid RGB color: for i > 0, color[i] is a hexadecimal digit from 0 to f
Any answer which has the same (highest) similarity as the best answer will be accepted.
All inputs and outputs should use lowercase letters, and the output is 7 characters.
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <climits>
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
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "common/ListNode.h"
#include "common/Node.h"
#include "common/TreeNode.h"

using namespace std;

// We should find a string of pattern "#XXYYZZ" that is most similar to the input string.

class Solution {
public:
    string find_similar(const string& s) {
        string res(2, s[0]);
        int si = stoi(s, 0, 16);
        int ri = stoi(res, 0, 16);
        if (s[0] != '0') {
            string t = s[0] != 'a' ? string(2, s[0] - 1) : "99";
            int ti = stoi(t, 0, 16);
            if (abs(ti - si) < abs(si - ri)) {
                res = t;
                ri = ti;
            }
        }
        if (s[0] != 'f') {
            string t = s[0] != '9'? string(2, s[0] + 1) : "aa";
            int ti = stoi(t, 0, 16);
            if (abs(ti - si) < abs(si - ri))
                res = t;
        }
        return res;
    }

    string similarRGB(string color) {
        return "#" + find_similar(color.substr(1, 2))
                + find_similar(color.substr(3, 2)) + find_similar(color.substr (5, 2));
    }
};

int main() {
    Solution sol;

    return 0;
}
