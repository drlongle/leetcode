/*
426. Convert Binary Search Tree to Sorted Doubly Linked List
Medium

Convert a Binary Search Tree to a sorted Circular Doubly-Linked List in place.

You can think of the left and right pointers as synonymous to the predecessor
and successor pointers in a doubly-linked list. For a circular doubly linked list,
the predecessor of the first element is the last element, and the successor of
the last element is the first element.

We want to do the transformation in place. After the transformation, the left pointer
of the tree node should point to its predecessor, and the right pointer should point
to its successor. You should return the pointer to the smallest element of the linked list.

Example 1:
Input: root = [4,2,5,1,3]
Output: [1,2,3,4,5]

Explanation: The figure below shows the transformed BST. The solid line indicates the
successor relationship, while the dashed line means the predecessor relationship.

Example 2:
Input: root = [2,1,3]
Output: [1,2,3]

Example 3:
Input: root = []
Output: []
Explanation: Input is an empty tree. Output is also an empty Linked List.

Example 4:
Input: root = [1]
Output: [1]

Constraints:
-1000 <= Node.val <= 1000
Node.left.val < Node.val < Node.right.val
All values of Node.val are unique.
0 <= Number of Nodes <= 2000
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
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    pair<Node*, Node*> convert(Node* node) {
        Node* head, *tail;
        if (node->left) {
            std::tie(head, tail) = convert(node->left);
            tail->right = node;
            node->left = tail;
            tail = node;
        } else
            head = tail = node;
        if (node->right) {
            auto rr = convert(node->right);
            tail->right = rr.first;
            rr.first->left = tail;
            tail = rr.second;
        }

        return make_pair(head, tail);
    }

    Node* treeToDoublyList(Node* root) {
        if (!root)
            return nullptr;
        auto [head, tail] = convert(root);
        head->left = tail;
        tail->right = head;

        return head;
    }
};

int main() {
    Solution sol;

    return 0;
}
