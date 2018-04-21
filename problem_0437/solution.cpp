/*
437. Path Sum III

    User Tried: 282
    Total Submissions: 613
    Difficulty: Easy

You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go
downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range
-1,000,000 to 1,000,000.

Example:

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11

*/

#include <algorithm>
#include <array>
#include <cassert>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    unordered_map<int, int> explore(TreeNode* root, int sum, int& count)
    {
        unordered_map<int, int> res;
        res[root->val] = 1;
        if (root->left) {
            unordered_map<int, int> lres = explore(root->left, sum, count);
            for (auto& lr: lres)
                res[lr.first + root->val] += lr.second;
        }
        if (root->right) {
            unordered_map<int, int> rres = explore(root->right, sum, count);
            for (auto& rr: rres)
                res[rr.first + root->val] += rr.second;
        }
        auto it = res.find(sum);
        if (it != res.end())
            count += it->second;

        return res;
    }

    int pathSum(TreeNode* root, int sum) {
        int res = 0;
        if (!root) return 0;
        explore(root, sum, res);

        return res;
    }
};

int main(int argc, const char* argv[])
{
    Solution sol;

    return 0;
}

