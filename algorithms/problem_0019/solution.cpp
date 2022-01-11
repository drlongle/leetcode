/*
19. Remove Nth Node From End of List
Total Accepted: 113058 Total Submissions: 377663 Difficulty: Easy

Given a linked list, remove the nth node from the end of list and return its head.

For example,
   Given linked list: 1->2->3->4->5, and n = 2.
   After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:
Given n will always be valid.
Try to do this in one pass. 
*/

#include <algorithm>
#include <array>
#include <cassert>
#include <cctype>
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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode* fast = head;
        for (int i = 0; i < n && fast; ++i)
            fast = fast->next;
        ListNode* curr = head;
        ListNode* prev = 0;

        while (fast)
        {
            prev = curr;
            curr = curr->next;
            fast = fast->next;
        }

        if (!prev)
            head = head->next;
        else
            prev->next = curr->next;
        delete curr;

        return head; 
    }
};

int main()
{
    Solution sol;

    return 0;
}

