/*
449. Serialize and Deserialize BST
Medium

Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary search tree can be serialized to a string and this string can be deserialized to the original tree structure.

The encoded string should be as compact as possible.
Note: Do not use class member/global
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

class Codec {
public:

    void serialize(TreeNode* root, ostringstream& oss) {
        if (!root) {
            oss << "NULL" << " ";
            return;
        }
        oss << root->val << " ";
        serialize(root->left, oss);
        serialize(root->right, oss);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream oss;
        serialize(root, oss);
        return oss.str();
    }

    TreeNode* deserialize(istringstream& iss) {
        string s;
        iss >> s;
        if (s == "NULL")
            return nullptr;
        TreeNode* node = new TreeNode(stoi(s));
        node->left = deserialize(iss);
        node->right = deserialize(iss);
        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss(data);
        return deserialize(iss);
    }
};


int main() {
    Solution sol;
    return 0;
}
