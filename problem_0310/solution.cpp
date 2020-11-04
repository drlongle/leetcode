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

struct Node {
    Node(int i): id(i) {}
    int id;
    unordered_set<int> neighs;
};

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<Node> nodes;
        for (int i = 0; i < n; ++i)
            nodes.emplace_back(i);
        for (auto& edge: edges) {
            nodes[edge[0]].neighs.emplace(edge[1]);
            nodes[edge[1]].neighs.emplace(edge[0]);
        }

        auto lambda = [] (Node& n1, Node& n2) {
            return n1.neighs.size() < n2.neighs.size();
        };
        auto mit = min_element(begin(nodes), end(nodes), lambda);
        unordered_set<int> curr, next;

        for (auto& n: nodes) {
            if (n.neighs.size() == mit->neighs.size()) {
                next.emplace(n.id);
            }
        }

        do {
            swap(curr, next);
            next.clear();
            for (int id: curr) {
                if (nodes[id].neighs.size()) {
                    int nid = *(nodes[id].neighs.begin());
                    nodes[nid].neighs.erase(id);
                    if (!curr.count(nid) && nodes[nid].neighs.size() <= 1)
                        next.emplace(nid);
                }
            }

        } while (next.size() > 0);

        return vector<int>(begin(curr), end(curr));
    }
};

int main() {
    Solution sol;
    int n;
    vector<vector<int>> edges;
    vector<int> res;

    // Output: {1}
    n = 4, edges = {{1,0},{1,2},{1,3}};
    res = sol.findMinHeightTrees(n, edges);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;

    // Output: {3,4}
    n = 6, edges = {{3,0},{3,1},{3,2},{3,4},{5,4}};
    res = sol.findMinHeightTrees(n, edges);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;

    n = 1, edges = {};
    res = sol.findMinHeightTrees(n, edges);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;

    n = 2, edges = {{0,1}};
    res = sol.findMinHeightTrees(n, edges);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;

    // OUtput: [1,2]
    n = 7;
    edges = {{0,1},{1,2},{1,3},{2,4},{3,5},{4,6}};
    res = sol.findMinHeightTrees(n, edges);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;

    return 0;
}
