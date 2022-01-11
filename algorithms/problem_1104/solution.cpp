/*
1104. Path In Zigzag Labelled Binary Tree
Medium

In an infinite binary tree where every node has two children, the nodes are
labelled in row order. In the odd numbered rows (ie., the first, third, fifth,...),
the labelling is left to right, while in the even numbered rows
(second, fourth, sixth,...), the labelling is right to left. Given the label
of a node in this tree, return the labels in the path from the root of
the tree to the node with that label.

Example 1:
Input: label = 14
Output: [1,3,4,14]

Example 2:
Input: label = 26
Output: [1,2,6,10,26]
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

class Solution {
public:
    int reverse_label(int label)
    {
        int level = log2(label);
        return 3 * pow(2, level) - 1 - label;
    }

    void add_label(int label)
    {
        res.emplace_back(label);
        if (label == 1)
            return;

        int level = log2(label);
        int parent;
        if (level % 2) {
            parent = reverse_label(label) / 2;
        } else
            parent = reverse_label(label / 2);
        add_label(parent);
    }

    vector<int> pathInZigZagTree(int label)
    {
        res.clear();
        add_label(label);
        reverse(begin(res), end(res));
        return res;
    }

    vector<int> res;
};

int main()
{
    Solution sol;
    vector<int> labels = {1, 2, 3, 4, 10, 14, 26, 31, 34, 40, 50, 60, 70, 80};

    for (int label : labels) {
        vector<int> res = sol.pathInZigZagTree(label);
        cout << "Label: " << label << " -> ";
        copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
        cout << endl;
    }

    return 0;
}
