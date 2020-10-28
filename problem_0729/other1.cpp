class MyCalendar {
public:
    struct interval {
        interval(int f, int s):mF(f),mS(s) {}
        int mF;
        int mS;

        bool operator<(const interval& obj) const
        {
            return this->mF < obj.mF;
        }
    };

    set<interval> bookings;
    MyCalendar() {
    }

    bool book(int start, int end) {
        auto itr = bookings.lower_bound({start,end});
        if (itr != bookings.end() && end > itr->mF)
            return false;
        if (itr != bookings.begin() && (--itr)->mS > start)
            return false;
        bookings.emplace_hint(itr, start, end);
        return true;
    }
