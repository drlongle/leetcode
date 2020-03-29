class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> m;
    unordered_map<string, pair<int, int>> stats;
    void checkIn(int id, string stationName, int t) {
        m[id] = {stationName, t};
    }
    void checkOut(int id, string stationName, int t) {
        auto &stat = stats[m[id].first + "_" + stationName];
        stat.first += (t - m[id].second);
        ++stat.second;
    }
    double getAverageTime(string startStation, string endStation) {
        auto &stat = stats[startStation + "_" + endStation];
        return (double)stat.first / stat.second;
    }
};
