/*
21. Merge Two Sorted Lists

Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
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

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode* head = NULL, *tail = NULL;

        while(list1 && list2) {
            if (list1->val < list2->val)
                append_and_advance(head, tail, list1);
            else
                append_and_advance(head, tail, list2);
        }

        if (list1) append(head, tail, list1);
        if (list2) append(head, tail, list2);

        return head;
    }

    void append(ListNode*& head, ListNode*& tail, ListNode* elem)
    {
        if (head) {
            tail->next = elem;
            tail = elem;
        } else {
            head = tail = elem;
        }
    }

    void append_and_advance(ListNode*& head, ListNode*& tail, ListNode*& elem)
    {
        append(head, tail, elem);
        elem = elem->next;
    }
};

int main()
{
    return 0;
}

