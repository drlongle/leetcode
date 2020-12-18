/*
314. Binary Tree Vertical Order Traversal
Medium

Given a binary tree, return the vertical order traversal of its nodes' values. (ie,
from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.

Examples 1:
Input: [3,9,20,null,null,15,7]

   3
  /\
 /  \
 9  20
    /\
   /  \
  15   7

Output:
[
  [9],
  [3,15],
  [20],
  [7]
]

Examples 2:
Input: [3,9,8,4,0,1,7]

     3
    /\
   /  \
   9   8
  /\  /\
 /  \/  \
 4  01   7
Output:
[
  [4],
  [9],
  [3,0,1],
  [8],
  [7]
]

Examples 3:
Input: [3,9,8,4,0,1,7,null,null,null,2,5] (0's right child is 2 and 1's left child is 5)

     3
    /\
   /  \
   9   8
  /\  /\
 /  \/  \
 4  01   7
    /\
   /  \
   5   2

Output:
[
  [4],
  [9,5],
  [3,0,1],
  [8,2],
  [7]
]
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

#include "common/TreeNode.h"

using namespace std;

class Solution {
public:
    map<int, vector<int>> nodes;
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root)
            return res;
        queue<pair<int, TreeNode*>> q;
        q.emplace(0, root);
        while (!q.empty()) {
            auto& p = q.front();
            nodes[p.first].push_back(p.second->val);
            if (p.second->left)
                q.emplace(p.first - 1, p.second->left);
            if (p.second->right)
                q.emplace(p.first + 1, p.second->right);
            q.pop();
        }

        for (auto& col: nodes) {
            res.push_back(vector<int>());
            for (int v: col.second)
                res.back().push_back(v);
        }

        return res;
    }
};

int main() {
    Solution sol;

    return 0;
}
