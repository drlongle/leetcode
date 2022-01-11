/*
155. Min Stack
Total Accepted: 73180 Total Submissions: 326412 Difficulty: Easy

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
    push(x) -- Push element x onto stack.
    pop() -- Removes the element on top of the stack.
    top() -- Get the top element.
    getMin() -- Retrieve the minimum element in the stack.

Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
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

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if (m_mins.empty() || m_mins.top() >= x) 
            m_mins.emplace(x);
        m_numbers.emplace(x);
    }
    
    void pop() {
        int x = m_numbers.top(); 
        if (x == m_mins.top())
            m_mins.pop();
        m_numbers.pop();
    }

    int top() {
        return m_numbers.top();
    }
    
    int getMin() {
        return m_mins.top(); 
    }

    stack<int> m_numbers;
    stack<int> m_mins;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
int main()
{
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin() << endl;//   --> Returns -3.
    minStack.pop();
    cout << minStack.top() << endl;  //      --> Returns 0.
    cout << minStack.getMin() << endl; //   --> Returns -2.

    return 0;
}

