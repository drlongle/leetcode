/*
987. Vertical Order Traversal of a Binary Tree
Difficulty: Medium

Given a binary tree, return the vertical order traversal of its nodes values.

For each node at position (X, Y), its left and right children respectively
will be at positions (X-1, Y-1) and (X+1, Y-1).

Running a vertical line from X = -infinity to X = +infinity, whenever the
vertical line touches some nodes, we report the values of the nodes in order
from top to bottom (decreasing Y coordinates).

If two nodes have the same position, then the value of the node that is
reported first is the value that is smaller.

Return an list of non-empty reports in order of X coordinate. Every report
will have a list of values of nodes.
*/

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    
    void traverse(TreeNode* node, int x, int y) {
        visit[x][y].push_back(node->val);
        if (node->left)
            traverse(node->left, x-1, y-1);
        if (node->right)
            traverse(node->right, x+1, y-1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        traverse(root, 0, 0);
        for (auto it = visit.begin(); it != visit.end(); ++it) {
            vector<int> temp;
            for (auto it2 = it->second.rbegin(); it2 != it->second.rend(); ++it2) {
                sort(begin(it2->second), end(it2->second));
                copy(begin(it2->second), end(it2->second), back_inserter(temp));
            }
            res.emplace_back(temp);
        }
        
        return res;
    }
    
    map<int, map<int, vector<int>>> visit;
};

int main(int argc, char** argv) {
    Solution sol;
    
    return 0;
}
