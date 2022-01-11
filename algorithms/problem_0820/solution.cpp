/*
820. Short Encoding of Words
Medium

A valid encoding of an array of words is any reference string s and array of indices indices such that:

words.length == indices.length
The reference string s ends with the '#' character.
For each index indices[i], the substring of s starting from indices[i] and up to (but not including)
the next '#' character is equal to words[i].

Given an array of words, return the length of the shortest reference string s possible of
any valid encoding of words.

Example 1:
Input: words = ["time", "me", "bell"]
Output: 10
Explanation: A valid encoding would be s = "time#bell#" and indices = [0, 2, 5].
words[0] = "time", the substring of s starting from indices[0] = 0 to the next '#' is underlined in "time#bell#"
words[1] = "me", the substring of s starting from indices[1] = 2 to the next '#' is underlined in "time#bell#"
words[2] = "bell", the substring of s starting from indices[2] = 5 to the next '#' is underlined in "time#bell#"

Example 2:
Input: words = ["t"]
Output: 2
Explanation: A valid encoding would be s = "t#" and indices = [0].

Constraints:
1 <= words.length <= 2000
1 <= words[i].length <= 7
words[i] consists of only lowercase letters.
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
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

class Solution {
public:
    struct Node {
        map<char, Node> children;
    };

    Node root;

    int get_score(Node* node, int cnt) {
        if (node->children.empty())
            return cnt;
        int res = 0;
        for (auto& [c, child]: node->children) {
            res += get_score(&child, cnt+1);
        }
        return res;
    }

    int minimumLengthEncoding(vector<string>& words) {
        for (string& word: words) {
            reverse(begin(word), end(word));
            Node* node = &root;
            for (char c: word) {
                node = &node->children[c];
            }
        }

        int res = 0;
        for (auto& [c, child]: root.children) {
            res += get_score(&child, 2);
        }
        return res;
    }
};

int main() {

    vector<string> words;

    // Output: 10
    {
        Solution sol;
        words = {"time", "me", "bell"};
        cout << sol.minimumLengthEncoding(words) << endl;
    }

    // Output: 2
    {
        Solution sol;
        words = {"t"};
        cout << sol.minimumLengthEncoding(words) << endl;
    }

    // Output: 12
    {
        Solution sol;
        words = {"time", "atime", "btime"};
        cout << sol.minimumLengthEncoding(words) << endl;
    }

    // Output: 13
    {
        Solution sol;
        words = {"atime", "aatime", "btime"};
        cout << sol.minimumLengthEncoding(words) << endl;
    }
    return 0;
}
