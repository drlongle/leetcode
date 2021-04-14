/*
1265. Print Immutable Linked List in Reverse
Medium

You are given an immutable linked list, print out all values of each node in reverse with the help
of the following interface:

ImmutableListNode: An interface of immutable linked list, you are given the head of the list.
You need to use the following functions to access the linked list (you can't access the
ImmutableListNode directly):

ImmutableListNode.printValue(): Print value of the current node.
ImmutableListNode.getNext(): Return the next node.

The input is only given to initialize the linked list internally. You must solve this problem without
modifying the linked list. In other words, you must operate the linked list using only the mentioned APIs.

Example 1:
Input: head = [1,2,3,4]
Output: [4,3,2,1]

Example 2:
Input: head = [0,-4,-1,3,-5]
Output: [-5,3,-1,-4,0]

Example 3:
Input: head = [-2,0,6,4,4,-6]
Output: [-6,4,4,6,0,-2]

Constraints:
The length of the linked list is between [1, 1000].
The value of each node in the linked list is between [-1000, 1000].

Follow up:
Could you solve this problem in:
Constant space complexity?
Linear time complexity and less than linear space complexity?
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <future>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

class ImmutableListNode {
public:
    void printValue(); // print the value of the node.
    ImmutableListNode* getNext(); // return the next node.
};

class Solution {
public:
    void printLinkedListInReverse(ImmutableListNode* head) {
        if (!head)
            return;
        printLinkedListInReverse(head->getNext());
        head->printValue();
    }
};

int main() {
    Solution sol;

    return 0;
}
