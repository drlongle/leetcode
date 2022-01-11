/*
1202. Smallest String With Swaps
Medium

You are given a string s, and an array of pairs of indices in the string pairs
where pairs[i] = [a, b] indicates 2 indices(0-indexed) of the string.
You can swap the characters at any pair of indices in the given pairs any number of times.

Return the lexicographically smallest string that s can be changed to after using the swaps.

Example 1:
Input: s = "dcab", pairs = [[0,3],[1,2]]
Output: "bacd"
Explaination: 
Swap s[0] and s[3], s = "bcad"
Swap s[1] and s[2], s = "bacd"

Example 2:
Input: s = "dcab", pairs = [[0,3],[1,2],[0,2]]
Output: "abcd"
Explaination: 
Swap s[0] and s[3], s = "bcad"
Swap s[0] and s[2], s = "acbd"
Swap s[1] and s[2], s = "abcd"

Example 3:
Input: s = "cba", pairs = [[0,1],[1,2]]
Output: "abc"
Explaination: 
Swap s[0] and s[1], s = "bca"
Swap s[1] and s[2], s = "bac"
Swap s[0] and s[1], s = "abc"

Constraints:
1 <= s.length <= 10^5
0 <= pairs.length <= 10^5
0 <= pairs[i][0], pairs[i][1] < s.length
s only contains lower case English letters.
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
    int get_root(int n) {
        int i = n;
        while (roots[n] != n) {
            n = roots[n];
        }
        roots[i] = n;
        return n;
    }

    void set_root(int n, int root) {
        while (roots[n] != root) {
            int parent = roots[n];
            roots[n] = root;
            n = parent;
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int sz = s.size();
        roots.resize(sz);
        iota(begin(roots), end(roots), 0);
        for (auto& p: pairs) {
            int a = p[0];
            int b = p[1];
            int root_a = get_root(a);
            int root_b = get_root(b);
            if (root_a < root_b)
                set_root(b, root_a);
            else
                set_root(a, root_b);
        }
        
        map<int, vector<char>> chars;
        map<int, vector<int>> indexes;
        for (int i = 0; i < sz; ++i) {
            int root = get_root(i);
            chars[root].emplace_back(s[i]);
            indexes[root].emplace_back(i);
        }
        for (auto& p: chars) {
            sort(begin(p.second), end(p.second));
            int n = p.second.size();
            for (int i = 0; i < n; ++i) {
                s[indexes[p.first][i]] = p.second[i];
            }
        }
        
        return s;
    }

    vector<int> roots;
};

int main() {
    Solution sol;
    string s;
    vector<vector<int>> pairs;

    // Output: "bacd"
    s = "dcab", pairs = {{0,3},{1,2}};

    // Output: "abcd"
    s = "dcab", pairs = {{0,3},{1,2},{0,2}};

    // Output: "abc"
    s = "cba", pairs = {{0,1},{1,2}};

    cout << "Result: " << sol.smallestStringWithSwaps(s, pairs) << endl;
    
    return 0;
}
