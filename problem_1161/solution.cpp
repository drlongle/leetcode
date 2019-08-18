/*
1161. Maximum Level Sum of a Binary Tree
Medium

Given the root of a binary tree, the level of its root is 1, the level of its children
is 2, and so on. Return the smallest level X such that the sum of all the values of nodes
at level X is maximal.
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

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        unordered_map<int, int> sums;

        queue<pair<TreeNode*, int>> q;
        q.emplace(root, 1);
        while (!q.empty()) {
            auto& p = q.front();
            if (p.first) {
                sums[p.second] += p.first->val;
                q.emplace(p.first->left, p.second + 1);
                q.emplace(p.first->right, p.second + 1);
            }
            q.pop();
        }
        auto it = max_element(begin(sums), end(sums), [](auto& p1, auto& p2) {return p1.second < p2.second;});
        
        return it->first;
    }
};

int main() {
    Solution sol;
    return 0;
}
