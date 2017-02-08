/*
61. Rotate List

Given a list, rotate the list to the right by k places, where k is non-negative.
For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!k || !head || !head->next) return head;
        ListNode* tail = head;
        int size = 1;
        while(tail->next)
        {
            tail = tail->next;
            ++size;
        }
        if (k % size == 0) return head;
        int skip = size - (k%size);
        if (!skip) return head;
        ListNode* newhead = head, *newtail;
        while(skip > 0) {
            newtail = newhead;
            newhead = newhead->next;
           --skip;
        }
        newtail->next = 0;
        tail->next = head;

        return newhead;
    }

    void append(ListNode*& head, ListNode*& tail, ListNode* elem) {
        if (head) {
            tail->next = elem;
            tail = elem;
        } else
            head = tail = elem;
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

    for(const auto& n: nums) {
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
    node = sol.rotateRight(node, 1);
    printList(node);
    deleteList(node);

    return 0;
}
