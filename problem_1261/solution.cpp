/*
1261. Find Elements in a Contaminated Binary Tree
Medium

Given a binary tree with the following rules:

root.val == 0
If treeNode.val == x and treeNode.left != null, then treeNode.left.val == 2 * x + 1
If treeNode.val == x and treeNode.right != null, then treeNode.right.val == 2 * x + 2
Now the binary tree is contaminated, which means all treeNode.val have been changed to -1.

You need to first recover the binary tree and then implement the FindElements class:

FindElements(TreeNode* root) Initializes the object with a contamined binary tree, you need to recover it first.
bool find(int target) Return if the target value exists in the recovered binary tree.
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
    TreeNode() : val(-1), left(NULL), right(NULL) {}
};

class FindElements {
public:

    void recover(TreeNode* node, int val) {
        if (!node)
            return;
        vals.emplace_back(val);
        recover(node->left, 2*val+1);
        recover(node->right, 2*val+2);
    }
    
    FindElements(TreeNode* root) {
        recover(root, 0);
        sort(begin(vals), end(vals));
    }
    
    bool find(int target) {
        int begin = 0, end = vals.size()-1;
        while (begin <= end) {
            int mid = (begin+end)/2;
            if (vals[mid] == target)
                return true;
            if (vals[mid] > target)
                end = mid -1;
            else
                begin = mid+1;
        }
        return false;
    }
    
    vector<int> vals;
};

void test_7()
{
    vector<TreeNode> nodes{4};
    nodes[0].left = nullptr;
    nodes[0].right = &nodes[1];
    nodes[1].left = &nodes[2];
    nodes[2].left = &nodes[3];
    FindElements find(&nodes[0]);
    for (auto n: {2, 3, 4, 5})
        cout << n << " -> " << find.find(n) << endl;
}

int main() {
    test_7();
    
    return 0;
}
