class SeatManager {
    priority_queue<int, vector<int>, greater<int>> pq;
public:
    SeatManager(int n) {
        for (int i = 1; i <= n; ++i) {
            pq.push(i);
        }
    }

    int reserve() {
        int ret = pq.top();
        pq.pop();
        return ret;
    }

    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};
