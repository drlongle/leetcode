class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList): m_list(nestedList.begin(), nestedList.end())
    {
        adjust();
    }

    void adjust() {
        while (m_list.size() && !m_list.front().isInteger()) {
            auto li = m_list.front();
            m_list.pop_front();
            auto children = li.getList();
            for (auto it = children.rbegin(); it != children.rend(); ++it)
                m_list.push_front(*it);
        }
    }

    int next() {
        int res = m_list.front().getInteger();
        m_list.pop_front();
        adjust();
        return res;
    }

    bool hasNext() {
        return m_list.size();
    }

    deque<NestedInteger> m_list;
};