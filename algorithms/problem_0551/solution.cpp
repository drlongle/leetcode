/*
551. Student Attendance Record I
Easy

You are given a string s representing an attendance record for a student where
each character signifies whether the student was absent, late, or present on
that day. The record only contains the following three characters:

'A': Absent.
'L': Late.
'P': Present.
The student is eligible for an attendance award if they meet both of the
following criteria:

The student was absent ('A') for strictly fewer than 2 days total.
The student was never late ('L') for 3 or more consecutive days.
Return true if the student is eligible for an attendance award, or false
otherwise.

Example 1:
Input: s = "PPALLP"
Output: true
Explanation: The student has fewer than 2 absences and was never late 3 or more
consecutive days.

Example 2:
Input: s = "PPALLL"
Output: false
Explanation: The student was late 3 consecutive days in the last 3 days, so is
not eligible for the award.

Constraints:
1 <= s.length <= 1000
s[i] is either 'A', 'L', or 'P'.
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
#include <ranges>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "common/FenwickTree.h"
#include "common/ListNode.h"
#include "common/Node.h"
#include "common/SegmentTree.h"
#include "common/TreeNode.h"
#include "common/UnionFind.h"
#include "common/bits.h"

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

class Solution {
  public:
    bool checkRecord(string s) {
        int a = 0;
        int l = 0;
        for (char c : s) {
            switch (c) {
            case 'A':
                if (++a > 1)
                    return false;
                l = 0;
                break;
            case 'L':
                if (++l >= 3)
                    return false;
                break;
            case 'P':
            default:
                l = 0;
                break;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    string s;

    s = "PPALLP";
    cout << boolalpha << s << " -> " << sol.checkRecord(s) << endl;

    s = "PPALLL";
    cout << boolalpha << s << " -> " << sol.checkRecord(s) << endl;
    return 0;
}
