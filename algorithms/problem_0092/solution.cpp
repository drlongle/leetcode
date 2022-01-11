/*
92. Reverse Linked List II  
Total Accepted: 71446 Total Submissions: 255204 Difficulty: Medium

Reverse a linked list from position m to n. Do it in-place and in one-pass.
For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,
return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 <= m <= n <= length of list. 
*/

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <functional>
#include <iomanip>
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
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ll long long
#define ull unsigned long long

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

int getListSize(ListNode* node) {
    int result = 0;
    while (node) {
        result++;
        node = node->next;
    }
    return result;
} 

ListNode* generateList(int listsize) {
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

ListNode* reverseList(ListNode* head) {
    ListNode* prev = 0;
    ListNode* newhead = 0;
    while (head) {
        ListNode* temp = head->next;
        newhead = head;
        head->next = prev;
        prev = head;
        head = temp;
    }

    return newhead;
}

ListNode* findTail(ListNode* head) {
    ListNode* tail = 0;
    while (head) {
        tail = head;
        head = head->next;
    }
    return tail;
}

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* curr = head;
        ListNode* head_1 = 0;
        ListNode* tail_1 = NULL;
        int i = 1;
        while (i < m) {
            tail_1 = curr;
            curr = curr->next;
            ++i;
        }

        if (tail_1) {
            head_1 = head;
            tail_1->next = 0;
        }

        ListNode* head_2 = curr;
        ListNode* tail_2 = curr;
        while (i <= n) {
            tail_2 = curr;
            curr = curr->next;
            ++i;
        }
        ListNode* head_3 = tail_2->next;
        tail_2->next = 0;
        head_2 = reverseList(head_2);
        tail_2 = findTail(head_2);
        tail_2->next = head_3;
        if (head_1) {
            tail_1->next = head_2;
            return head_1;
        }
        else
            return head_2;
    }
};

int main()
{
    Solution sol;
    ListNode* head; 
    int m, n;

    std::srand(std::time(0)); // use current time as seed for random generator
    n = std::rand() % 20;
    head = generateList(n);

    n = rand() % n;
    if (!n) ++n;
    m = rand() % n;
    if (!m) ++m;

    printList(head);
    head = sol.reverseBetween(head, m,n);
    cout << "Result :" << endl;
    printList(head);

    return 0;
}

