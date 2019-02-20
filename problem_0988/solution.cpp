/*
Problem 988. Smallest String Starting From Leaf
Difficulty: Medium

Given the root of a binary tree, each node has a value from 0 to 25
representing the letters 'a' to 'z': a value of 0 represents 'a', a value of 1
represents 'b', and so on.

Find the lexicographically smallest string that starts at a leaf of this tree
and ends at the root.

(As a reminder, any shorter prefix of a string is lexicographically smaller:
for example, "ab" is lexicographically smaller than "aba".  A leaf of a node
is a node that has no children.)
*/

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <functional>
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

class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        if (!root) return "";
        string left = smallestFromLeaf(root->left);
        string right = smallestFromLeaf(root->right);
        if (root->right == nullptr || (root->left && left <= right)) {
            left.push_back('a' + root->val);
            return left;
        } else {
            right.push_back('a' + root->val);
            return right;
        }
    }
};

int main()
{
    Solution sol;

    return 0;
}

