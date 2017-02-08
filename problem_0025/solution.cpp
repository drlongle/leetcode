/*
25. Reverse Nodes in k-Group

Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5 

Input: [1,2]
K = 2
Expected: [2,1] 
*/

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#include <string.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* generateList()
{
    std::srand(std::time(0)); // use current time as seed for random generator
    int listsize = std::rand() % 3;
    vector<int> nums;
    for (int i = 0; i < listsize; ++i)
        nums.push_back(std::rand());
    sort(nums.begin(), nums.end());
    ListNode *head = NULL, *node, *tail;

    for (const auto& n: nums)
    {
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
}

void deleteList(ListNode* node) {
    ListNode* temp;

    while (node) {
        temp = node->next;
        delete node;
        node = temp;
    }
}

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        ListNode *node = head, *prev = NULL, *temp, *first, *last;
        int index;

        head = NULL;
        while (node) {
            first = node;
            last = node;
            index = 0;
            bool full = true;
            for(index = 0; last && index < k-1; ++index) {
                if (last) last = last->next;
                if (!last) full = false;
            }
            if (last)
                node = last->next;
            else
                node = NULL;
            if (full)
                temp = reverse(first, last);
            else
                temp = first;

            if (head == NULL)
                head = temp;
            else
                prev->next = temp;
            prev = first;
        }

        return head;
    }

    ListNode* reverse(ListNode* head, ListNode* tail)
    {
        ListNode *node = head, *prev = NULL, *next;
        if (tail) tail->next = NULL;
        while (node)
        {
            next = node->next;
            node->next = prev;
            prev = node;
            head = node;
            node = next;
        }
        return head;
    }
};

int main()
{
    Solution sol;
    ListNode* list = generateList();
    int K;

    cout << "Input K: ";
    cin >> K;
 
    ListNode* ret = sol.reverseKGroup(list, K);
    printList(ret);
    deleteList(ret);

    return 0;
}

