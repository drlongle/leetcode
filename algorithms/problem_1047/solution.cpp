/*
1047. Remove All Adjacent Duplicates In String
Easy

Given a string S of lowercase letters, a duplicate removal consists of choosing two adjacent and
equal letters, and removing them.

We repeatedly make duplicate removals on S until we no longer can.

Return the final string after all such duplicate removals have been made. It is
guaranteed the answer is unique.

Example 1:

Input: "abbaca"
Output: "ca"
Explanation:
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is
the only possible move.  The result of this move is that the string is "aaca", of which only "aa"
is possible, so the final string is "ca".

Note:
1 <= S.length <= 20000
S consists only of English lowercase letters.
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
    string removeDuplicates(string S) {
        string res;
        for (char ch: S) {
            if (res.size() && res.back() == ch)
                res.pop_back();
            else
                res.push_back(ch);
        }
        return res;
    }
};

int main() {
    Solution sol;

    return 0;
}
