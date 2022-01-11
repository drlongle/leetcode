/*
1522. Diameter of N-Ary Tree
Medium

Given a root of an N-ary tree, you need to compute the length of the diameter of the tree.

The diameter of an N-ary tree is the length of the longest path between any two nodes in the tree.
This path may or may not pass through the root.

(Nary-Tree input serialization is represented in their level order traversal,
each group of children is separated by the null value.)

Example 1:
Input: root = [1,null,3,2,4,null,5,6]
Output: 3
Explanation: Diameter is shown in red color.

Example 2:
Input: root = [1,null,2,null,3,4,null,5,null,6]
Output: 4

Example 3:
Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: 7

Constraints:
The depth of the n-ary tree is less than or equal to 1000.
The total number of nodes is between [1, 10^4].
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

class Solution {
public:
    int res = 0;

    int height(Node* node) {
        vector<int> h;
        for (auto child: node->children) {
            h.push_back(height(child));
        }
        if (h.empty())
            return 0;
        int a = 0, b = 0;
        for (int c: h) {
            if (c >= a) {
                b = a;
                a = c;
            } else if (c > b)
                b = c;
        }
        if (h.size() == 1)
            res = max(res, 1 + a);
        else
            res = max(res, 2 + a + b);

        return 1 + a;
    }

    int diameter(Node* root) {
        height(root);
        return res;
    }
};

int main() {
    Solution sol;

    return 0;
}
