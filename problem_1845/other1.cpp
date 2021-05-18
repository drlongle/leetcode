class SeatManager {
public:
    priority_queue<int,vector<int>, greater<int>>pq;
    int i = 1;
    SeatManager(int n) {
        // no initialization requred
    }

    int reserve() {
        if(pq.empty()) return i++;
        int top=pq.top();
        pq.pop();
        return top;
    }

    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};
