/*
1079. Letter Tile Possibilities
Medium

You have a set of tiles, where each tile has one letter tiles[i] printed on it.  Return the number of possible non-empty sequences of letters you can make. 

Example 1:
Input: "AAB"
Output: 8
Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".

Example 2:
Input: "AAABBC"
Output: 188

Note:
1 <= tiles.length <= 7
tiles consists of uppercase English letters.
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
    unordered_set<string> seqs;
    int sz;
    string res;
    vector<bool> used;

    void backtrack(string& s, int level) {
        if (level == sz) {
            if (res.size())
                seqs.emplace(res);
            return;
        }
        
        backtrack(s, level + 1);

        for (int i = 0; i < sz; ++i) {
            if (used[i])
                continue;
            used[i] = true;
            res.push_back(s[i]);
            backtrack(s, level + 1);
            res.pop_back();
            used[i] = false;
        }

    }
    
    int numTilePossibilities(string tiles) {
        sz = tiles.size();
        used.resize(sz, false);
        backtrack(tiles, 0);
        return seqs.size();
    }
};

int main() {
    Solution sol;
    string tiles;

    // Output: 8
    tiles =  "AAB";

    // Output: 188
    tiles = "AAABBC";

    cout << sol.numTilePossibilities(tiles) << endl;
    
    return 0;
}
