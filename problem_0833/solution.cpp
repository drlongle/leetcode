/*
833. Find And Replace in String
Medium

To some string S, we will perform some replacement operations that replace groups of letters with new ones (not necessarily the same size).

Each replacement operation has 3 parameters: a starting index i, a source word x and a target word y.  The rule is that if x starts at position i in the original string S, then we will replace that occurrence of x with y.  If not, we do nothing.

For example, if we have S = "abcd" and we have some replacement operation i = 2, x = "cd", y = "ffff", then because "cd" starts at position 2 in the original string S, we will replace it with "ffff".

Using another example on S = "abcd", if we have both the replacement operation i = 0, x = "ab", y = "eee", as well as another replacement operation i = 2, x = "ec", y = "ffff", this second operation does nothing because in the original string S[2] = 'c', which doesn't match x[0] = 'e'.

All these operations occur simultaneously.  It's guaranteed that there won't be any overlap in replacement: for example, S = "abc", indexes = [0, 1], sources = ["ab","bc"] is not a valid test case.

Example 1:
Input: S = "abcd", indexes = [0,2], sources = ["a","cd"], targets = ["eee","ffff"]
Output: "eeebffff"
Explanation: "a" starts at index 0 in S, so it's replaced by "eee".
"cd" starts at index 2 in S, so it's replaced by "ffff".

Example 2:
Input: S = "abcd", indexes = [0,2], sources = ["ab","ec"], targets = ["eee","ffff"]
Output: "eeecd"
Explanation: "ab" starts at index 0 in S, so it's replaced by "eee". 
"ec" doesn't starts at index 2 in the original S, so we do nothing.

Notes:
0 <= indexes.length = sources.length = targets.length <= 100
0 < indexes[i] < S.length <= 1000
All characters in given inputs are lowercase letters.
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
    struct Entry {
        Entry(int i, string s, string t): index(i), source(s), target(t) {}
        int index;
        string source, target;

        bool operator<(const Entry& other) const {
            return index < other.index;
        }
    };
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {

        int sz = S.size(), index = 0, si = 0, vz = indexes.size();
        vector<Entry> entries;
        for (int i = 0; i < vz; ++i) {
            entries.emplace_back(indexes[i], sources[i], targets[i]);
        }
        sort(begin(entries), end(entries));

        ostringstream oss;
        while (index < vz && si < sz) {
            int ssz = entries[index].source.size();
            int ix = entries[index].index;
            if (ix + ssz <= sz && S.compare(ix, ssz, entries[index].source) == 0) {
                oss << S.substr(si, ix - si);
                oss << entries[index].target;
            } else
                oss << S.substr(si, ix - si + ssz);
            si = ix + ssz;
            ++index;
        }
        if(si < sz)
            oss << S.substr(si);

        return oss.str();
    }
};

int main() {
    Solution sol;
    string S;
    vector<int> indexes;
    vector<string> sources, targets;

    // Output: "eeebffff"
    S = "abcd", indexes = {0,2}, sources = {"a","cd"}, targets = {"eee","ffff"};
    cout << sol.findReplaceString(S, indexes, sources, targets) << endl;
    
    // Output: "eeecd"
    S = "abcd", indexes = {0,2}, sources = {"ab","ec"}, targets = {"eee","ffff"};
    cout << sol.findReplaceString(S, indexes, sources, targets) << endl;

    // Output: "vbfrssozp"
    S = "vmokgggqzp", indexes = {3,5,1}, sources = {"kg","ggq","mo"}, targets = {"s","so","bfr"};
    cout << sol.findReplaceString(S, indexes, sources, targets) << endl;
    
    return 0;
}
