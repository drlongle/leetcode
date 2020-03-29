class UndergroundSystem {
public:
    void checkIn(int id, string s1, int t1) {
        notes[id] = make_tuple(s1, t1);
    }
    void checkOut(int id, string s2, int t2) {
        auto [s1, t1] = notes[id];
        edges[s1][s2].push_back(t2 - t1); // add edge (s1 -> s2) with time delta abs(t1 -t2) ⏰
    }
    double getAverageTime(string s1, string s2) {
        return accumulate(edges[s1][s2].begin(), edges[s1][s2].end(), 0.0) / edges[s1][s2].size();
    }
private:
    using Note = tuple<string, int>;
    using Notes = unordered_map<int, Note>;
    Notes notes; // { id: { source-station, check-in time }}
    using Edges = unordered_map<string, unordered_map<string, vector<int>>>;
    Edges edges; // { source: { destination, { time delta(s) }}}
};


