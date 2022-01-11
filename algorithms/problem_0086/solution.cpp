/*
86. Partition List  
Total Accepted: 65652 Total Submissions: 221819 Difficulty: Medium

Given a linked list and a value x, partition it such that all nodes less than x
come before nodes greater than or equal to x.
You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5. 
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
    ListNode* partition(ListNode* head, int x) {
        ListNode *head1 = NULL;
        ListNode *tail1 = NULL;
        ListNode *head2 = NULL;
        ListNode *tail2 = NULL;

        ListNode* curr = head;
        
        while (curr) {
            if (curr->val < x)
                appendNode(head1, tail1, curr);
            else
                appendNode(head2, tail2, curr);
            curr = curr->next;
        }

        if (tail1) tail1->next = NULL;
        if (tail2) tail2->next = NULL;
        if (head1) {
            tail1->next = head2;
            return head1;
        }
        else
            return head2;
    }
};

ListNode* generateList() {
    std::srand(std::time(0)); // use current time as seed for random generator
    int listsize = std::rand() % 20 + 1;
    vector<int> nums;
    for (int i = 0; i < listsize; ++i)
        nums.push_back(std::rand() % 400);
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
    node = sol.partition(node, 200);
    cout << "Partitioned list:" << endl;
    printList(node);

    return 0;
}

