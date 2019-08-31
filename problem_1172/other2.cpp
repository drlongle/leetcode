/*
Use a map m to keep the mapping between index and stack
Use a set available to keep indices of all no full stacks.
*/

class DinnerPlates {
    int c;
    map<int, vector<int>> m;
    set<int> available;

    DinnerPlates(int capacity)
    {
        c = capacity;
    }

    void push(int val)
    {
        if (available.empty())
            available.insert(m.size());
        m[*available.begin()].push_back(val);
        if (m[*available.begin()].size() == c)
            available.erase(available.begin());
    }

    int pop()
    {
        if (m.empty())
            return -1;
        return popAtStack(m.rbegin()->first);
    }

    int popAtStack(int index)
    {
        if (!m.count(index) || m[index].empty())
            return -1;
        int val = m[index].back();
        m[index].pop_back();
        available.insert(index);
        if (m[index].empty())
            m.erase(index);
        return val;
    }
};
