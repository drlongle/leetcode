class LogSystem {
    map<string, vector<int>> logs;

    map <string, int> gran = {{"Year", 5},
                              {"Month", 8},
                              {"Day", 11},
                              {"Hour", 14},
                              {"Minute", 17},
                              {"Second", 19}};

    unordered_map <string, pair<string, string>> pad = {
            {"Year", {"01:01:00:00:00", "12:31:23:59:59"}},
            {"Month", {"01:00:00:00", "31:23:59:59"}},
            {"Day", {"00:00:00", "23:59:59"}},
            {"Hour", {"00:00", "59:59"}},
            {"Minute", {"00", "59"}},
            {"Second", {"", ""}}
    };

public:
    LogSystem() {
    }

    void put(int id, string timestamp) {
        logs[timestamp].push_back(id);
    }

    vector<int> retrieve(string start, string end, string granularity) {

        int len = gran[granularity];

        auto s = start.substr(0, len) + pad[granularity].first;
        auto e = end.substr(0, len) + pad[granularity].second;

        vector<int> res;

        auto lo = logs.lower_bound(s);
        auto up = logs.upper_bound(e);

        while(lo!=up) {
            res.insert(res.end(), lo->second.begin(), lo->second.end());
            lo++;
        }

        return res;
    }
};
