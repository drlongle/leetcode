/*
369. Plus One Linked List
Medium

Given a non-negative integer represented as a linked list of digits, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list.

Example 1:
Input: head = [1,2,3]
Output: [1,2,4]

Example 2:
Input: head = [0]
Output: [1]

Constraints:
The number of nodes in the linked list is in the range [1, 100].
0 <= Node.val <= 9
The number represented by the linked list does not contain leading zeros except for the zero itself.
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
    ListNode* reverse(ListNode* node) {
        ListNode* head = nullptr;
        while (node != nullptr) {
            ListNode* temp = node->next;
            node->next = head;
            head = node;
            node = temp;
        }

        return head;
    }

    ListNode* plusOne(ListNode* head) {
        ListNode* node = reverse(head);
        head = node;
        int carry = 1;
        while (carry) {
            if (++(node->val) >= 10) {
                node->val -= 10;
                if (!node->next)
                    node->next = new ListNode();
                node = node->next;
            } else
                break;
        }

        return reverse(head);
    }
};

int main() {
    return 0;
}
