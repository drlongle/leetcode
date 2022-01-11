/*
1530. Number of Good Leaf Nodes Pairs
Medium

Given the root of a binary tree and an integer distance. A pair of two different leaf nodes of a binary tree is
said to be good if the length of the shortest path between them is less than or equal to distance.

Return the number of good leaf node pairs in the tree.

Example 1:
Input: root = [1,2,3,null,4], distance = 3
Output: 1
Explanation: The leaf nodes of the tree are 3 and 4 and the length of the shortest path between them is 3. This is the only good pair.

Example 2:
Input: root = [1,2,3,4,5,6,7], distance = 3
Output: 2
Explanation: The good pairs are [4,5] and [6,7] with shortest path = 2. The pair [4,6] is not good because the length of ther shortest path between them is 4.

Example 3:
Input: root = [7,1,4,6,null,5,3,null,null,null,null,null,2], distance = 3
Output: 1
Explanation: The only good pair is [2,5].

Example 4:
Input: root = [100], distance = 1
Output: 0

Example 5:
Input: root = [1,1,1], distance = 2
Output: 1

Constraints:
The number of nodes in the tree is in the range [1, 2^10].
Each node's value is between [1, 100].
1 <= distance <= 10
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
    unordered_map<int, int> visit(TreeNode* node, int distance, int* cnt) {
        if (!node)
            return {};
        auto lr = visit(node->left, distance, cnt);
        auto rr = visit(node->right, distance, cnt);
        unordered_map<int, int> res;
        for (auto& [k, v]: lr) {
            res[k+1] += v;
            for (int i = 0; i <= distance -k - 2; ++i) {
                auto it = rr.find(i);
                if (it != rr.end())
                    *cnt += v * it->second;
            }
        }
        for (auto& [k, v]: rr) {
            res[k+1] += v;
        }
        if (node->left == nullptr && node->right == nullptr)
            res[0] = 1;
        return res;
    }
    int countPairs(TreeNode* root, int distance) {
        int res = 0;
        visit(root, distance, &res);
        return res;
    }
};

int main() {
    Solution sol;
    return 0;
}
