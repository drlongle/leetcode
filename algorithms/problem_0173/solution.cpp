/*
173. Binary Search Tree Iterator
Total Accepted: 50423 Total Submissions: 143363 Difficulty: Medium

Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
*/

#include <algorithm>
#include <array>
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

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

class BSTIterator {
public:
    BSTIterator(TreeNode *root) ;
    bool hasNext() ;
    int next() ;
    void visitLeft(TreeNode* node);

private:
    stack<TreeNode* > m_visits;
};

void BSTIterator::visitLeft(TreeNode* node)
{
    while (node)
    {
        m_visits.emplace(node);
        node = node->left;
    }
}

BSTIterator::BSTIterator(TreeNode *root) {
    visitLeft(root);
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    return !m_visits.empty();
}

/** @return the next smallest number */
int BSTIterator::next() {
    TreeNode* node = m_visits.top();
    m_visits.pop();
    visitLeft(node->right);
    return node->val;
}

int main()
{
    return 0;
}

