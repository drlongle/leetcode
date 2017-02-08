/*
24. Swap Nodes in Pairs

Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed. 
*/

#include <algorithm>
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
    ListNode* swapPairs(ListNode* head)
    {
        if (head == 0) return 0;
        ListNode* newhead = 0, *node = head, *prev = NULL, *next;

        while (node)
        {
            if (node->next == 0)
            {
                if (prev)
                    prev->next = node;
                else
                    newhead = node;
                return newhead;
            }
            else
            {
                next = node->next;
                if (prev)
                    prev->next = next;
                else
                    newhead = next;
                swap(node, next->next);
                prev = next->next;
                if (prev)
                    prev->next = NULL;
            }
        }
        return newhead;
    }
};

ListNode* generateList()
{
    std::srand(std::time(0)); // use current time as seed for random generator
    int listsize = std::rand() % 10;
    vector<int> nums;
    for (int i = 0; i < listsize; ++i)
        nums.push_back(std::rand() % 100);
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

void printList(ListNode* node)
{
    while (node) {
        cout << node->val << ", ";
        node = node->next;
    }
    cout << endl;
}

void deleteList(ListNode* node)
{
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
    node = sol.swapPairs(node);
    printList(node);
    deleteList(node);
    return 0;
}

