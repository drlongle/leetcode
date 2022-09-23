/*
1612. Check If Two Expression Trees are Equivalent
Medium

A binary expression tree is a kind of binary tree used to represent arithmetic
expressions. Each node of a binary expression tree has either zero or two
children. Leaf nodes (nodes with 0 children) correspond to operands (variables),
and internal nodes (nodes with two children) correspond to the operators. In
this problem, we only consider the '+' operator (i.e. addition).

You are given the roots of two binary expression trees, root1 and root2. Return
true if the two binary expression trees are equivalent. Otherwise, return false.

Two binary expression trees are equivalent if they evaluate to the same value
regardless of what the variables are set to.

Example 1:
Input: root1 = [x], root2 = [x]
Output: true

Example 2:
Input: root1 = [+,a,+,null,null,b,c], root2 = [+,+,a,b,c]
Output: true
Explaination: a + (b + c) == (b + c) + a

Example 3:
Input: root1 = [+,a,+,null,null,b,c], root2 = [+,+,a,b,d]
Output: false
Explaination: a + (b + c) != (b + d) + a

Constraints:
The number of nodes in both trees are equal, odd and, in the range [1, 4999].
Node.val is '+' or a lower-case English letter.
It's guaranteed that the tree given is a valid binary expression tree.

Follow up: What will you change in your solution if the tree also supports the
'-' operator (i.e. subtraction)?
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

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

struct Node {
    char val;
    Node *left;
    Node *right;
    Node() : val(' '), left(nullptr), right(nullptr) {}
    Node(char x) : val(x), left(nullptr), right(nullptr) {}
    Node(char x, Node *left, Node *right) : val(x), left(left), right(right) {}
};

class Solution {
  public:
    string eval(Node *node) {
        if (node->left)
            return eval(node->left) + eval(node->right);
        else
            return string(1, node->val);
    }
    bool checkEquivalence(Node *root1, Node *root2) {
        auto s1 = eval(root1);
        auto s2 = eval(root2);
        sort(begin(s1), end(s1));
        sort(begin(s2), end(s2));
        return s1 == s2;
    }
};

int main() { return 0; }
