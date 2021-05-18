class SeatManager {
public:
    set<int> s;
    int seat ;
    SeatManager(int n) {
        seat =0;
    }

    int reserve() {
        if(s.empty())
            return ++seat;
        else {
            int val = *s.begin();
            s.erase(val);
            return val;
        }
    }
    void unreserve(int seatNumber) {
        s.insert(seatNumber);
    }
};
