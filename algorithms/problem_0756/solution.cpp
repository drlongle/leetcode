/*
756. Pyramid Transition Matrix
Medium

We are stacking blocks to form a pyramid. Each block has a color which is a one letter string.

We are allowed to place any color block C on top of two adjacent blocks of colors A and B, if and only if ABC is an allowed triple.

We start with a bottom row of bottom, represented as a single string. We also start with a list of allowed triples allowed. Each allowed triple is represented as a string of length 3.

Return true if we can build the pyramid all the way to the top, otherwise false.

Example 1:
Input: bottom = "BCD", allowed = ["BCG", "CDE", "GEA", "FFF"]
Output: true
Explanation:
We can stack the pyramid like this:
    A
   / \
  G   E
 / \ / \
B   C   D

We are allowed to place G on top of B and C because BCG is an allowed triple.  Similarly, we can place E on top of C and D, then A on top of G and E.

Example 2:
Input: bottom = "AABA", allowed = ["AAA", "AAB", "ABA", "ABB", "BAC"]
Output: false
Explanation:
We can't stack the pyramid to the top.
Note that there could be allowed triples (A, B, C) and (A, B, D) with C != D.

Constraints:
bottom will be a string with length in range [2, 8].
allowed will have length in range [0, 200].
Letters in all strings will be chosen from the set {'A', 'B', 'C', 'D', 'E', 'F', 'G'}.
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

class Solution {
public:
    unordered_map<string, vector<char>> lookup;

    bool dfs(string& s, string& ns, int index) {
        int sz = s.size();
        if (sz == 1)
            return true;
        if (index == sz - 1) {
            string nns;
            return dfs(ns, nns, 0);
        }

        string key = string({s[index], s[index+1]});
        auto& chars = lookup[key];
        if (chars.empty())
            return false;
        ns.push_back(' ');
        for (char ch: chars) {
            ns.back() = ch;
            int nsz = ns.size();
            if (nsz >= 2) {
                string key{ns[nsz-2], ns[nsz-1]};
                if (lookup.count(key) == 0)
                    continue;
            }
            if (dfs(s, ns, index+1))
                return true;
        }
        ns.pop_back();
        return false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        lookup.clear();
        for (string& s: allowed) {
            lookup[string({s[0], s[1]})].emplace_back(s[2]);
        }
        string ns;
        return dfs(bottom, ns, 0);
    }
};

int main() {
    Solution sol;
    string bottom;
    vector<string> allowed;

    // Output: true
    bottom = "BCD", allowed = {"BCG", "CDE", "GEA", "FFF"};
    cout << boolalpha << sol.pyramidTransition(bottom, allowed) << endl;

    // Output: false
    bottom = "AABA", allowed = {"AAA", "AAB", "ABA", "ABB", "BAC"};
    cout << boolalpha << sol.pyramidTransition(bottom, allowed) << endl;

    // Output: true
    bottom = "ACBACFG";
    allowed = {"BGD","AGG","AGC","AGB","CCE","EGB","CCG","EGE","EGD","DCF","FGE","FGB","BFD","DBD",
               "DBF","FFE","FFB","FDA","FDC","GBE","FDE","BEA","EGC","AEC","CCD","EEE","EED","DEB",
               "DEE","DEF","EEB","CEE","BDC","GEC","GEB","GCA","GCB","BDA","GCG","AFF","DDB","EFB",
               "DDG","DDF","DDE","CBF","ACB","ACG","ACF","BCD","BCC","DGB","EFD","CGD","CGG","FCB",
               "GGF","FCD","FCF","FEB","BBF","BBE","CDE","ADA","DFE","DFG","DFB","CDD","EDC","CDF",
               "EDD","FBC","FBF","AAD","AAF","AAB","BAG","BAD","CAG","CAF","DAB","DAC","EEC","GAE",
               "FAG","ABA","EBC","CFG","GFD"};
    cout << boolalpha << sol.pyramidTransition(bottom, allowed) << endl;

    return 0;
}
