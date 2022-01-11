/*
83. Remove Duplicates from Sorted List
Total Accepted: 122173 Total Submissions: 328670 Difficulty: Easy

Given a sorted linked list, delete all duplicates such that each element appear only once.
For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/

#include <algorithm>
#include <array>
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
#include <unordered_set>
#include <unordered_map>
#include <vector>

#define ll long long int
#define ull unsigned long long int

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head)
            return head;
        ListNode* curr = head;
        while (curr && curr->next)
        {
            if (curr->next->val == curr->val)
            {
                ListNode* temp = curr->next->next;
                delete curr->next;
                curr->next = temp;
            }
            else
                curr = curr->next;
        }

        return head;
    }
};

int main()
{
    Solution sol;

    return 0;
}

