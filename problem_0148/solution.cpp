/*
148. Sort List

Sort a linked list in O(n log n) time using constant space complexity.
*/

#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <iostream>
#include <sstream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#include <string.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if ((!head) || (!head->next)) return head;
        if (head->next->next == NULL) {
            ListNode* next = head->next;
            head->next = NULL;
            return merge_list(head, next);
        }
        ListNode* fast = head, *slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* list2 = sortList(slow->next);
        slow->next = 0;
        ListNode* list1 = sortList(head);
        return merge_list(list1, list2);
    }

    ListNode* merge_list(ListNode* list1, ListNode* list2) {
        ListNode* head = NULL, *tail = NULL;

        while (list1 && list2) {
            if (list1->val < list2->val)
                append_and_advance(head, tail, list1);
            else
                append_and_advance(head, tail, list2);
        }

        if (list1) append(head, tail, list1);
            if (list2) append(head, tail, list2);

        return head;
    }

    void append(ListNode*& head, ListNode*& tail, ListNode* elem) {
        if (head) {
            tail->next = elem;
            tail = elem;
        } else
            head = tail = elem;
    }

    void append_and_advance(ListNode*& head, ListNode*& tail, ListNode*& elem)
    {
        append(head, tail, elem);
        elem = elem->next;
    }
};

void printList(ListNode* node) {
    while (node) {
        cout << node->val << ", ";
        node = node->next;
    }
}

int main()
{
    Solution sol;
    ListNode *list = new ListNode(2);
    list->next = new ListNode(1);
    ListNode* result= sol.sortList(list);
    printList(result);
    return 0;
}
