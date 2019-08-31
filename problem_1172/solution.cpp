/*
1172. Dinner Plate Stacks
Hard

You have an infinite number of stacks arranged in a row and numbered (left to right)
from 0, each of the stacks has the same maximum capacity.

Implement the DinnerPlates class:

DinnerPlates(int capacity) Initializes the object with the maximum capacity of the stacks.
void push(int val) pushes the given positive integer val into the leftmost stack with size less than capacity.
int pop() returns the value at the top of the rightmost non-empty stack and removes it from that stack, and returns -1
if all stacks are empty. int popAtStack(int index) returns the value at the top of the stack with the given index and
removes it from that stack, and returns -1 if the stack with that given index is empty. Example:

Input:
["DinnerPlates","push","push","push","push","push","popAtStack","push","push","popAtStack","popAtStack","pop","pop","pop","pop","pop"]
[[2],[1],[2],[3],[4],[5],[0],[20],[21],[0],[2],[],[],[],[],[]]
Output:
[null,null,null,null,null,null,2,null,null,20,21,5,4,3,1,-1]

Explanation:
DinnerPlates D = DinnerPlates(2);  // Initialize with capacity = 2
D.push(1);
D.push(2);
D.push(3);
D.push(4);
D.push(5);         // The stacks are now:  2  4
                                           1  3  5
                                           ﹈ ﹈ ﹈
D.popAtStack(0);   // Returns 2.  The stacks are now:     4
                                                       1  3  5
                                                       ﹈ ﹈ ﹈
D.push(20);        // The stacks are now: 20  4
                                           1  3  5
                                           ﹈ ﹈ ﹈
D.push(21);        // The stacks are now: 20  4 21
                                           1  3  5
                                           ﹈ ﹈ ﹈
D.popAtStack(0);   // Returns 20.  The stacks are now:     4 21
                                                        1  3  5
                                                        ﹈ ﹈ ﹈
D.popAtStack(2);   // Returns 21.  The stacks are now:     4
                                                        1  3  5
                                                        ﹈ ﹈ ﹈
D.pop()            // Returns 5.  The stacks are now:      4
                                                        1  3
                                                        ﹈ ﹈
D.pop()            // Returns 4.  The stacks are now:   1  3
                                                        ﹈ ﹈
D.pop()            // Returns 3.  The stacks are now:   1
                                                        ﹈
D.pop()            // Returns 1.  There are no stacks.
D.pop()            // Returns -1.  There are still no stacks.
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

class DinnerPlates {
public:
    DinnerPlates(int capacity) : cap(capacity)
    {
    }

    void push(int val)
    {
        int index;
        if (!not_full.empty()) {
            index = *begin(not_full);
            stacks[index].push(val);
            if (stacks[index].size() == cap)
                not_full.erase(index);
        } else {
            stacks.emplace_back(stack<int>());
            stacks.back().emplace(val);
            index = stacks.size() - 1;
            if (stacks.back().size() < cap)
                not_full.emplace(index);
        }
        not_empty.emplace(index);
    }

    int pop()
    {
        if (not_empty.empty())
            return -1;
        int index = *(not_empty.rbegin());

        return popAtStack(index);
    }

    int popAtStack(int index)
    {
        if (index >= static_cast<int>(stacks.size()))
            return -1;
        if (stacks[index].empty())
            return -1;
        int val = stacks[index].top();
        stacks[index].pop();
        if (stacks[index].empty())
            not_empty.erase(index);
        not_full.emplace(index);

        return val;
    }

    size_t cap;
    vector<stack<int>> stacks;
    set<int> not_full;
    set<int> not_empty;
};

void test_1()
{
    DinnerPlates D = DinnerPlates(2);
    int res;
    D.push(1);
    D.push(2);
    D.push(3);
    D.push(4);
    D.push(5);

    res = D.popAtStack(0);
    cout << "Expect: 2: " << res << endl;

    D.push(20);
    D.push(21);

    res = D.popAtStack(0);
    cout << "Expect: 20: " << res << endl;

    res = D.popAtStack(2);
    cout << "Expect: 21: " << res << endl;

    res = D.pop();
    cout << "Expect: 5: " << res << endl;

    res = D.pop();
    cout << "Expect: 4: " << res << endl;

    res = D.pop();
    cout << "Expect: 3: " << res << endl;

    res = D.pop();
    cout << "Expect: 1: " << res << endl;

    res = D.pop();
    cout << "Expect: -1: " << res << endl;
}

void test_2()
{
    DinnerPlates D = DinnerPlates(2);
    int res;
    D.push(1);
    D.push(2);
    D.push(3);
    D.push(4);
    D.push(7);

    res = D.popAtStack(8);
    cout << "Expected: -1: " << res << endl;

    D.push(20);
    D.push(21);

    res = D.popAtStack(0);
    cout << "Expected: 2: " << res << endl;

    res = D.popAtStack(2);
    res = D.pop();
    res = D.pop();
    res = D.pop();
    res = D.pop();
    res = D.pop();
}

void test_3()
{
    DinnerPlates D = DinnerPlates(2);
    D.push(472);
    D.push(106);
    D.push(497);
    D.push(498);
    D.push(73);
    D.push(115);
    D.push(437);
    D.push(461);
    D.popAtStack(3);
    D.popAtStack(3);
    D.popAtStack(1);
    D.popAtStack(3);
    D.popAtStack(0);
    D.popAtStack(2);
    D.popAtStack(2);
    D.popAtStack(1);

    D.push(197);
    D.push(239);
    D.push(129);
    D.push(449);
    D.push(460);
    D.push(240);
    D.push(386);
    D.push(343);
    D.pop();
    D.pop();
    D.pop();
    D.pop();
    D.pop();
    D.pop();
    D.pop();
    D.pop();
    D.pop();
    D.pop();
}

int main()
{
    test_1();
    test_2();
    test_3();

    return 0;
}
