/*
382. Linked List Random Node

Difficulty:Medium
Total Accepted:38.6K
Total Submissions:81.2K

Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.

Follow up:
What if the linked list is extremely large and its length is unknown to you? Could you solve this efficiently without using extra space?

Example:

// Init a singly linked list [1,2,3].
ListNode head = new ListNode(1);
head.next = new ListNode(2);
head.next.next = new ListNode(3);
Solution solution = new Solution(head);

// getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.
solution.getRandom();

*/

#include <algorithm>
#include <array>
#include <bitset>
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
#include <tuple>
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
    Solution(ListNode* head): m_head(head), m_size(get_size(head)) {

    }

    int getRandom() {
        size_t index = rand() % m_size; 
        ListNode* node = m_head;
        while (index > 0) {
            node = node->next;
            --index;
        }
        return node->val;
    }

    size_t get_size(ListNode* head) {
        if (!head) return 0;
        size_t res = 0;
        while (head) {
            head = head->next;
            ++res;
        }
        return res;
    }

    ListNode* m_head;
    size_t m_size;
};

int main(int argc, const char* argv[])
{
    return 0;
}

