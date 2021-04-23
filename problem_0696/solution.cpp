/*
696. Count Binary Substrings
Easy

Give a string s, count the number of non-empty (contiguous) substrings that have the same number of 0's and 1's,
and all the 0's and all the 1's in these substrings are grouped consecutively.

Substrings that occur multiple times are counted the number of times they occur.

Example 1:
Input: "00110011"
Output: 6
Explanation: There are 6 substrings that have equal number of consecutive 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".
Notice that some of these substrings repeat and are counted the number of times they occur.
Also, "00110011" is not a valid substring because all the 0's (and 1's) are not grouped together.

Example 2:
Input: "10101"
Output: 4
Explanation: There are 4 substrings: "10", "01", "10", "01" that have equal number of consecutive 1's and 0's.

Note:
s.length will be between 1 and 50,000.
s will only consist of "0" or "1" characters.
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
#include "common/TreeNode.h"

using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        int cnt = 0, sz = s.size();
        for (int i = 0; i < sz-1; ++i) {
            if (s[i]== '0' && s[i+1] == '1') {
                for (int k = i, j = i+1; k >= 0 && j < sz; --k, ++j) {
                    if (s[k] == '0' && s[j] == '1')
                        ++cnt;
                    else
                        break;
                }
            } else if (s[i]== '1' && s[i+1] == '0') {
                for (int k = i, j = i+1; k >= 0 && j < sz; --k, ++j) {
                    if (s[k] == '1' && s[j] == '0')
                        ++cnt;
                    else
                        break;
                }
            }
        }
        return cnt;
    }
};

int main() {
    Solution sol;

    return 0;
}
