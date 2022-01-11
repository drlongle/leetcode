/*
427. Construct Quad Tree
Medium


We want to use quad trees to store an N x N boolean grid. Each cell in the grid can only be true or false. The root node represents the whole grid. For each node, it will be subdivided into four children nodes until the values in the region it represents are all the same.

Each node has another two boolean attributes : isLeaf and val. isLeaf is true if and only if the node is a leaf node. The val attribute for a leaf node contains the value of the region it represents.

Your task is to use a quad tree to represent a given grid. The following example may help you understand the problem better:

Given the 8 x 8 grid below, we want to construct the corresponding quad tree:*/

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

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }

    ~Node() {
        delete topLeft;
        delete topRight;
        delete bottomLeft;
        delete bottomRight;
    }
};

void print(Node* node) {
    if (node == nullptr)
        return;
    printf("node: %p, topLeft: %p, topRight: %p, bottomLeft: %p, bottomRight: %p, val: %d, isLeaf: %d\n",
           node, node->topLeft, node->topRight, node->bottomLeft, node->bottomRight, node->val, node->isLeaf);
    print(node->topLeft);
    print(node->topRight);
    print(node->bottomLeft);
    print(node->bottomRight);
}

class Solution {
public:
    Node* construct(vector<vector<int>>& grid, int x1, int y1, int x2, int y2) {
        int ssize = x2 - x1 + 1;
        if (ssize == 1)
            return new Node(grid[x1][y1], true, nullptr, nullptr, nullptr, nullptr);
        int val = sum[x2][y2] - (x1 > 0 ? sum[x1-1][y2] : 0) - (y1 > 0 ? sum[x2][y1-1] : 0)
            + (x1 > 0 && y1 > 0 ? sum[x1-1][y1-1] : 0);
        if (val == ssize*ssize || val == 0)
            return new Node(val, true, nullptr, nullptr, nullptr, nullptr);

        Node* top_left = construct(grid, x1, y1, x1 + ssize/2-1, y1 + ssize/2-1);
        Node* top_right = construct(grid, x1, y1 + ssize/2, x1 + ssize/2-1, y2);
        Node* bottom_left = construct(grid, x1 + ssize/2, y1, x2, y1 + ssize/2-1);
        Node* bottom_right = construct(grid, x1 + ssize/2, y1 + ssize/2, x2, y2);
        
        return new Node(val, false, top_left, top_right, bottom_left, bottom_right);
    }

    Node* construct(vector<vector<int>>& grid) {
        int N = grid.size();
        sum.resize(N, vector<int>(N, 0));

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                sum[i][j] = grid[i][j] + (i > 0 ? sum[i-1][j] : 0) +
                    (j > 0 ? sum[i][j-1] : 0) - (i > 0 && j > 0 ? sum[i-1][j-1] : 0);
            }
        }

        /*
        for (int i = 0; i < N; ++i) {
            copy(begin(sum[i]), end(sum[i]), ostream_iterator<int>(cout, ", "));
            cout << endl;
        }
        */

        return construct(grid, 0, 0, N-1, N-1);
    }

    vector<vector<int>> sum;
};

int main() {
    Solution sol;
    vector<vector<int>> grid;

    grid = {{1, 0},{0,1}};

    grid = {{1,1,0,0},{1,1,0,0},{0,0,0,0},{0,0,0,0}};

    grid = {
        {1,1,1,1,0,0,0,0},
        {1,1,1,1,0,0,0,0},
        {1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1},
        {1,1,1,1,0,0,0,0},
        {1,1,1,1,0,0,0,0},
        {1,1,1,1,0,0,0,0},
        {1,1,1,1,0,0,0,0}
    };
    
    Node *node = sol.construct(grid);
    print(node);
    delete node;
    
    return 0;
}
