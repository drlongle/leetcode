/*
2807. Insert Greatest Common Divisors in Linked List
Medium

Given the head of a linked list head, in which each node contains an integer
value.

Between every pair of adjacent nodes, insert a new node with a value equal to
the greatest common divisor of them.

Return the linked list after insertion.

The greatest common divisor of two numbers is the largest positive integer that
evenly divides both numbers.

Example 1:
Input: head = [18,6,10,3]
Output: [18,6,6,2,10,1,3]
Explanation: The 1st diagram denotes the initial linked list and the 2nd diagram
denotes the linked list after inserting the new nodes (nodes in blue are the
inserted nodes).
- We insert the greatest common divisor of 18 and 6 = 6 between the 1st and the
2nd nodes.
- We insert the greatest common divisor of 6 and 10 = 2 between the 2nd and the
3rd nodes.
- We insert the greatest common divisor of 10 and 3 = 1 between the 3rd and the
4th nodes. There are no more adjacent nodes, so we return the linked list.

Example 2:
Input: head = [7]
Output: [7]
Explanation: The 1st diagram denotes the initial linked list and the 2nd diagram
denotes the linked list after inserting the new nodes. There are no pairs of
adjacent nodes, so we return the initial linked list.

Constraints:
The number of nodes in the list is in the range [1, 5000].
1 <= Node.val <= 1000
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

#include "../common/FenwickTree.h"
#include "../common/ListNode.h"
#include "../common/Node.h"
#include "../common/SegmentTree.h"
#include "../common/TreeNode.h"
#include "../common/UnionFind.h"
#include "../common/bits.h"

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

int gcd(int a, int b) {
    if (a > b)
        return gcd(b, a);
    if (a == 0)
        return b;
    return gcd(a, b % a);
}

class Solution {
  public:
    ListNode *insertGreatestCommonDivisors(ListNode *head) {
        if (!head)
            return nullptr;
        auto res = head;
        auto next = head->next;
        while (head && next) {
            int val = gcd(head->val, next->val);
            auto node = new ListNode(val, next);
            head->next = node;
            head = next;
            next = next->next;
        }

        return res;
    }
};

int main() { return 0; }
