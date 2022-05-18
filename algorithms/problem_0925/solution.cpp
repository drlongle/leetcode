/*
925. Long Pressed Name
Easy

Your friend is typing his name into a keyboard. Sometimes, when typing a
character c, the key might get long pressed, and the character will be typed 1
or more times.

You examine the typed characters of the keyboard. Return True if it is possible
that it was your friends name, with some characters (possibly none) being long
pressed.

Example 1:
Input: name = "alex", typed = "aaleex"
Output: true
Explanation: 'a' and 'e' in 'alex' were long pressed.

Example 2:
Input: name = "saeed", typed = "ssaaedd"
Output: false
Explanation: 'e' must have been pressed twice, but it was not in the typed
output.

Constraints:
1 <= name.length, typed.length <= 1000
name and typed consist of only lowercase English letters.
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

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

class Solution {
  public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0, ns = name.size(), ts = typed.size();
        while (i < ns || j < ts) {
            if (i < ns && name[i] == typed[j])
                ++i, ++j;
            else if (i == 0)
                return false;
            else if (typed[j] == name[i - 1])
                ++j;
            else
                return false;
        }
        return (i == ns && j == ts);
    }
};

int main() {
    Solution sol;
    string name, typed;

    // Output: true
    name = "alex", typed = "aaleex";
    cout << boolalpha << sol.isLongPressedName(name, typed) << endl;

    // Output: false
    name = "saeed", typed = "ssaaedd";
    cout << boolalpha << sol.isLongPressedName(name, typed) << endl;

    return 0;
}
