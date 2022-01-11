/*
203. Remove Linked List Elements  
Total Accepted: 63057 Total Submissions: 219152 Difficulty: Easy

Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5 
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
    ListNode* removeElements(ListNode* head, int val) {
        while (head && head->val == val) {
            ListNode* temp = head->next;
            delete head;
            head = temp;
        }
        if (!head) return 0;
        ListNode* prev = head;
        ListNode* curr = head->next;
        while (curr) {
            if (curr->val == val) {
                ListNode* temp = curr->next;
                delete curr;
                prev->next = curr = temp;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};

int main()
{
    Solution sol;

    return 0;
}

