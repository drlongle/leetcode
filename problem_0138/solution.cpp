/*
138. Copy List with Random Pointer  
Total Accepted: 64170 Total Submissions: 246148 Difficulty: Hard

A linked list is given such that each node contains an additional random
pointer which could point to any node in the list or null.

Return a deep copy of the list. 
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

struct Node {
    int val;
    Node *next, *random;
    Node(int x) : val(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    Node *copyRandomList(Node *head) {
        if (!head) return NULL;
        Node* curr = head;

        while (curr) {
            Node* newnode = new Node(curr->val);
            newnode->next = curr->next;
            newnode->random = curr->random;
            curr->next = newnode;
            curr = newnode->next;
        }

        Node* newhead = head->next;
        curr = head;
        while (curr) {
            Node* newcurr = curr->next;
            if (curr->random)
                newcurr->random = curr->random->next;
            curr = newcurr->next;
        }

        curr = head;
        while (curr) {
            Node* newcurr = curr->next;
            Node* nextcurr;
            if (newcurr->next) {
                nextcurr = newcurr->next;
                newcurr->next = nextcurr->next;
            }
            else
                nextcurr = 0;

            curr->next = nextcurr;
            curr = nextcurr;
        }

        return newhead;
    }
};

int main()
{
    Solution sol;

    return 0;
}

