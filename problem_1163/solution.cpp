/*
1163. Last Substring in Lexicographical Order
Hard

Given a string s, return the last substring of s in lexicographical order.

Example 1:
Input: "abab"
Output: "bab"
Explanation: The substrings are ["a", "ab", "aba", "abab", "b", "ba", "bab"].
The lexicographically maximum substring is "bab".

Example 2:
Input: "leetcode"
Output: "tcode"
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

struct Node {
    map<char, Node> edges;
};

class Solution {
public:

    void add_substring(string& s, Node* node, int index, int end) {
        for (; index <= end; ++index) {
            char ch = s[index];
            if (!node->edges.empty() && node->edges.rbegin()->first > ch)
                break;
            if (!node->edges.empty() && node->edges.rbegin()->first < ch)
                node->edges.clear();
            node = &(node->edges[ch]);
        }
    }
    
    string lastSubstring(string s) {
        set<char> uniq(begin(s), end(s));
        if (uniq.size() <= 1)
            return s;
        Node root;
        int ssize = s.size();
        auto it = max_element(s.begin(), s.end());
        for (int i = 0; i < ssize; ++i) {
            if (s[i] == *it)
                add_substring(s, &root, i, ssize-1);
        }
        ostringstream oss;
        Node* p = &root;
        while (!p->edges.empty()) {
            auto it = p->edges.rbegin();
            oss << it->first;
            p = &it->second;
        }
        return oss.str();
    }
};

int main() {
    Solution sol;
    string s;

    s = "abab";
    
    s = "leetcode";

    s = "zrziy";

    cout << "Result: " << sol.lastSubstring(s) << endl;
    
    return 0;
}
