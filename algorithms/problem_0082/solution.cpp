/*
82. Remove Duplicates from Sorted List II  
Total Accepted: 72185 Total Submissions: 267575 Difficulty: Medium

Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3. 
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

class Solution {
public:
    void appendNode(ListNode*&head, ListNode*& tail, ListNode* node) {
        if (!head)
            head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
    }

    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* newhead = NULL;
        ListNode* newtail = NULL;
        ListNode* fast = head;

        while (fast) {
            if (fast->next == NULL || (fast->next &&
                fast->val != fast->next->val)) {
                appendNode(newhead, newtail, fast);
                fast = fast->next;
            } else {
                int val = fast->val;
                while (fast && fast->val == val) {
                    ListNode* temp = fast;
                    fast = fast->next;
                    delete temp;
                }
            }
        }

        if (newtail)
            newtail->next = 0;

        return newhead;
    }
};

void printList(ListNode* node) {
    while (node) {
        cout << node->val << ", ";
        node = node->next;
    }
    cout << endl;
}

ListNode* generateList() {
    std::srand(std::time(0)); // use current time as seed for random generator
    int listsize = std::rand() % 20;
    vector<int> nums;
    for (int i = 0; i < listsize; ++i)
        nums.push_back(std::rand() % 20);
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
    ListNode* head = generateList();
    printList(head);
    cout << "Result: " << endl;
    printList(sol.deleteDuplicates(head));

    return 0;
}

