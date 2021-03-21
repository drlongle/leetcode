/*
869. Reordered Power of 2
Medium

Starting with a positive integer N, we reorder the digits in any order (including the original order)
such that the leading digit is not zero.

Return true if and only if we can do this in a way such that the resulting number is a power of 2.

Example 1:
Input: 1
Output: true

Example 2:
Input: 10
Output: false

Example 3:
Input: 16
Output: true

Example 4:
Input: 24
Output: false

Example 5:
Input: 46
Output: true

Note:
1 <= N <= 10^9
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
        bool leaf = false;
    };

    Node root;

    void insert(string& s) {
        Node* node = &root;
        for (char c: s) {
            node = &(node->children[c]);
        }
        node->leaf = true;
    }

    bool empty(unordered_map<char, int>& cnt) {
        for (auto& [k, v]: cnt) {
            if (v)
                return false;
        }
        return true;
    }

    bool check(Node* node, unordered_map<char, int>& cnt) {
        if (empty(cnt))
            return node->leaf;
        for (auto& [k, v]: node->children) {
            if (cnt[k] > 0) {
                --cnt[k];
                if (check(&v, cnt))
                    return true;
                ++cnt[k];
            }
        }
        return false;
    }

    bool reorderedPowerOf2(int n) {
        for (int i = 1; i <= 1000000000; i <<= 1) {
            string s = to_string(i);
            insert(s);
        }

        unordered_map<char, int> cnt;
        for (char c: to_string(n)) {
            ++cnt[c];
        }

        return check(&root, cnt);
    }
};

int main() {
    Solution sol;

    for (int n: {1, 10, 16, 24, 46, 61, 100, 128, 821})
        cout << boolalpha << n << " -> " << sol.reorderedPowerOf2(n) << endl;

    return 0;
}
