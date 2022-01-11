/*
399. Evaluate Division
Difficulty: Medium

Equations are given in the format A / B = k, where A and B are variables
represented as strings, and k is a real number (floating point number). Given
some queries, return the answers. If the answer does not exist, return -1.0.

Example:
Given a / b = 2.0, b / c = 3.0. 
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? . 
return [6.0, 0.5, -1.0, 1.0, -1.0 ].

The input is:
 * vector<pair<string, string>> equations,
 * vector<double>& values,
 * vector<pair<string, string>> queries
where equations.size() == values.size() and the values are positive. This
represents the equations. Return vector<double>.

According to the example above:

equations = [ ["a", "b"], ["b", "c"] ],
values = [2.0, 3.0],
queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 
The input is always valid. You may assume that evaluating the queries will
result in no division by zero and there is no contradiction.
*/

#include <algorithm>
#include <bitset>
#include <cassert>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    double query(const vector<string>& query) {
        queue<pair<string, double>> nodes;
        set<string> visited;
        nodes.push({query[0], 1.0});
        while (nodes.size() > 0) {
            const pair<string, double>& node = nodes.front();
            if (node.first == query[1]) {
                return node.second;
            }
            for (auto& neigh: rel[node.first]) {
                if (!visited.count(neigh.first)) {
                    nodes.push({neigh.first, node.second * neigh.second});
                }
            }
            visited.emplace(node.first);
            nodes.pop();
        }
        
        return -1.0;
    }
    
    vector<double> calcEquation(vector<vector<string>> equations,
            vector<double>& values, vector<vector<string>>& queries) {
        for (size_t i = 0; i < equations.size(); ++i) {
            const vector<string>& eq = equations[i];
            rel[eq[0]][eq[1]] = values[i];
            rel[eq[1]][eq[0]] = 1.0 / values[i];
        }
        
        vector<double> res;
        for (const auto& q : queries) {
            if (!rel.count(q[0]) || !rel.count(q[1]))
                res.emplace_back(-1.0);
            else if (q[0] == q[1])
                res.emplace_back(1.0);
            else
                res.emplace_back(query(q));
        }
        
        return res;
    }
    
    map<string, map<string, double>> rel;
};

int main(int argc, char** argv) {
    Solution sol;
    vector<vector<string>> equations;
    vector<double> values, res;
    vector<vector<string>> queries;

    // Expected: [6.0, 0.5, -1.0, 1.0, -1.0 ]
    equations = { {"a", "b"}, {"b", "c"} };
    values = {2.0, 3.0};
    queries = { {"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"} };
    queries = { {"b", "a"} };
    queries = { {"x", "x"} };
    res = sol.calcEquation(equations, values, queries);
    copy(begin(res), end(res), ostream_iterator<double>(cout, ", "));
    cout << endl;

    return 0;
}
