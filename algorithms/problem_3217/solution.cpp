/*
3217. Delete Nodes From Linked List Present in Array
Medium

You are given an array of integers nums and the head of a linked list. Return the head of the modified linked list after removing all nodes from the linked list that have a value that exists in nums.


Example 1:
Input: nums = [1,2,3], head = [1,2,3,4,5]
Output: [4,5]
Explanation:
Remove the nodes with values 1, 2, and 3.

Example 2:
Input: nums = [1], head = [1,2,1,2,1,2]
Output: [2,2,2]
Explanation:
Remove the nodes with value 1.

Example 3:
Input: nums = [5], head = [1,2,3,4]
Output: [1,2,3,4]
Explanation:
No node has value 5.


Constraints:
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^5
All elements in nums are unique.
The number of nodes in the given list is in the range [1, 10^5].
1 <= Node.val <= 10^5
The input is generated such that there is at least one node in the linked list that has a value not present in nums.
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

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode dummy{0, head};
        unordered_set<int> lookup(nums.begin(), nums.end());
        for (ListNode* curr =& dummy; curr->next; ) {
            if (lookup.count(curr->next->val)) {
                curr->next = curr->next->next;
            } else {
                curr = curr->next;
            }

        }
        return dummy.next;
    }
};

int main() {
    return 0;
}
