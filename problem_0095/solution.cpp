/*
95. Unique Binary Search Trees II

Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <climits>
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
#include <vector>

#include <string.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> result;
        vector<int> numbers(n+1);
        iota(numbers.begin(), numbers.end(), 0);
        getTrees(numbers, 1, n, result);

        return result;
    }

    void getTrees(const vector<int>& numbers, int begin, int end,
        vector<TreeNode*>& result)
    {
        if (begin > end)
            return;

        for (int i = begin; i <= end; i++) {
	    array<vector<TreeNode*>, 2> subtrees;
            getTrees(numbers, begin, i-1, subtrees[0]);
            getTrees(numbers, i+1, end, subtrees[1]);
            if (subtrees[0].empty() && subtrees[1].empty())
            {
                TreeNode* root = new TreeNode(i);
                result.emplace_back(root);
                return;
            }

            if (subtrees[0].empty())
                subtrees[0].emplace_back(reinterpret_cast<TreeNode*>(0));
            if (subtrees[1].empty())
                subtrees[1].emplace_back(reinterpret_cast<TreeNode*>(0));
            for (int lindex = 0;
                lindex < static_cast<int>(subtrees[0].size()); ++lindex)
                for (int rindex = 0;
                    rindex < static_cast<int>(subtrees[1].size()); ++rindex)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = subtrees[0][lindex];
                    root->right = subtrees[1][rindex];
                    result.emplace_back(root);
                }
        }
    }
};

int main()
{
    Solution sol;
    vector<TreeNode*> result;
    result = sol.generateTrees(3);
    cout << "Number of trees: " << result.size() << endl;

    return 0;
}
