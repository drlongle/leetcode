class MyCalendarTwo {
public:
    MyCalendarTwo() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

    bool book(int start, int end) {
        ++m_[start]; --m_[end]; // starting point => +1 ending point => -1
        int concurrency = 0;
        for (auto const& p : m_) {
            concurrency += p.second;
            if (concurrency > 2) {
                // current modification is not feasible, so, undo it and return false
                --m_[start]; ++m_[end]; return false;
            }
        }
        return true;
    }
private:
    map<int, int> m_;
};
