class MyCalendar {
public:
    set<pair<int,int>> st;
    MyCalendar() {
        st.clear();
    }

    bool book(int s, int e) {
        auto it = st.insert({s, e});
        auto cur = it.first;
        // duplicate
        if (it.second == false) {
            return false;
        }
        bool ans = true;
        if (cur != st.begin()) {
            auto p = *prev(cur);
            if (s < p.second) {
                ans = false;
            }
        }
        if (cur != prev(st.end())) {
            auto p = *next(cur);
            if (p.first < e) {
                ans = false;
            }
        }
        if (ans == false) {
            st.erase(cur);
        }
        return ans;
    }
};
