/*
1171. Remove Zero Sum Consecutive Nodes from Linked List
Medium

Given the head of a linked list, we repeatedly delete consecutive sequences
of nodes that sum to 0 until there are no such sequences. After doing so, return
the head of the final linked list.  You may return any such answer.

(Note that in the examples below, all sequences are serializations of ListNode objects.)
Example 1:
Input: head = [1,2,-3,3,1]
Output: [3,1]
Note: The answer [1,2,1] would also be accepted.

Example 2:
Input: head = [1,2,3,-3,4]
Output: [1,2,4]

Example 3:
Input: head = [1,2,3,-3,-2]
Output: [1]
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

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr)
    {
    }
};

class Solution {
public:
    pair<ListNode*, bool> reduce(ListNode* head)
    {
        int sum = 0;
        ListNode* curr = head;
        bool changed = false;
        while (curr) {
            sum += curr->val;
            if (sum == 0) {
                head = curr->next;
                changed = true;
            }
            curr = curr->next;
        }

        if (head && head->next) {
            auto p = reduce(head->next);
            if (p.second) {
                head->next = p.first;
                p = reduce(head);
                head = p.first;
                changed = true;
            }
        }

        return {head, changed};
    }

    ListNode* removeZeroSumSublists(ListNode* head)
    {
        return reduce(head).first;
    }
};

void print(ListNode* node)
{
    stringstream ss;
    while (node) {
        ss << node->val << " ";
        node = node->next;
    }
    cout << "Result: " << ss.str() << endl;
}

int main()
{
    Solution sol;
    vector<ListNode> nodes;
    vector<int> nums;

    // Output: [3,1]
    nums = {1, 2, -3, 3, 1};

    // Output: [1,2,4]
    // nums = {1,2,3,-3,4};

    // Output: [1]
    nums = {1, 2, 3, -3, -2};

    // Output: [1,5,1] or [1,3,2,1].
    nums = {1, 3, 2, -3, -2, 5, 100, -100, 1};

    for (auto n : nums)
        nodes.emplace_back(n);
    for (size_t i = 0; i + 1 < nodes.size(); ++i)
        nodes[i].next = &nodes[i + 1];
    auto res = sol.removeZeroSumSublists(&nodes[0]);
    print(res);

    return 0;
}
