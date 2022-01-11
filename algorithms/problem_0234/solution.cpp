/*
234. Palindrome Linked List  
Total Accepted: 47826 Total Submissions: 169023 Difficulty: Easy

Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?

Sketch:

-------------
For list with an even number of elements

1 2 3 4 5 6
fast = 1
slow = 1

fast = 3
slow = 2

fast = 5
slow = 3

fast = NULL
slow = 4
prev = 3

-------------
For list with an odd number of elements

1 2 3 4 5 6 7
fast = 1,
slow = 1

fast = 3
slow = 2

fast = 5
slow = 3

fast = 7
slow = 4
prev = 3
-------------
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

    ListNode* reverseList(ListNode* head) {
        ListNode *curr=head, *prev=NULL, *newhead = NULL;
        while (curr) {
            newhead = curr;
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return newhead;
    }

    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode *fast = head, *slow = head, *prev = NULL;

        while (fast && fast->next) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }

        prev->next = NULL;
        ListNode* head2 = reverseList(slow);
        while (head && head2) {
            if (head->val != head2->val)
                return false;
            head = head->next;
            head2 = head2->next;
        }
        head2 = reverseList(head2);
        prev->next = head2;

        return true;
    }
};

int main()
{
    Solution sol;
    vector<ListNode> nodes{1,2,1};
    nodes = {1};

    for (size_t i = 0; i+1 < nodes.size(); ++i) {
        nodes[i].next = &nodes[i+1];
    }
    cout << "Result: " << sol.isPalindrome(&nodes[0]) << endl;

    return 0;
}

