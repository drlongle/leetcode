/*
725. Split Linked List in Parts
Medium

Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.
The length of each part should be as equal as possible: no two parts should have a size differing by more than one.
This may lead to some parts being null.

The parts should be in the order of occurrence in the input list, and parts occurring earlier should always
have a size greater than or equal to parts occurring later.

Return an array of the k parts.

Example 1:
Input: head = [1,2,3], k = 5
Output: [[1],[2],[3],[],[]]
Explanation:
The first element output[0] has output[0].val = 1, output[0].next = null.
The last element output[4] is null, but its string representation as a ListNode is [].

Example 2:
Input: head = [1,2,3,4,5,6,7,8,9,10], k = 3
Output: [[1,2,3,4],[5,6,7],[8,9,10]]
Explanation:
The input has been split into consecutive parts with size difference at most 1, and earlier parts are
a larger size than the later parts.

Constraints:
The number of nodes in the list is in the range [0, 1000].
0 <= Node.val <= 1000
1 <= k <= 50
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
#include "common/Node.h"
#include "common/TreeNode.h"

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

class Solution {
public:
    int length(ListNode* head) {
        int res = 0;
        while (head) {
            head = head->next;
            ++res;
        }
        return res;
    }

    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> res;
        int len = length(head);
        int sublen = len / k;
        int mod = len - sublen * k;
        while (k-- > 0) {
            int l = sublen;
            if (mod > 0) {
                ++l, --mod;
            }
            ListNode dummy;
            ListNode* cur = &dummy;
            while (l-- > 0) {
                cur->next = head;
                cur = cur->next;
                head = head->next;
            }
            cur->next = nullptr;
            res.push_back(dummy.next);
        }

        return res;
    }
};

int main() {
    Solution sol;

    return 0;
}
