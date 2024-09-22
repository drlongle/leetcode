/*
641. Design Circular Deque
Medium

Design your implementation of the circular double-ended queue (deque).

Implement the MyCircularDeque class:

MyCircularDeque(int k) Initializes the deque with a maximum size of k.
boolean insertFront() Adds an item at the front of Deque. Returns true if the
operation is successful, or false otherwise. boolean insertLast() Adds an item
at the rear of Deque. Returns true if the operation is successful, or false
otherwise. boolean deleteFront() Deletes an item from the front of Deque.
Returns true if the operation is successful, or false otherwise. boolean
deleteLast() Deletes an item from the rear of Deque. Returns true if the
operation is successful, or false otherwise. int getFront() Returns the front
item from the Deque. Returns -1 if the deque is empty. int getRear() Returns the
last item from Deque. Returns -1 if the deque is empty. boolean isEmpty()
Returns true if the deque is empty, or false otherwise. boolean isFull() Returns
true if the deque is full, or false otherwise.

Example 1:
Input:
["MyCircularDeque", "insertLast", "insertLast", "insertFront", "insertFront",
"getRear", "isFull", "deleteLast", "insertFront", "getFront"]
[[3], [1], [2], [3], [4], [], [], [], [4], []]
Output:
[null, true, true, true, false, 2, true, true, true, 4]

Explanation
MyCircularDeque myCircularDeque = new MyCircularDeque(3);
myCircularDeque.insertLast(1);  // return True
myCircularDeque.insertLast(2);  // return True
myCircularDeque.insertFront(3); // return True
myCircularDeque.insertFront(4); // return False, the queue is full.
myCircularDeque.getRear();      // return 2
myCircularDeque.isFull();       // return True
myCircularDeque.deleteLast();   // return True
myCircularDeque.insertFront(4); // return True
myCircularDeque.getFront();     // return 4

Constraints:
1 <= k <= 1000
0 <= value <= 1000
At most 2000 calls will be made to insertFront, insertLast, deleteFront,
deleteLast, getFront, getRear, isEmpty, isFull.
*/

#include <algorithm>
#include <atomic>
#include <bit>
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
#include <ranges>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "../common/FenwickTree.h"
#include "../common/ListNode.h"
#include "../common/Node.h"
#include "../common/SegmentTree.h"
#include "../common/TreeNode.h"
#include "../common/UnionFind.h"
#include "../common/bits.h"

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

class MyCircularDeque {
  public:
    MyCircularDeque(int k) : size(0), capacity(k), head(0), tail(0), nums(k) {}

    void decrement(int &index) {
        --index;
        if (index < 0)
            index += capacity;
    }

    void increment(int &index) {
        ++index;
        if (index == capacity)
            index = 0;
    }

    bool insertFront(int value) {
        if (isFull())
            return false;
        if (!isEmpty())
            decrement(head);
        nums[head] = value;
        ++size;
        return true;
    }

    bool insertLast(int value) {
        if (isFull())
            return false;
        if (!isEmpty())
            increment(tail);
        nums[tail] = value;

        ++size;
        return true;
    }

    bool deleteFront() {
        if (isEmpty())
            return false;
        --size;
        increment(head);
        if (isEmpty())
            tail = head;
        return true;
    }

    bool deleteLast() {
        if (isEmpty())
            return false;
        --size;
        decrement(tail);
        if (isEmpty())
            head = tail;
        return true;
    }

    int getFront() { return isEmpty() ? -1 : nums[head]; }

    int getRear() { return isEmpty() ? -1 : nums[tail]; }

    bool isEmpty() { return size == 0; }

    bool isFull() { return size == capacity; }

  private:
    int size, capacity;
    int head, tail;
    vector<int> nums;
};

int main() { return 0; }
