/*

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

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        vector<vector<TreeNode*>> nodes(2);
        nodes[0].emplace_back(root);
        int index = 0;
        while (!nodes[index].empty()) {
            nodes[1-index].resize(0);
            int sz = nodes[index].size();
            for (int i = 0; i < sz; ++i) {
                auto node = nodes[index][i];
                if (node->val % 2 == index)
                    return false;
                if (i > 0) {
                    if (index == 0) {
                        if (node->val <= nodes[index][i-1]->val)
                            return false;
                    } else if (node->val >= nodes[index][i-1]->val)
                            return false;
                }
                if (node->left)
                    nodes[1 - index].emplace_back(node->left);
                if (node->right)
                    nodes[1 - index].emplace_back(node->right);
            }

            index = 1 - index;
        }
        return true;
    }
};

int main() {
    Solution sol;

    return 0;
}
