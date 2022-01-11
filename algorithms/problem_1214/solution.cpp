/*
1214. Two Sum BSTs
Medium

Given two binary search trees, return True if and only if there is a node in the
first tree and a node in the second tree whose values sum up to a given integer target.
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

bool find_node(TreeNode* root, int target) {
    queue<TreeNode*> q;
    q.emplace(root);
    while (!q.empty()) {
        TreeNode* n = q.front();
        q.pop();
        if (!n) continue;
        if (n->val == target)
            return true;
        if (n->val > target)
            q.emplace(n->left);
        else
            q.emplace(n->right);
    }

    return false;
}

class Solution {
public:
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        queue<TreeNode*> q;
        q.emplace(root1);
        while (!q.empty()) {
            TreeNode* n = q.front();
            q.pop();
            if (!n) continue;
            if (find_node(root2, target - n->val))
                return true;
            q.emplace(n->left);
            q.emplace(n->right);
        }

        return false;
    }
};

int main() {
    Solution sol;
    return 0;
}
