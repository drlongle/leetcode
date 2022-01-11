/*
297. Serialize and Deserialize Binary Tree
Total Accepted: 12020 Total Submissions: 45692 Difficulty: Medium

Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

For example, you may serialize the following tree

    1
   / \
  2   3
     / \
    4   5

as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "null";
        ostringstream oss;
        oss << root->val << " ";
        oss << serialize(root->left) << " ";
        oss << serialize(root->right) << " ";
        return oss.str();
    }

    TreeNode* deserialize(istringstream& iss) {
        string st;
        iss >> st;
        if (st == "null") return NULL;
        TreeNode *root = new TreeNode(stoi(st));
        root->left = deserialize(iss);
        root->right = deserialize(iss);

        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss(data);
        return deserialize(iss);
    }
};

int main()
{
    Codec codec;
    cout << codec.serialize(new TreeNode(1)) << endl;
    return 0;
}
