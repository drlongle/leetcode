class MyCalendar {
public:
    vector<pair<int,int>> bookings;
    MyCalendar() {
        bookings.clear();
    }

    bool book(int start, int end) {
        bool overlap = false;
        for(auto &x : bookings){
            if(start >= x.second or end <= x.first) continue;
            else if(start < x.second and end > x.first){
                overlap = true;
                break;
            }
        }
        if(overlap == true) return false;
        bookings.push_back({start , end});
        return true;
    }
};
