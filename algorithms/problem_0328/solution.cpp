/*
328. Odd Even Linked List

Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example:
Given 1->2->3->4->5->NULL,
return 1->3->5->2->4->NULL.

Note:
The relative order inside both the even and odd groups should remain as it was in the input.
The first node is considered odd, the second node even and so on ... 

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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *odd_head, *odd_tail, *odd_curr;
        ListNode *even_head, *even_tail, *even_curr;

        odd_head = odd_tail = 0;
        even_head = even_tail = 0;
        odd_curr = head;
        even_curr = head->next;

        while (odd_curr && even_curr) {
            append(odd_head, odd_tail, odd_curr);
            append(even_head, even_tail, even_curr);
            odd_curr = even_curr->next;
            even_curr = (odd_curr != 0) ? odd_curr->next : 0;
        }

        if (odd_curr)
            append(odd_head, odd_tail, odd_curr);
        append(odd_head, odd_tail, even_head);
        even_tail->next = 0;
        return odd_head;
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
};

ListNode* generateList() {
    std::srand(std::time(0)); // use current time as seed for random generator
    int listsize = std::rand() % 20;
    vector<int> nums;
    for (int i = 0; i < listsize; ++i)
        nums.push_back(std::rand() % 400);
    sort(nums.begin(), nums.end());
    ListNode *head = NULL, *node, *tail;

    for (const auto& n: nums) {
        node = new ListNode(n);
        if (head == NULL)
            head = node;
        else
            tail->next = node;
        tail = node;
    }

    return head;
}

void printList(ListNode* node) {
    while (node) {
        cout << node->val << ", ";
        node = node->next;
    }
    cout << endl;
}

void deleteList(ListNode* node) {
    ListNode* temp;

    while (node) {
        temp = node->next;
        delete node;
        node = temp;
    }
}

int main()
{
    ListNode *node = generateList();
    printList(node);
    Solution sol;
    node = sol.oddEvenList(node);
    printList(node);
    deleteList(node);

    return 0;
}
