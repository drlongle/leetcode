class MyCalendarTwo {
public:

    vector<pair<int,int>> booking, double_booking;

    MyCalendarTwo() {
        booking.clear();
        double_booking.clear();
    }

    bool book(int start, int end) {
        for(auto &x : double_booking){
            if(start < x.second and end > x.first){
                return false;
            }
        }

        for (auto &x : booking){
            if(x.second > start and end > x.first){
                int left = max(start , x.first);
                int right= min(end , x.second);
                double_booking.push_back({left , right});
            }
        }
        booking.push_back({start , end});
        return true;
    }
};

