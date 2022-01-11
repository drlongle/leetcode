/*
2. Add Two Numbers

You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return addTwoNumbersWithCarry(l1, l2, 0);
    }

    ListNode* addTwoNumbersWithCarry(ListNode* l1, ListNode* l2, int carry) {
        if (l1 == NULL && l2 == NULL)
            return new ListNode(carry);
        int sum = carry;
        if (l1 != NULL)
            sum += l1->val;
        if (l2 != NULL)
            sum += l2->val;
        carry = sum / 10;
        ListNode* result = new ListNode(sum % 10);
        if (carry == 0 && (l1 == NULL || l1->next == NULL) &&
            (l2 == NULL || l2->next == NULL))
            return result;
        result->next = addTwoNumbersWithCarry(l1 ? l1->next : NULL,
            l2 ? l2->next : NULL, carry);
        return result;
    }
};

int main()
{
    ListNode n(0);
    Solution solution;
    solution.addTwoNumbers(&n, &n);
}

