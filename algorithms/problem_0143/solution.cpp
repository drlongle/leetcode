/*
143. Reorder List  
Total Accepted: 64464 Total Submissions: 282028 Difficulty: Medium

Given a singly linked list L: L0 -> L1 -> ... -> Ln-1 -> Ln,
reorder it to: L0 -> Ln -> L1 -> Ln-1 -> L2 -> Ln-2-> ...
You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}. 
*/

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
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

#define ll long long int
#define ull unsigned long long int

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode* node) {
    while (node) {
        cout << node->val << ", ";
        node = node->next;
    }
    cout << endl;
}

ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;
    
    while (curr) {
        ListNode* temp = curr->next;
        curr->next = prev;
        head = prev = curr;
        curr = temp;
    }
    return head;
}

void appendNode(ListNode*& head, ListNode*& tail, ListNode* node)
{
    if (!head)
        head = tail = node;
    else {
        tail->next = node;
        tail = node;
    }
}

class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL) return;

        ListNode* fast = head;
        ListNode* slow = head, *prev = NULL;
        while (fast && fast->next) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }

        prev->next = NULL;
        ListNode* curr = head;
        ListNode* curr2 = reverseList(slow);
        ListNode* newhead = NULL;
        ListNode* newtail = NULL;
        while (curr && curr2) {
            appendNode(newhead, newtail, curr);
            curr = curr->next;
            appendNode(newhead, newtail, curr2);
            curr2 = curr2->next;
        }
        if (curr2)
            appendNode(newhead, newtail, curr2);
        newtail->next = NULL;
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

int main()
{
    Solution sol;
    ListNode *node = generateList();
    printList(node);
    sol.reorderList(node);
    cout << "Reordered list:" << endl;
    printList(node);

    return 0;
}

