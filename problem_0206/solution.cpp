/*
206. Reverse Linked List  
Total Accepted: 108528 Total Submissions: 273282 Difficulty: Easy

Reverse a singly linked list.
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
    ListNode* reverseList(ListNode* head) ;
};

ListNode* Solution::reverseList(ListNode* head) {
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

int main()
{
    Solution sol;

    return 0;
}

