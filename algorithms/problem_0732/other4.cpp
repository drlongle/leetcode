/*
The basic idea is there is a sorted array contains all intervals with book number. When there is a new
interval arrives, we will break any existing intervals:

New arrival          :|------------------------------------|
Existing intervals   :|-----|     |------------|                |----------------|
It will be broken into:

|-----|-----|------------|----------|
|-----|     |------------|                |----------------|

Then we recalculate the book number

|--2--|--1--|-----2------|---1------|     |------1---------|
*/

class MyCalendarThree {
public:
    struct Node {
        int start;
        int end;
        int count;
    };
    int maxbook;
    vector<Node> m;
    MyCalendarThree() {
        maxbook = 0;
    }

    int book(int start, int end) {
        size_t s = 0, e = m.size();
        while (s < e) {
            size_t k = (s + e) / 2;
            if (m[k].end <= start) s = k + 1;
            else e = k;
        }
        const auto idx1 = s;
        s = 0;
        e = m.size();
        while (s < e) {
            size_t k = (s + e) / 2;
            if (m[k].start < end) s = k + 1;
            else e = k;
        }
        const auto idx2 = s;
        int end2 = end;
        for (size_t p = idx2; p > idx1; p--) {
            if (end2 > m[p - 1].end) {
                m.insert(m.begin() + p, { m[p - 1].end,end2,0 });
                end2 = m[p - 1].end;
            }
            if (end2 < m[p - 1].end) {
                m.insert(m.begin() + p, { end2,m[p-1].end,m[p-1].count });
                m[p - 1].end = end2;
            }
            if (start > m[p - 1].start) {
                m.insert(m.begin() + p, { start,m[p - 1].end,m[p - 1].count });
                m[p - 1].end = start;
            }
            end2 = m[p - 1].start;
        }
        if (start < end2) {
            m.insert(m.begin() + idx1, { start,end2,0 });
        }
        s = 0;
        e = m.size();
        while (s < e) {
            size_t k = (s + e) / 2;
            if (m[k].start < start) s = k + 1;
            else e = k;
        }
        const auto idx3 = s;
        s = 0;
        e = m.size();
        while (s < e) {
            size_t k = (s + e) / 2;
            if (m[k].end <=end) s = k + 1;
            else e = k;
        }
        const auto idx4 = s;
        for (size_t i = idx3; i < idx4; i++) {
            m[i].count++;
            maxbook= max(maxbook, m[i].count);
        }
        return maxbook;
    }
};
