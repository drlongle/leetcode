/*
430. Flatten a Multilevel Doubly Linked List
Medium

You are given a doubly linked list which in addition to the next and previous pointers, it could have a child pointer, which may or may not point to a separate doubly linked list. These child lists may have one or more children of their own, and so on, to produce a multilevel data structure, as shown in the example below.

Flatten the list so that all the nodes appear in a single-level, doubly linked list. You are given the head of the first level of the list.

Example
Input:
 1---2---3---4---5---6--NULL
         |
         7---8---9---10--NULL
             |
             11--12--NULL

Output:
1-2-3-7-8-11-12-9-10-4-5-6-NULL
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <future>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};

class Solution {
public:
    pair<Node*, Node*> flat_helper(Node* head) {
        Node* curr = head;
        Node* tail = nullptr;
        while (curr) {
            if (curr->child) {
                auto [chead, ctail] = flat_helper(curr->child);
                curr->child = nullptr;
                auto next = curr->next;
                curr->next = chead;
                chead->prev = curr;
                ctail->next = next;
                if (next)
                    next->prev = ctail;
                curr = next;
                tail = ctail;
            } else {
                tail = curr;
                curr = curr->next;
            }
        }
        return {head, tail};
    }
    
    Node* flatten(Node* head) {
        auto [phead, ptail] = flat_helper(head);
        return phead;
    }
};

int main() {
    Solution sol;
    return 0;
}
