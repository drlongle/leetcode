/*
147. Insertion Sort List

Sort a linked list using insertion sort.
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

class Solution {
public:
    ListNode* insertionSortList(ListNode* list) {
        ListNode* head = NULL, *tail = NULL, *next;

        while(list) {
            next = list->next;
            if (!tail) {
                head = tail = list;
                list->next = 0;
            } else {
                if (list->val < head->val) {
                    list->next = head;
                    head = list;
                } else {
                    ListNode* curr = head, *prev;
                    while (curr != NULL && curr->val <= list->val) {
                        prev = curr;
                        curr = curr->next;
                    }
                    prev->next = list;
                    list->next = curr;
                }
            }
            list = next;
        }

        return head;
    }
};

int main()
{
    return 0;
}
