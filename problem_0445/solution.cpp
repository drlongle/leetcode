/*
445. Add Two Numbers II
Medium

You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:
Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void listToStack(ListNode* l, stack<int>& s) {
        while (l) {
            s.emplace(l->val);
            l = l->next;
        }
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        listToStack(l1, s1);
        listToStack(l2, s2);
        int carry = 0;
        string s;
        while (!s1.empty() || !s2.empty() || carry) {
            if (!s1.empty()) {
                carry += s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                carry += s2.top();
                s2.pop();
            }
            s.push_back('0' + carry  % 10);
            carry /= 10;
        }
        ListNode dummy(0);
        ListNode* tail = &dummy;
        reverse(begin(s), end(s));
        for (char ch: s) {
            tail->next = new ListNode(ch - '0');
            tail = tail->next;
        }
        return dummy.next;
    }
};

int main() {
    Solution sol;
    return 0;
}
