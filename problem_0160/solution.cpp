/*
160. Intersection of Two Linked Lists  
Total Accepted: 73779 Total Submissions: 243510 Difficulty: Easy

Write a program to find the node at which the intersection of two
singly linked lists begins.
Notes:

    If the two linked lists have no intersection at all, return null.
    The linked lists must retain their original structure after the function returns.
    You may assume there are no cycles anywhere in the entire linked structure.
    Your code should preferably run in O(n) time and use only O(1) memory.
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

void printList(ListNode* node) {
    while (node) {
        cout << node->val << ", ";
        node = node->next;
    }
    cout << endl;
}

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (!headA || !headB) return 0;
        int lenA = getListSize(headA); 
        int lenB = getListSize(headB);
        if (lenA > lenB)
            swap(headA, headB);
        int diff = abs(lenA-lenB);
        while (diff > 0) {
            headB = headB->next;
            --diff;
        }

        while (headA && headB && headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }

        return headA == headB ? headA : NULL;
    }
};

int main()
{
    Solution sol;
    ListNode* headA, *headB, *result; 

    headA = generateList(10);
    headB = 0;

    headA = generateList(10);
    headB = headA->next;

    cout << "List A: " << endl;
    printList(headA);
    cout << "List B: " << endl;
    printList(headB);
    result = sol.getIntersectionNode(headA, headB);
    cout << "Result: " << endl;
    printList(result);

    return 0;
}

