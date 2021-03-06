#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <climits>
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

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:

    vector<int> postorder(Node* root) {
        vector<int> res;
        stack<Node*> nodes;
        unordered_set<Node*> visited;
        if (!root)
            return res;
        nodes.push(root);
        while (nodes.size()) {
            auto node = nodes.top();
            if (!visited.insert(node).second) {
                res.push_back(node->val);
                nodes.pop();
                continue;
            }
            reverse(begin(node->children), end(node->children));
            for (auto child: node->children)
                nodes.push(child);
        }

        return res;
    }
};

int main() {
    Solution sol;

    return 0;
}
