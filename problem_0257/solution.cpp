/*
257. Binary Tree Paths
Total Accepted: 50339 Total Submissions: 172961 Difficulty: Easy

Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5

All root-to-leaf paths are:
["1->2->5", "1->3"]
*/

#include <algorithm>
#include <cassert>
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

void find_paths(TreeNode* root, string& path, vector<string>& paths)
{
    if (!root) return;
    int curpos = path.size();
    if (curpos)
        path.append("->");
    path.append(to_string(root->val));
    if (!root->left && !root->right)
        paths.emplace_back(path);
    else
    {
        find_paths(root->left, path, paths);
        find_paths(root->right, path, paths);
    }

    path.erase(curpos);
}

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string path;

        find_paths(root, path, res);
        return res;
    }
};

int main()
{
    Solution sol;

    return 0;
}

