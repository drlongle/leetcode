/*
515. Find Largest Value in Each Tree Row
Medium

You need to find the largest value in each row of a binary tree.

Example:
Input: 

          1
         / \
        3   2
       / \   \  
      5   3   9 

Output: [1, 3, 9]
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <future>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        queue<pair<TreeNode*, size_t>> q;
        q.emplace(root, 0);
        while (!q.empty()) {
            auto& [node, round] = q.front();
            if (node == nullptr) {
                q.pop();
                continue;
            }
            q.push({node->left, round+1});
            q.push({node->right, round+1});
            if (res.size() < round+1)
                res.emplace_back(node->val);
            else
                res.back() = max(res.back(), node->val);
            q.pop();
        }
        return res;
    }
};

int main() {
    Solution sol;
    return 0;
}
