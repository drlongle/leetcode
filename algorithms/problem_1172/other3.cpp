/*
Algorithm
Use vector of vectors to model stacks. Allocate dynamically new vectors as needed.
Use priority queue to get the leftmost stack which has the capacity for push.
Use one integer, rightside, to track the rightmost non-empty stack.

The functions pop and popAtIndex are essentially the same, the only difference that
pop works on the index specified as a parameter and popAtIndex uses rightside as index.
*/

#include <queue>
#include <vector>

using namespace std;

class DinnerPlates {
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<vector<int>> container = vector<vector<int>>(1);
    int rightside{-1}; // used for pop
    int cap;           // capacity

    int popAtIndex(int index)
    {
        int val = container[index].back();
        bool push_to_pq = container[index].size() == cap;
        container[index].pop_back();
        if (push_to_pq)
            pq.push(index);
        if (index == rightside)
            while (rightside >= 0 && container[rightside].empty())
                --rightside;
        return val;
    }

public:
    DinnerPlates(int capacity) : cap(capacity)
    {
        pq.push(0);
    }

    void push(int val)
    {
        int top = pq.top();
        container[top].push_back(val);
        rightside = max(rightside, top);
        if (container[top].size() == cap) {
            pq.pop();
            if (top == container.size() - 1) {
                container.emplace_back();
                pq.push(top + 1);
            }
        }
    }

    int pop()
    {
        return rightside >= 0 ? popAtIndex(rightside) : -1;
    }

    int popAtStack(int index)
    {
        return index <= rightside && !container[index].empty() ? popAtIndex(index) : -1;
    }
};

int main()
{
}
