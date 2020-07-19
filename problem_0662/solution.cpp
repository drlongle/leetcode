/*
662. Maximum Width of Binary Tree
Medium

1273

267

Add to List

Share
Given a binary tree, write a function to get the maximum width of the given tree. The width of a tree is the
maximum width among all levels. The binary tree has the same structure as a full binary tree, but some nodes are null.

The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null
nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.

Example 1:
Input: 
           1
         /   \
        3     2
       / \     \  
      5   3     9 
Output: 4
Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).

Example 2:
Input: 
          1
         /  
        3    
       / \       
      5   3     
Output: 2
Explanation: The maximum width existing in the third level with the length 2 (5,3).

Example 3:
Input: 

          1
         / \
        3   2 
       /        
      5      
Output: 2
Explanation: The maximum width existing in the second level with the length 2 (3,2).

Example 4:
Input: 
          1
         / \
        3   2
       /     \  
      5       9 
     /         \
    6           7
Output: 8
Explanation:The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7).

Note: Answer will in the range of 32-bit signed integer.
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
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void insert(array<TreeNode*, 10000>& nodes, TreeNode* node, size_t index, long long& first, int& last) {
        nodes[index] = node;
        if (node != nullptr) {
            last = index;
            if (first < 0)
                first = index;
        }
    }

    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        array<vector<pair<long long, TreeNode*>>, 2> nodes;
        long long res = 0, curr = 0;
        nodes[0].emplace_back(0, root);
        while (nodes[curr].size()) {
            auto& curr_nodes = nodes[curr];
            auto& next_nodes = nodes[1 - curr];
            next_nodes.resize(0);
            auto offset = curr_nodes[0].first;
            auto distance = curr_nodes.back().first - offset;
            res = max(res, distance + 1);
            for (auto&p: curr_nodes) {
                auto pos = p.first;
                auto node = p.second;
                if (node->left)
                    next_nodes.emplace_back(2*pos - offset, node->left);
                if (node->right)
                    next_nodes.emplace_back(2*pos - offset + 1, node->right);
            }
            curr = 1 - curr;
        }

        return res;
    }
};

int main() {
    Solution sol;
    return 0;
}
