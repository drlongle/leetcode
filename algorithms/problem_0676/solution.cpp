/*
676. Implement Magic Dictionary
Medium

Design a data structure that is initialized with a list of different words.
Provided a string, you should determine if you can change exactly one character
in this string to match any word in the data structure.

Implement the MagicDictionary class:

MagicDictionary() Initializes the object.
void buildDict(String[] dictionary) Sets the data structure with an array of
distinct strings dictionary. bool search(String searchWord) Returns true if you
can change exactly one character in searchWord to match any string in the data
structure, otherwise returns false.

Example 1:
Input
["MagicDictionary", "buildDict", "search", "search", "search", "search"]
[[], [["hello", "leetcode"]], ["hello"], ["hhllo"], ["hell"], ["leetcoded"]]
Output
[null, null, false, true, false, false]

Explanation
MagicDictionary magicDictionary = new MagicDictionary();
magicDictionary.buildDict(["hello", "leetcode"]);
magicDictionary.search("hello"); // return False
magicDictionary.search("hhllo"); // We can change the second 'h' to 'e' to match
"hello" so we return True magicDictionary.search("hell"); // return False
magicDictionary.search("leetcoded"); // return False

Constraints:
1 <= dictionary.length <= 100
1 <= dictionary[i].length <= 100
dictionary[i] consists of only lower-case English letters.
All the strings in dictionary are distinct.
1 <= searchWord.length <= 100
searchWord consists of only lower-case English letters.
buildDict will be called only once before search.
At most 100 calls will be made to search.
*/

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
#include <ranges>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "common/FenwickTree.h"
#include "common/ListNode.h"
#include "common/Node.h"
#include "common/SegmentTree.h"
#include "common/TreeNode.h"
#include "common/UnionFind.h"
#include "common/bits.h"

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

class MagicDictionary {
  public:
    void buildDict(vector<string> dictionary) { dict = dictionary; }

    bool match(string &s1, string &s2) {
        if (s1.size() != s2.size())
            return false;
        int cnt = 0;
        for (size_t i = 0, sz = s1.size(); i < sz && cnt <= 1; ++i) {
            cnt += (s1[i] != s2[i]);
        }

        return cnt == 1;
    }

    bool search(string searchWord) {
        for (auto &w : dict) {
            if (match(searchWord, w))
                return true;
        }
        return false;
    }

    vector<string> dict;
};

int main() { return 0; }
