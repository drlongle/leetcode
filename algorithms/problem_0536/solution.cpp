/*
536. Construct Binary Tree from String
Medium

You need to construct a binary tree from a string consisting of parenthesis and integers.

The whole input represents a binary tree. It contains an integer followed by zero,
one or two pairs of parenthesis. The integer represents the root's value and a pair of
parenthesis contains a child binary tree with the same structure.

You always start to construct the left child node of the parent first if it exists.

Example 1:
Input: s = "4(2(3)(1))(6(5))"
Output: [4,2,6,3,1,5]
Example 2:

Input: s = "4(2(3)(1))(6(5)(7))"
Output: [4,2,6,3,1,5,7]

Example 3:
Input: s = "-4(2(3)(1))(6(5)(7))"
Output: [-4,2,6,3,1,5,7]

Constraints:
0 <= s.length <= 3 * 104
s consists of digits, '(', ')', and '-' only.
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
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
    TreeNode* create(string& s, size_t& index) {
        int num = 0;
        int sign = 1;
        if (s[index] == '-') {
            ++index;
            sign = -1;
        }
        while (index < s.size() && isdigit(s[index])) {
            num = num*10 + s[index++] - '0';
        }
        TreeNode* node = new TreeNode(num * sign);
        if (index < s.size() && s[index] == '(')
            node->left = create(s, ++index);
        if (index < s.size() && s[index] == '(')
            node->right = create(s, ++index);
        if (index < s.size() && s[index] == ')')
            ++index;
        return node;
    }
    TreeNode* str2tree(string s) {
        if (s.empty())
            return nullptr;
        size_t index = 0;
        return create(s, index);
    }
};

int main() {
    Solution sol;
    string s;

    s = "4(2)";
    sol.str2tree(s);

    return 0;
}
