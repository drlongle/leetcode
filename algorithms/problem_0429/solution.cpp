/*
429. N-ary Tree Level Order Traversal
Easy

Given an n-ary tree, return the level order traversal of its nodes' values.
(ie, from left to right, level by level).
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

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        array<queue<Node*>, 2> q;
        int curr = 0;
        if (root)
            q[curr].emplace(root);
        while (true) {
            int next = 1 - curr;
            if (q[curr].empty())
                break;
            res.emplace_back(vector<int>(0));
            while (!q[curr].empty()) {
                Node* node = q[curr].front();
                q[curr].pop();
                res.back().emplace_back(node->val);
                for (auto& child: node->children)
                    q[next].emplace(child);
            }
            curr = next;
        }

        return res;
    }
};

int main()
{
    Solution sol;
    constexpr int size = 10;
    vector<Node> nodes(size);

    for (int i = 0; i < size; ++i)
        nodes[i].val = i;
    
    nodes[1].children.push_back(&nodes[3]);
    nodes[1].children.push_back(&nodes[2]);
    nodes[1].children.push_back(&nodes[4]);
    nodes[3].children.push_back(&nodes[5]);
    nodes[3].children.push_back(&nodes[6]);
            
    auto res = sol.levelOrder(&nodes[1]);
    for (auto& r: res) {
        copy(begin(r), end(r), ostream_iterator<int>(cout, ", "));
        cout << endl;
    }

    return 0;
}

