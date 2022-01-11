/*
109. Convert Sorted List to Binary Search Tree

Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
*/

#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <climits>
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

#include <string.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
         return sortedListToBST(head, NULL);
    }

    TreeNode* sortedListToBST(ListNode* head, ListNode* tail) {
        if (!head || head == tail) return NULL;
        if (head->next == tail) return new TreeNode(head->val);
        ListNode* fast = head, *slow = head;
        while(fast != tail && fast->next != tail) {
            fast = fast->next->next;
            slow = slow->next;
        }
        TreeNode* node = new TreeNode(slow->val);
        node->left = sortedListToBST(head, slow);
        node->right = sortedListToBST(slow->next, tail);
        return node;
    }
};


int main()
{
    return 0;
}
