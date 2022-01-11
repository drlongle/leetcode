/*
Use vector of stacks. Add a new stack if needed.
Use pushindex and popindex to keep track of which stack to push and pop respectively.
Note that, if doing push on empty stack, you might need to update popindex
also, if doing pop on full stack, you might need to update pushindex.
*/

class DinnerPlates {
public:
    DinnerPlates(int capacity) : capacity(capacity)
    {
    }
    void push(int val)
    {
        if (pushindex == data.size()) {
            stack<int, vector<int>> newstack;
            data.push_back(newstack);
        }
        if (data[pushindex].empty() && pushindex > popindex)
            popindex = pushindex;
        data[pushindex].push(val);
        while (pushindex < data.size() && data[pushindex].size() == capacity) {
            pushindex++;
        }
    }

    int pop()
    {

        if (popindex == -1)
            return -1;
        if (data[popindex].size() == capacity && popindex < pushindex)
            pushindex = popindex;

        int val = data[popindex].top();
        data[popindex].pop();

        while (popindex >= 0 && data[popindex].empty())
            popindex--;

        return val;
    }

    int popAtStack(int index)
    {

        if (index >= data.size())
            return -1;

        if (data[index].empty())
            return -1;

        if (data[index].size() == capacity && index < pushindex)
            pushindex = index;

        int val = data[index].top();
        data[index].pop();

        while (popindex >= 0 && data[popindex].empty())
            popindex--;

        return val;
    }

private:
    int capacity;
    vector<stack<int, vector<int>>> data;
    int pushindex = 0;
    int popindex = -1;
};
